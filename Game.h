#ifndef GAME_H
#define GAME_H

#include "Subject.h"
#include "Board.h"

class Board;

class Game : public Subject {
public:
    Game(int dimension, int target);

    Board* getGameBoard() const;
    void restart();
    void playerMove(DIRECTION dir);
    int getScore() const;
    int getBest() const;
    bool isGameOver() const;
    bool isFinished() const;

private:
    Board *board;
    bool gameOver;
    string line;
    int finish;
    int score;
    int best;

};

#endif // GAME_H
