INSTALL_TARGET_PROCESSES = SpringBoard

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = Evanesco

Evanesco_FILES = $(wildcard *.m *.xm)
Evanesco_CFLAGS = -fobjc-arc
Evanesco_CFLAGS += -I./ -I./classes/views

include $(THEOS_MAKE_PATH)/tweak.mk
