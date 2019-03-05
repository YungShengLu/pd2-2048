#ifndef QBUTTON_H
#define QBUTTON_H

#include "QHeaderfile.h"

class QButton : public QObject, public QGraphicsRectItem {
    Q_OBJECT

public:
    QButton(QString name, QGraphicsItem *parent = 0);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

private:
    QGraphicsTextItem *text;

signals:
    void clicked();

public slots:

};

#endif // QBUTTON_H
