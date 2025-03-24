To build for ANDROID, please follow below steps:

1. Install android sdk. If the sdk is already installed, go the next step.
   1) cd /opt
   2) sudo wget https://dl.google.com/android/repository/android-ndk-r25c-linux.zip
   3) sudo unzip android-ndk-r25c-linux.zip

2. Generate Makefile
   1) export ANDROID_NDK_HOME="/opt/android-ndk-r25c"
   2) export ANDROID_ROOT_PATH="/work/android";  // set to your android root path
   3) cd appshell
   4) mkdir build-android
   5) cd build-android
   6) ../android-build.sh

3. Build
   1) make


Note: Need first build android code for evk_8mp.

====================================================
For partial build:
   1) export BUILD_OS=android
   2) export ANDROID_NDK_HOME="/opt/android-ndk-r25c"
   3) cd appshell
   4) mkdir build-android
   5) cd build-android
   6) ../android-build-partial.sh
   7) make

For specific sensor driver build, please ref units/isi/drv/OS08a20/CMakeLists.txt.
