/****************************************************************************
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2020-2021 VeriSilicon Holdings Co., Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 *****************************************************************************/
#ifndef _APPSHELL_V4LDRMTEST_WLDISPLAY_H_
#define _APPSHELL_V4LDRMTEST_WLDISPLAY_H_

#ifdef WAYLAND_SUPPORT

#include "IDisplay.h"
#include <wayland-client.h>
#include <wayland-client-protocol.h>

#include "xdg-shell-client-protocol.h"
#include "linux-dmabuf-unstable-v1-client-protocol.h"
#include "viewporter-client-protocol.h"

#include <drm_fourcc.h>

struct dma_map {
    unsigned long dma_phys;
    unsigned int index;
};

struct buffer_format {
    uint32_t width;
    uint32_t height;
    unsigned stride;
    uint32_t sizeimage;
    uint32_t format;
    uint32_t type;
};

struct display {
	struct wl_display *display;
	struct wl_registry *registry;
	struct wl_compositor *compositor;
	struct wp_viewporter *viewporter;
	struct xdg_wm_base *wm_base;
	struct zwp_linux_dmabuf_v1 *dmabuf;

    struct buffer_format format;
    uint32_t drm_format;
    bool format_found;

    int v4l2_fd;
    int cma_fd;
};

struct buffer {
    uint32_t width;
    uint32_t height;
    int busy;
    int index;

    int dma_fd;
    int plane;
    unsigned long paddr;
    int plane_offset[3];

    struct wl_buffer *buf;
    struct display *display;
};

struct window {
    struct display *display;
	struct wl_surface *surface;
	struct xdg_surface *xdg_surface;
	struct xdg_toplevel *xdg_toplevel;
	struct wp_viewport *viewport;
    struct xdg_wm_base *wm_base;

    struct buffer *buffers;
    int num_bufs;
    struct dma_map *maps;

    int video_width;
    int video_height;

};

class WlDisplay : public IDisplay {
public:
    WlDisplay();
    ~WlDisplay();

    void showBuffer(unsigned char* data, int width, int height, int format, int size);
    void showBufferExt(unsigned char* yuvData, unsigned long buf_addr,
                    int width, int height, int format, int size);

    int connect_v4l2(int v4l2_fd);
    int frameid = 0;

private:
    void *g2d_handle;
    struct window *window;
};
#endif //WAYLAND_SUPPORT End
#endif