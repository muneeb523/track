#!/bin/bash
echo "ISP software trim for release"

echo "remove 3a source code..."
rm ../../aaa/ -rf

echo "remove bufferpool source code..."
rm ../../bufferpool/ -rf

echo "remove bufsync_ctrl source code..."
rm ../../bufsync_ctrl/ -rf

echo "remove cam_calibdb source code..."
rm ../../cam_calibdb/ -rf

echo "remove cam_device source code..."
rm ../../cam_device/source -rf
rm ../../cam_device/proprietories -rf
rm ../../cam_device/CMakeLists.txt -rf
rm ../../cam_device/LICENSE -rf

echo "remove cam_engine source code..."
rm ../../cam_engine/ -rf

echo "remove cameric_drv source code..."
rm ../../cameric_drv/include_priv -rf
rm ../../cameric_drv/proprietories -rf
rm ../../cameric_drv/source -rf
rm ../../cameric_drv/CMakeLists.txt -rf
rm ../../cameric_drv/LICENSE -rf
mv ../../cameric_drv/include/cameric_drv_common.h ../../cameric_drv/
rm ../../cameric_drv/include -rf

echo "remove cameric_reg_drv source code..."
rm ../../cameric_reg_drv/ -rf

echo "remove cim_ctrl source code..."
rm ../../cim_ctrl/ -rf

echo "remove cmodel source code..."
rm ../../cmodel/ -rf

echo "remove common source code..."
rm ../../common/source -rf
rm ../../common/include_priv -rf
rm ../../common/CMakeLists.txt -rf
rm ../../common/LICENSE -rf

echo "remove dom_ctrl source code..."
rm ../../dom_ctrl/ -rf

echo "remove ebase source code..."
rm ../../ebase/source -rf
rm ../../ebase/CMakeLists.txt -rf
rm ../../ebase/LICENSE -rf

echo "remove fpga source code..."
rm ../../fpga/CMakeLists.txt -rf
rm ../../fpga/LICENSE -rf
mv ../../fpga/fpga/include/* ../../fpga/
rm ../../fpga/fpga/ -rf

echo "remove hal source code..."
rm ../../hal/include_priv -rf
rm ../../hal/proprietories -rf
rm ../../hal/source -rf
rm ../../hal/CMakeLists.txt -rf
rm ../../hal/LICENSE -rf
mv ../../hal/include/* ../../hal/
rm ../../hal/include -rf

echo "remove i2c_drv source code..."
rm ../../i2c_drv/include_priv -rf
rm ../../i2c_drv/source -rf
rm ../../i2c_drv/CMakeLists.txt -rf
rm ../../i2c_drv/LICENSE -rf
mv ../../i2c_drv/include/* ../../i2c_drv/
rm ../../i2c_drv/include -rf

echo "remove ibd source code..."
rm ../../ibd/ -rf

echo "remove isi source code..."
rm ../../isi/source -rf
rm ../../isi/LICENSE -rf

echo "remove mim_ctrl source code..."
rm ../../mim_ctrl/ -rf

echo "remove mipi_drv source code..."
rm ../../mipi_drv/ -rf

echo "remove mkrel source code..."
rm ../../mkrel/ISP8000/ -rf
rm ../../mkrel/ISP8000_*/ -rf
rm ../../mkrel/ISP8000L*/ -rf
rm ../../mkrel/ISP8000NANO/ -rf
rm ../../mkrel/ISP8000NANO_V1801/ -rf

echo "remove mom_ctrl source code..."
rm ../../mom_ctrl/ -rf

echo "remove oslayer source code..."
rm ../../oslayer/source -rf
rm ../../oslayer/CMakeLists.txt -rf
rm ../../oslayer/LICENSE -rf
mv ../../oslayer/include/* ../../oslayer
rm ../../oslayer/include/ -rf

echo "remove scmi source code..."
rm ../../scmi/ -rf

echo "remove som_ctrl source code..."
rm ../../som_ctrl/ -rf

echo "remove test source code..."
rm ../../test/ -rf

echo "remove Test.bm source code..."
rm ../../Test.bm/ -rf

echo "remove version source code..."
rm ../../version/ -rf

echo "remove version source code..."
rm ../../vom_ctrl/ -rf

echo "remove xom_ctrl source code..."
rm ../../xom_ctrl/ -rf

echo "remove tuningext source code..."
rm ../../../tuningext/config -rf
rm ../../../tuningext/dependent -rf
rm ../../../tuningext/include -rf
rm ../../../tuningext/source -rf
rm ../../../tuningext/CMakeLists.txt -rf
rm ../../../tuningext/README.md -rf
rm ../../../tuningext/LICENSE -rf

echo "remove mediacontrol source code..."
rm ../../../mediacontrol/buffer -rf
rm ../../../mediacontrol/case -rf
rm ../../../mediacontrol/daemon -rf
rm ../../../mediacontrol/fpga -rf
rm ../../../mediacontrol/include -rf
rm ../../../mediacontrol/lib -rf
rm ../../../mediacontrol/server -rf
rm ../../../mediacontrol/CMakeLists.txt -rf
rm ../../../mediacontrol/readme -rf
rm ../../../mediacontrol/README.md -rf

echo "remove dewarp source code..."
rm ../../../dewarp/cmodel -rf
rm ../../../dewarp/hal -rf
rm ../../../dewarp/parser -rf
rm ../../../dewarp/test -rf
rm ../../../dewarp/CMakeLists.txt -rf
rm ../../../dewarp/README -rf
rm ../../../dewarp/README.md -rf
rm ../../../dewarp/proprietories/hal/CMakeLists.txt -rf
rm ../../../dewarp/proprietories/parser/CMakeLists.txt -rf
rm ../../../dewarp/proprietories/mkpartitionbuild.sh -rf

echo "remove utils3rd source code..."
rm ../../../utils3rd/script -rf

echo "change binary compile configuration"
#sed -i "s/^set (GENERATE_PARTITION_BUILD 1)/#set (GENERATE_PARTITION_BUILD 1)/g" ./*.cmake

echo "binary trim done!"
