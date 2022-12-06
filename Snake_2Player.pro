QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    c_connectiontoservercontroller.cpp \
    c_game.cpp \
    c_interfacefactory.cpp \
    c_lobby.cpp \
    c_myinterfaceeventfilter.cpp \
    c_myqapplication.cpp \
    c_parser.cpp \
    c_player.cpp \
    main.cpp \
    w_boardwidget.cpp \
    w_coinswidget.cpp \
    w_gameslistitemWidget.cpp \
    w_gameslistwidget.cpp \
    w_gljoinbutton.cpp \
    w_gllabel.cpp \
    w_lbckeckbox.cpp \
    w_lbeditbutton.cpp \
    w_lblabel.cpp \
    w_lblineedit.cpp \
    w_lobbyboxwidget.cpp \
    w_mainmenuinterface.cpp \
    w_mainwindow.cpp \
    w_newgameinterface.cpp \
    w_shopitemwidget.cpp \
    w_shopwidget.cpp \
    w_speedupcounterwidget.cpp \
    w_tpbutton.cpp \
    w_userinterface.cpp

HEADERS += \
    _defaultProperties.h \
    _myData.h \
    c_connectiontoservercontroller.h \
    c_game.h \
    c_interfacefactory.h \
    c_lobby.h \
    c_myinterfaceeventfilter.h \
    c_myqapplication.h \
    c_parser.h \
    c_player.h \
    w_boardwidget.h \
    w_coinswidget.h \
    w_gameslistitemWidget.h \
    w_gameslistwidget.h \
    w_gljoinbutton.h \
    w_gllabel.h \
    w_lbckeckbox.h \
    w_lbeditbutton.h \
    w_lblabel.h \
    w_lblineedit.h \
    w_lobbyboxwidget.h \
    w_mainmenuinterface.h \
    w_mainwindow.h \
    w_newgameinterface.h \
    w_shopitemwidget.h \
    w_shopwidget.h \
    w_speedupcounterwidget.h \
    w_tpbutton.h \
    w_userinterface.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    config.ini

RESOURCES += \
    images.qrc
