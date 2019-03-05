#ifndef QGAMEOVER_H
#define QGAMEOVER_H

#include "QHeaderfile.h"

class QResetButton;

class QGameOver : public QWidget {
    Q_OBJECT

public:
    QGameOver(QWidget *parent = 0);
    QResetButton* getResetBtn() const;

private:
    QResetButton *reset;

signals:

public slots:

};

#endif // QGAMEOVER_H
