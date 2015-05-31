#ifndef QSCORE_H
#define QSCORE_H

#include "QHeaderfile.h"

class QScore : public QWidget {
    Q_OBJECT

public:
    QScore(QWidget *parent = 0);
    QString getScore();
    void setScore(QString count);

private:
    QVBoxLayout *mainLayout;
    QLabel *title, *count;

};

#endif // QSCORE_H
