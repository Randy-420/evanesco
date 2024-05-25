ifeq ($(THEOS_PACKAGE_SCHEME),rootless)
	TARGET = iphone:14.5:14.0
else
	TARGET = iphone:clang:14.5:11.0
endif

ARCHS = arm64 arm64e

BUNDLE_NAME = evanescocc

$(BUNDLE_NAME)_FILES = $(wildcard *.m)
$(BUNDLE_NAME)_CFLAGS += -fobjc-arc
$(BUNDLE_NAME)_INSTALL_PATH = /Library/ControlCenter/Bundles/
$(BUNDLE_NAME)_PRIVATE_FRAMEWORKS = ControlCenterUIKit

include $(THEOS)/makefiles/common.mk
include $(THEOS_MAKE_PATH)/bundle.mk

after-install::
	install.exec "killall -9 SpringBoard"