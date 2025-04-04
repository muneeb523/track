#include <QDebug>

#include <qapplication.h>
#include <qevent.h>
#include <qwhatsthis.h>
#include <qpainter.h>

#include <qwt_plot.h>
#include <qwt_symbol.h>
#include <qwt_scale_map.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_directpainter.h>

#include "level2/canvaspicker.h"

CanvasPicker::CanvasPicker( QwtPlot *plot )
	: QObject(plot), d_selectedCurve( NULL ), d_selectedPoint( -1 )
{
    QwtPlotCanvas *canvas = (QwtPlotCanvas *)plot->canvas();

    canvas->installEventFilter( this );

    // We want the focus, but no focus rect. The
    // selected point will be highlighted instead.
    canvas->setFocusPolicy( Qt::StrongFocus );

#ifndef QT_NO_CURSOR
    canvas->setCursor( Qt::PointingHandCursor );
#endif
    canvas->setFocusIndicator( QwtPlotCanvas::ItemFocusIndicator );
    canvas->setFocus();

    const char *text =
        "All points can be moved using the left mouse button "
        "or with these keys:\n\n"
        "- Up:\t\tSelect next curve\n"
        "- Down:\t\tSelect previous curve\n"
        "- Left, �-�:\tSelect next point\n"
        "- Right, �+�:\tSelect previous point\n"
        "- 7, 8, 9, 4, 6, 1, 2, 3:\tMove selected point";
    canvas->setWhatsThis(text);

    shiftCurveCursor(true);
}



bool CanvasPicker::event( QEvent *e )
{
    if ( e->type() == QEvent::User )
    {
        showCursor(true);
        return ( true );
    }

    return QObject::event( e );
}



bool CanvasPicker::eventFilter( QObject *object, QEvent *e )
{
    if ( object != (QObject *)plot()->canvas() )
    {
        return ( false );
	}

    switch ( e->type() )
    {
        case QEvent::FocusIn:
        {
            showCursor( true );
		}

		case QEvent::FocusOut:
		{
            showCursor( false );
		}

        case QEvent::Paint:
        {   
            QApplication::postEvent( this, new QEvent(QEvent::User) );
            break;
        }

        case QEvent::MouseButtonPress:
        {
            select( ((QMouseEvent *)e)->pos() );
            qDebug() << "MouseButtonPress: " << ( (QMouseEvent *)e )->pos() << endl;
            return ( true ); 
        }

        case QEvent::MouseMove:
        {
            move( ((QMouseEvent *)e)->pos() );
            qDebug() << "MouseMove: " << ( (QMouseEvent *)e )->pos() << endl;
            return ( true ); 
        }
        case QEvent::KeyPress:
        {
            const int delta = 5;
            switch(((const QKeyEvent *)e)->key())
            {
                case Qt::Key_Up:
                    shiftCurveCursor(true);
                    return true;
                    
                case Qt::Key_Down:
                    shiftCurveCursor(false);
                    return true;

                case Qt::Key_Right:
                case Qt::Key_Plus:
                    if ( d_selectedCurve )
                        shiftPointCursor(true);
                    else
                        shiftCurveCursor(true);
                    return true;

                case Qt::Key_Left:
                case Qt::Key_Minus:
                    if ( d_selectedCurve )
                        shiftPointCursor(false);
                    else
                        shiftCurveCursor(true);
                    return true;

                // The following keys represent a direction, they are
                // organized on the keyboard.
 
                case Qt::Key_1: 
                    moveBy(-delta, delta);
                    break;
                case Qt::Key_2:
                    moveBy(0, delta);
                    break;
                case Qt::Key_3: 
                    moveBy(delta, delta);
                    break;
                case Qt::Key_4:
                    moveBy(-delta, 0);
                    break;
                case Qt::Key_6: 
                    moveBy(delta, 0);
                    break;
                case Qt::Key_7:
                    moveBy(-delta, -delta);
                    break;
                case Qt::Key_8:
                    moveBy(0, -delta);
                    break;
                case Qt::Key_9:
                    moveBy(delta, -delta);
                    break;
                default:
                    break;
            }
        }
        default:
            break;
    }
    return QObject::eventFilter(object, e);
}



// Select the point at a position. If there is no point deselect the selected point
void CanvasPicker::select( const QPoint &pos )
{
    QwtPlotCurve *curve = NULL;
    double dist = 10e10;
    int index = -1;

    const QwtPlotItemList& itmList = plot()->itemList();

	for ( QwtPlotItemIterator it = itmList.begin(); it != itmList.end(); ++it )
    {
        if ( (*it)->rtti() == QwtPlotItem::Rtti_PlotCurve )
        {
            QwtPlotCurve *c = (QwtPlotCurve *)( *it );

            double d;
            int idx = c->closestPoint( pos, &d );
            if ( d < dist )
            {
                curve = c;
                index = idx;
                dist = d;
            } 
        }
    }

    showCursor( false );
    d_selectedCurve = NULL;
    d_selectedPoint = -1;

    if ( curve && dist < 10 ) // 10 pixels tolerance
    {
        d_selectedCurve = curve;
        d_selectedPoint = index;
        showCursor( true );
    }
}



// Move the selected point
void CanvasPicker::moveBy(int dx, int dy)
{
    if ( dx == 0 && dy == 0 )
        return;

    if ( !d_selectedCurve )
        return;

    const QPointF sample = 
        d_selectedCurve->sample(d_selectedPoint);

    const double x = plot()->transform(
        d_selectedCurve->xAxis(), sample.x());
    const double y = plot()->transform(
        d_selectedCurve->yAxis(), sample.y());

    move( QPoint(qRound(x + dx), qRound(y + dy)) );
}

// Move the selected point
void CanvasPicker::move(const QPoint &pos)
{
    if ( !d_selectedCurve )
        return;

    QVector<double> xData(d_selectedCurve->dataSize());
    QVector<double> yData(d_selectedCurve->dataSize());

    for ( int i = 0; i < (int)d_selectedCurve->dataSize(); i++ )
    {
        if ( i == d_selectedPoint )
        {
            xData[i] = plot()->invTransform(
                d_selectedCurve->xAxis(), pos.x());
            yData[i] = plot()->invTransform(
                d_selectedCurve->yAxis(), pos.y());
        }
        else
        {
            const QPointF sample = d_selectedCurve->sample(i);
            xData[i] = sample.x();
            yData[i] = sample.y();
        }
    }
    d_selectedCurve->setSamples(xData, yData);

    plot()->replot();
    showCursor(true);
}

// Hightlight the selected point
void CanvasPicker::showCursor(bool showIt)
{
    if ( !d_selectedCurve )
        return;

    QwtSymbol *symbol = (QwtSymbol *)d_selectedCurve->symbol();

    const QBrush brush = symbol->brush();
    if ( showIt )
        symbol->setBrush(symbol->brush().color().dark(150));

    const bool doReplot = plot()->autoReplot();

    plot()->setAutoReplot(false);

    QwtPlotDirectPainter directPainter;
    directPainter.drawSeries(d_selectedCurve, d_selectedPoint, d_selectedPoint);

    if ( showIt )
        symbol->setBrush(brush); // reset brush

    plot()->setAutoReplot(doReplot);
}

// Select the next/previous curve 
void CanvasPicker::shiftCurveCursor(bool up)
{
    QwtPlotItemIterator it;

    const QwtPlotItemList &itemList = plot()->itemList();

    QwtPlotItemList curveList;
    for ( it = itemList.begin(); it != itemList.end(); ++it )
    {
        if ( (*it)->rtti() == QwtPlotItem::Rtti_PlotCurve )
            curveList += *it;
    }
    if ( curveList.isEmpty() )
        return;

    it = curveList.begin();

    if ( d_selectedCurve )
    {
        for ( it = curveList.begin(); it != curveList.end(); ++it )
        {
            if ( d_selectedCurve == *it )
                break;
        }
        if ( it == curveList.end() ) // not found
            it = curveList.begin();

        if ( up )
        {
            ++it;
            if ( it == curveList.end() )
                it = curveList.begin();
        }
        else
        {
            if ( it == curveList.begin() )
                it = curveList.end();
            --it;
        }
    }
        
    showCursor(false);
    d_selectedPoint = 0;
    d_selectedCurve = (QwtPlotCurve *)*it;
    showCursor(true);
}

// Select the next/previous neighbour of the selected point
void CanvasPicker::shiftPointCursor(bool up)
{
    if ( !d_selectedCurve )
        return;

    int index = d_selectedPoint + (up ? 1 : -1);
    index = (index + d_selectedCurve->dataSize()) % d_selectedCurve->dataSize();

    if ( index != d_selectedPoint )
    {
        showCursor(false);
        d_selectedPoint = index;
        showCursor(true);
    }
}
