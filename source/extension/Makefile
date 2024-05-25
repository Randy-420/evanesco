ifeq ($(THEOS_PACKAGE_SCHEME),rootless)
	TARGET = iphone:14.5:14.0
else
	TARGET = iphone:clang:14.5:7.0
endif
#SYSROOT = $(THEOS)/sdks/iPhoneOS14.1.sdk

ARCHS = arm64 arm64e

INSTALL_TARGET_PROCESSES = SpringBoard

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = Evanesco

Evanesco_FILES = $(wildcard *.m *.xm)
Evanesco_CFLAGS = -fobjc-arc -Wno-deprecated-declarations
Evanesco_CFLAGS += -I./ -I./classes/views

include $(THEOS_MAKE_PATH)/tweak.mk
