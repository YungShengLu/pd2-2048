#ifndef QLCDBEST_H
#define QLCDBEST_H

#include "QHeaderfile.h"
#include "Game.h"

class Game;

class QLCDbest : public QLCDNumber {
public:
    QLCDbest(QWidget *parent = 0);

private:
    Game *game;

};

#endif // QLCDBEST_H
