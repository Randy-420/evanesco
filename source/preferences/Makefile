TARGET = :clang:11.2:7.0
ARCHS = arm64 arm64e

include $(THEOS)/makefiles/common.mk

BUNDLE_NAME = Evanesco

Evanesco_FILES = $(wildcard *.m)
Evanesco_INSTALL_PATH = /Library/PreferenceBundles
Evanesco_FRAMEWORKS = UIKit
Evanesco_PRIVATE_FRAMEWORKS = Preferences
Evanesco_CFLAGS = -fobjc-arc

include $(THEOS_MAKE_PATH)/bundle.mk

internal-stage::
	$(ECHO_NOTHING)mkdir -p $(THEOS_STAGING_DIR)/Library/PreferenceLoader/Preferences$(ECHO_END)
	$(ECHO_NOTHING)cp entry.plist $(THEOS_STAGING_DIR)/Library/PreferenceLoader/Preferences/Evanesco.plist$(ECHO_END)
