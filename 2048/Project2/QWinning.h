#ifndef QWINNING_H
#define QWINNING_H

#include "QHeaderfile.h"
#include "QBest.h"
#include "QScore.h"

class QResetButton;
class QBest;
class QScore;

class QWinning : public QWidget {
    Q_OBJECT

public:
    QWinning(QWidget *parent = 0);
    QResetButton* getResetBtn() const;

private:
    QResetButton *reset;
    QBest *best;
    QScore * score;

signals:

public slots:

};

#endif // QWINNING_H
