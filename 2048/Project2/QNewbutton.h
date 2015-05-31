#ifndef QNEWBUTTON_H
#define QNEWBUTTON_H

#include "QHeaderfile.h"

class QNewButton : public QLabel, public QGraphicsRectItem {
    Q_OBJECT

public:
    QNewButton(QWidget *parent = 0);

signals:
    void clicked();

public slots:

protected:
    void mousePressEvent(QMouseEvent *event);
    void hoverEnterEvent(QHoverEvent *event);
    void hoverLeaveEvent(QHoverEvent *event);

};

#endif // QNEWBUTTON_H
