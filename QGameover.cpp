#include "QHeaderfile.h"
#include "QGameover.h"
#include "QResetbutton.h"

QGameOver::QGameOver(QWidget *parent) : QWidget(parent) {
    setStyleSheet("QGameOverWindow { background: rgb(237,224,200); }");
    setFixedSize(425, 205);

    QVBoxLayout *layout = new QVBoxLayout();

    QLabel *gameover = new QLabel("Game Over!", this);
    gameover->setStyleSheet("QLabel { color: rgb(119,110,101); font: 40pt; font: bold; } ");
    gameover->setGeometry(60, 30, 300, 50);

    reset = new QResetButton(this);
    reset->setFixedHeight(50);
    reset->setFixedWidth(200);
    reset->setGeometry(120, 120, 50, 100);

    layout->insertWidget(0, gameover, 0, Qt::AlignCenter);
    layout->insertWidget(1, reset, 0, Qt::AlignCenter);
}

QResetButton* QGameOver::getResetBtn() const {
    return reset;
}
