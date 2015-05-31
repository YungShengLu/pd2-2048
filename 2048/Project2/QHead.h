#ifndef QHEAD_H
#define QHEAD_H

#include "Headerfile.h"
#include "QHeaderfile.h"
#include "Game.h"

class Game;

class QHead : public QWidget {
    Q_OBJECT

public:
    explicit QHead(int version, int target, QWidget *parent = 0);

private:
    Game *game;
    QHBoxLayout *mainLayout;
    QLabel *gameTitle;
    string head;

};

#endif // QHEAD_H
