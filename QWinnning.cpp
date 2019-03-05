#include "QHeaderfile.h"
#include "QWinning.h"
#include "QResetbutton.h"

QWinning::QWinning(QWidget *parent) : QWidget(parent) {
    setStyleSheet("QGameOverWindow { background: rgb(237,224,200); }");
    setFixedSize(425, 205);

    QGridLayout *layout = new QGridLayout();

    QLabel *gameover = new QLabel("Winning !", this);
    gameover->setStyleSheet("QLabel { color: rgb(119,110,101); font: 40pt; font: bold; } ");
    gameover->setGeometry(100, 30, 300, 60);

    reset = new QResetButton(this);
    reset->setFixedHeight(50);
    reset->setFixedWidth(200);
    reset->setGeometry(120, 120, 50, 100);

    layout->addWidget(gameover, 0, 0);
    layout->addWidget(reset, 2, 0, 1, 2);
}

QResetButton* QWinning::getResetBtn() const {
    return reset;
}
