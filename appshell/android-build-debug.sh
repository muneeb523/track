TOOLCHAIN_INC_DIR=$ANDROID_NDK_HOME/toolchains/llvm/prebuilt/linux-x86_64/sysroot/usr/include
sudo mkdir -p $TOOLCHAIN_INC_DIR/imx/linux
sudo cp $ANDROID_ROOT_PATH/vendor/nxp/fsl-proprietary/include/g2d.h $TOOLCHAIN_INC_DIR
sudo cp $ANDROID_ROOT_PATH/vendor/nxp/fsl-proprietary/include/g2dExt.h $TOOLCHAIN_INC_DIR
sudo cp $ANDROID_ROOT_PATH/vendor/nxp-opensource/libdrm-imx/xf86drm.h $TOOLCHAIN_INC_DIR/drm
sudo cp $ANDROID_ROOT_PATH/vendor/nxp-opensource/libdrm-imx/xf86drmMode.h $TOOLCHAIN_INC_DIR/drm
sudo cp $ANDROID_ROOT_PATH/device/nxp/common/kernel-headers/linux/dma-buf.h $TOOLCHAIN_INC_DIR/imx/linux
sudo cp $ANDROID_ROOT_PATH/device/nxp/common/kernel-headers/linux/dma-buf-imx.h $TOOLCHAIN_INC_DIR/imx/linux


cmake	-DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK_HOME/build/cmake/android.toolchain.cmake \
      -DANDROID_NDK=$ANDROID_NDK_HOME \
      -DANDROID_ABI=arm64-v8a \
      -DANDROID_TOOLCHAIN=clang \
      -DANDROID_PLATFORM=android-29 \
      -DANDROID_ALLOW_UNDEFINED_SYMBOLS=1 \
      -DCMAKE_SYSTEM_NAME=ANDROID \
      -DANDROID_ROOT=$ANDROID_ROOT_PATH \
      -DSDKTARGETSYSROOT=$ANDROID_NDK_HOME/toolchains/llvm/prebuilt/linux-x86_64/sysroot \
      -DBoost_DEBUG=ON \
      -DBoost_VERSION_STRING=1.72.0 \
      -DBOOST_ROOT=/opt/Boost-for-Android-Prebuilt/boost-1_72_0 \
      -DBoost_INCLUDE_DIR=/opt/Boost-for-Android-Prebuilt/boost-1_72_0/include \
      -DBoost_LIBRARY_DIR_RELEASE=/opt/Boost-for-Android-Prebuilt/boost-1_72_0/arm64-v8a/lib \
      -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_INSTALL_LIBDIR=lib -DCMAKE_INSTALL_INCLUDEDIR=include \
      -DCMAKE_BUILD_TYPE=debug -DISP_VERSION=ISP8000NANO_V1802 -DPLATFORM=ARM64 -DQTLESS=1 -DFULL_SRC_COMPILE=1 -DIMX_G2D=ON -DWITH_DWE=1 -DWITH_DRM=1 -DTUNINGEXT=1 -DSUBDEV_V4L2=1 .. -Wno-dev
