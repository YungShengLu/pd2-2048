#ifndef QHINT_H
#define QHINT_H

#include "QHeaderfile.h"
#include "QBoard.h"

class QHint : public QWidget {
    Q_OBJECT

public:
    QHint(int target, QWidget *parent = 0);

private:
    QHBoxLayout *mainLayout;
    QLabel *hint;

signals:

public slots:

};


#endif // QHINT_H
