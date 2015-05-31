#ifndef QBEST_H
#define QBEST_H

#include "QHeaderfile.h"
#include "Headerfile.h"
#include "Game.h"

class Game;

class QBest : public QWidget {
    Q_OBJECT

public:
    QBest(QWidget *parent = 0);
    QString getBest();
    void setBest(QString count);

private:
    Game *game;
    QVBoxLayout *mainLayout;
    QLabel *title, *count;
    string line;
    int curr;

};


#endif // QBEST_H
