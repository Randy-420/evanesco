TARGET = ::7.0
FINALPACKAGE = 1

SUBPROJECTS += source/evanescocc
SUBPROJECTS += source/extension
SUBPROJECTS += source/preferences

include $(THEOS)/makefiles/common.mk
include $(THEOS_MAKE_PATH)/aggregate.mk

after-install::
	install.exec "killall -9 backboardd"