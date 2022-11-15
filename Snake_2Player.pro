QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    c_board.cpp \
    c_game.cpp \
    c_myinterfaceeventfilter.cpp \
    c_myqapplication.cpp \
    c_snake.cpp \
    main.cpp \
    w_boardwidget.cpp \
    w_coinswidget.cpp \
    w_mainwindow.cpp \
    w_shopitemwidget.cpp \
    w_shopwidget.cpp \
    w_speedupcounterwidget.cpp

HEADERS += \
    _defaultProperties.h \
    _myData.h \
    c_board.h \
    c_game.h \
    c_myinterfaceeventfilter.h \
    c_myqapplication.h \
    c_snake.h \
    w_boardwidget.h \
    w_coinswidget.h \
    w_mainwindow.h \
    w_shopitemwidget.h \
    w_shopwidget.h \
    w_speedupcounterwidget.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    config.ini \
    stylesheet.css \
    stylesheet_bright.css \
    stylesheet_dark.css

RESOURCES += \
    images.qrc
