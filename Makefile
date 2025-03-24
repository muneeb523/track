# SPDX-License-Identifier: GPL-2.0
INSTALL_DIR := ${D}
SOURCE_DIR := ${S}

libdir ?= /usr/lib
includedir ?= /usr/include

DIR = generated/release

LIBS = $(DIR)/lib/*.so*
XML = $(DIR)/bin/*.xml
DRV = $(DIR)/bin/*.drv
MEDIA_SERVER = $(DIR)/bin/isp_media_server
VIDEO_TEST = $(DIR)/bin/*_test
VVEXT = $(DIR)/bin/vvext
INCLUDE = $(DIR)/include/*
TUNINGEXT = $(DIR)/bin/tuningext

SCRIPT := ${SOURCE_DIR}/imx/run.sh ${SOURCE_DIR}/imx/start_isp.sh

DEWARP_CONFIG = ${SOURCE_DIR}/dewarp/dewarp_config/*

ISP_TARGET := ${LIBS} ${XML} ${DRV} ${MEDIA_SERVER} \
              ${VIDEO_TEST} ${SCRIPT} ${VVEXT} ${INCLUDE} ${TUNINGEXT} \
              ${DEWARP_CONFIG}

.PHONY:clean install

clean:
	@echo "\n-------------enter isp clean -------------------------->"
	@$(RM) -rf ${INSTALL_DIR}

install:${ISP_TARGET}
	@echo "\n-------------enter isp install------------------------->"
	@install -d ${INSTALL_DIR}${libdir}
	@install -d ${INSTALL_DIR}${includedir}
	@install -d ${INSTALL_DIR}/opt/imx8-isp/bin
	@install -d ${INSTALL_DIR}/opt/imx8-isp/bin/dewarp_config
	@install -m 644 -D $(XML) ${INSTALL_DIR}/opt/imx8-isp/bin
	@install -m 755 -D $(TUNINGEXT) ${INSTALL_DIR}/opt/imx8-isp/bin
	@install -m 755 -D $(DRV) ${INSTALL_DIR}/opt/imx8-isp/bin
	@install -m 755 -D $(MEDIA_SERVER) ${INSTALL_DIR}/opt/imx8-isp/bin
	@install -m 755 -D $(VVEXT) ${INSTALL_DIR}/opt/imx8-isp/bin
	@install -m 755 -D $(VIDEO_TEST) ${INSTALL_DIR}/opt/imx8-isp/bin
	@install -m 755 -D $(SCRIPT) ${INSTALL_DIR}/opt/imx8-isp/bin

	@if [ -d $(${INSTALL_DIR}${includedir})]; \
		then cp -av --no-preserve=ownership $(INCLUDE) ${INSTALL_DIR}${includedir}; \
	fi;
	@if [ -d $(${INSTALL_DIR}/opt/imx8-isp/bin/dewarp_config)]; \
		then cp -av --no-preserve=ownership $(DEWARP_CONFIG) ${INSTALL_DIR}/opt/imx8-isp/bin/dewarp_config; \
	fi;
	@if [ -d $(${INSTALL_DIR}${libdir})]; \
		then cp -av --no-preserve=ownership $(LIBS) ${INSTALL_DIR}${libdir}; \
		chmod 644 ${INSTALL_DIR}${libdir}/*; \
	fi;
	@echo "\n-------------isp install successful ------------------->"
