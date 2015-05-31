#-------------------------------------------------
#
# Project created by QtCreator 2015-05-12T13:19:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2048
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11
CONFIG += debug_and_release

SOURCES += main.cpp\
    QTile.cpp \
    QResetbutton.cpp \
    QBoard.cpp \
    Mainwindow.cpp \
    Subject.cpp \
    Game.cpp \
    Board.cpp \
    QHead.cpp \
    QHint.cpp \
    QNewbutton.cpp \
    QGameover.cpp \
    QBest.cpp \
    QScore.cpp \
    QGame.cpp \
    QButton.cpp \
    Tile.cpp \
    QWinnning.cpp

HEADERS  += \
    QHeaderfile.h \
    QTile.h \
    QResetbutton.h \
    QBoard.h \
    Mainwindow.h \
    Headerfile.h \
    Tile.h \
    Subject.h \
    Observer.h \
    Game.h \
    Board.h \
    QHead.h \
    QHint.h \
    QNewbutton.h \
    QGameover.h \
    QBest.h \
    QScore.h \
    QGame.h \
    QButton.h \
    QWinning.h

OTHER_FILES += \
    num2048.png

RC_FILE = Resource.rc

