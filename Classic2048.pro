#-------------------------------------------------
#
# Project created by QtCreator 2015-05-12T13:19:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Classic2048
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11
CONFIG += debug_and_release

SOURCES += main.cpp\
    QTile.cpp \
    QResetbutton.cpp \
    QBoard.cpp \
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
    QWinnning.cpp \
    Observer.cpp \

HEADERS  += \
    QHeaderfile.h \
    QTile.h \
    QResetbutton.h \
    QBoard.h \
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
    QWinning.h \

OTHER_FILES += \
    img/num2048.png \
    img/num2048.ico \
    font/Ubuntu-B.ttf \
    font/Ubuntu-BI.ttf \
    font/Ubuntu-C.ttf \
    font/Ubuntu-L.ttf \
    font/Ubuntu-LI.ttf \
    font/Ubuntu-M.ttf \
    font/Ubuntu-MI.ttf \
    font/Ubuntu-R.ttf \
    font/Ubuntu-RI.ttf \
    font/UbuntuMono-B.ttf \
    font/UbuntuMono-BI.ttf \
    font/UbuntuMono-R.ttf \
    font/UbuntuMono-RI.ttf \
    output/best

SUBDIRS += \
    Classic2048.pro

DISTFILES += \
    README.md \
    LICENSE \
    output/best

RESOURCES += \
    Resource.qrc

