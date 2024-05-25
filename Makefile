FINALPACKAGE = 1
TARGET = iphone:clang:14.5:7.0
PACKAGE_VERSION= 2024.05.25

#export THEOS_PACKAGE_SCHEME = rootless

ifeq ($(THEOS_PACKAGE_SCHEME), rootful)
	THEOS_PACKAGE_DIR = DEBs/rootful
else ifeq ($(THEOS_PACKAGE_SCHEME), rootless)
	TARGET = iphone:14.5:14.0
	THEOS_PACKAGE_DIR = DEBs/rootless
else ifeq ($(THEOS_PACKAGE_SCHEME), jailed)
	THEOS_PACKAGE_DIR = DEBs/jailed
else
	THEOS_PACKAGE_DIR = DEBs
endif

export PKG_VERSION=$(PACKAGE_VERSION)

SUBPROJECTS += source/evanescocc
SUBPROJECTS += source/extension
SUBPROJECTS += source/preferences

include $(THEOS)/makefiles/common.mk
include $(THEOS_MAKE_PATH)/aggregate.mk

after-install::
	install.exec "killall -9 backboardd"