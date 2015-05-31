#include "QResetbutton.h"

QResetButton::QResetButton(QWidget* parent) : QLabel(parent) {
    setText("New Game");

    QFont font("Ubuntu", 20, QFont::Bold);
    setFont(font);

    setAlignment(Qt::AlignCenter);

    setStyleSheet("QResetButton { background: rgb(92,64,51); color: rgb(255,255,255); border-radius: 5px; }");
}

void QResetButton::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}
