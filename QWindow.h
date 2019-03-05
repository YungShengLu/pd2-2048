#ifndef QWINDOW_H
#define QWINDOW_H

#include "QHeaderfile.h"
#include "QHead.h"
#include "QHint.h"
#include "QBoard.h"

class QHead;
class QHint;
class QBoard;

class QWindow : public QWidget {
    Q_OBJECT

public:
    explicit QWindow(QWidget *parent = 0);

private:
    QVBoxLayout *mainLayout;
    QHead *head;
    QHint *hint;
    QBoard *board;

signals:

public slots:

};

#endif // QWINDOW_H
