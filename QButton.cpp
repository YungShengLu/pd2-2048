#include "QHeaderfile.h"
#include "QButton.h"

QButton::QButton(QString name, QGraphicsItem *parent) : QGraphicsRectItem(parent) {
    setRect(0, 0, 200, 50);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGreen);
    setBrush(brush);

    text = new QGraphicsTextItem(name, this);
    QFont font("Ubuntu", 20, QFont::Bold);
    text->setFont(font);
    int pos_x = rect().width()/2 - text->boundingRect().width()/2;
    int pos_y = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(pos_x, pos_y);

    setAcceptHoverEvents(true);
}

void QButton::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    emit clicked();
}

void QButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}

void QButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGreen);
    setBrush(brush);
}
