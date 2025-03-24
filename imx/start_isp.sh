#!/bin/sh
#
# Start the isp_media_server with support for various cameras, including IMX351
#
# (c) Basler 2020
# (c) NXP 2020-2022
#

RUNTIME_DIR="$( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
NR_DEVICE_TREE_BASLER=$(grep basler-camera-vvcam `find /sys/firmware/devicetree/base/soc@0/ -name compatible | grep i2c` -l | wc -l 2> /dev/null)
NR_DEVICE_TREE_OV5640=$(grep ov5640 `find /sys/firmware/devicetree/base/soc@0/ -name compatible | grep i2c` -l | wc -l 2> /dev/null)
NR_DEVICE_TREE_OS08A20=$(grep os08a20 `find /sys/firmware/devicetree/base/soc@0/ -name compatible | grep i2c` -l | wc -l 2> /dev/null)
NR_DEVICE_TREE_IMX351=$(grep imx351 `find /sys/firmware/devicetree/base/soc@0/ -name compatible | grep i2c` -l | wc -l 2> /dev/null)

# check if the basler device has been enabled in the device tree
if [ $NR_DEVICE_TREE_BASLER -eq 1 ]; then
    echo "Starting isp_media_server for Single Basler daA3840-30mc"
    cd $RUNTIME_DIR
    if [ $NR_DEVICE_TREE_OV5640 -eq 0 ]; then
        exec ./run.sh -c basler_4k -lm
    elif [ $NR_DEVICE_TREE_OV5640 -eq 1 ]; then
        exec ./run.sh -c basler_1080p60 -lm
    fi
elif [ $NR_DEVICE_TREE_BASLER -eq 2 ]; then
    echo "Starting isp_media_server for Dual Basler daA3840-30mc"
    cd $RUNTIME_DIR
    exec ./run.sh -c dual_basler_1080p60 -lm
elif [ $NR_DEVICE_TREE_OS08A20 -eq 1 ]; then
    echo "Starting isp_media_server for Single OS08A20"
    cd $RUNTIME_DIR
    if [ $NR_DEVICE_TREE_OV5640 -eq 0 ]; then
        exec ./run.sh -c os08a20_4k -lm
    elif [ $NR_DEVICE_TREE_OV5640 -eq 1 ]; then
        exec ./run.sh -c os08a20_1080p60 -lm
    fi
elif [ $NR_DEVICE_TREE_OS08A20 -eq 2 ]; then
    echo "Starting isp_media_server for Dual OS08A20"
    cd $RUNTIME_DIR
    exec ./run.sh -c dual_os08a20_1080p60 -lm
elif [ $NR_DEVICE_TREE_IMX351 -eq 1 ]; then
    echo "Starting isp_media_server for Single IMX351"
    cd $RUNTIME_DIR
    exec ./run.sh -c imx351_4k -lm
elif [ $NR_DEVICE_TREE_IMX351 -eq 2 ]; then
    echo "Starting isp_media_server for Dual IMX351"
    cd $RUNTIME_DIR
    exec ./run.sh -c dual_imx351_1080p60 -lm
else
    echo "No compatible device found, check dtb file!" >&2
    exit 6
fi
