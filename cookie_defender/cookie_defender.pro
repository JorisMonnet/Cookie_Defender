QT       += core gui
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += resources_big


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    difficultymenu.cpp \
    encyclopedia.cpp \
    encyclowidg.cpp \
    game.cpp \
    main.cpp \
    mainmenu.cpp \
    map.cpp \
    mapmenu.cpp \
    monster.cpp \
    pausemenu.cpp \
    projectile.cpp \
    soundboxes.cpp \
    story.cpp \
    tower.cpp

HEADERS += \
    difficultymenu.h \
    encyclopedia.h \
    encyclowidg.h \
    game.h \
    mainmenu.h \
    map.h \
    mapmenu.h \
    monster.h \
    pausemenu.h \
    projectile.h \
    soundboxes.h \
    story.h \
    tower.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    formEncyclo.ui

RESOURCES += \
    Ressources.qrc \
    Ressources.qrc
