#include "QNewbutton.h"

QNewButton::QNewButton(QWidget* parent) : QLabel(parent) {
    setText("New Game");

    QFont font("Ubuntu", 20, QFont::Bold);
    setFont(font);

    setFixedHeight(50);
    setFixedWidth(150);
    setAlignment(Qt::AlignCenter);

    setStyleSheet("QNewButton { background: rgb(92,64,51); color: rgb(255,255,255); border-radius: 5px; }");
}

void QNewButton::mousePressEvent(QMouseEvent *event) {
    emit clicked();
}

void QNewButton::hoverEnterEvent(QHoverEvent *event) {
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}

void QNewButton::hoverLeaveEvent(QHoverEvent *event) {
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}
