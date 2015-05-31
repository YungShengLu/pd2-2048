#ifndef QLCDSCORE_H
#define QLCDSCORE_H

#include "QHeaderfile.h"
#include "Game.h"

class Game;

class QLCDscore : public QLCDNumber {
public:
    QLCDscore(QWidget *parent = 0);

private:
    Game *game;

};

#endif // QLCDSCORE_H
