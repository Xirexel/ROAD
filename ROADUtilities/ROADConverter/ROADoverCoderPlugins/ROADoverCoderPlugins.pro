TEMPLATE = subdirs

SUBDIRS += \
    ROADoverWAVECoderPlugin

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/PlatformDependencies/release/ -lPlatformDependencies
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/PlatformDependencies/debug/ -lPlatformDependencies
else:unix: LIBS += -L$$OUT_PWD/../../../ROADcodec/PlatformDependencies/ -lPlatformDependencies

INCLUDEPATH += $$PWD/../../../ROADcodec/PlatformDependencies
DEPENDPATH += $$PWD/../../../ROADcodec/PlatformDependencies

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/PlatformDependencies/release/libPlatformDependencies.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/PlatformDependencies/debug/libPlatformDependencies.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/PlatformDependencies/release/PlatformDependencies.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/PlatformDependencies/debug/PlatformDependencies.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/PlatformDependencies/libPlatformDependencies.a
