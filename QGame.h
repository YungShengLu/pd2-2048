#ifndef QGAME_H
#define QGAME_H

#include "QHeaderfile.h"
#include "Headerfile.h"
#include "QBoard.h"
#include "QGameover.h"
#include "QScore.h"
#include "QBest.h"
#include "Game.h"
#include "Observer.h"

class QBoard;
class QScore;
class QBest;
class QGameOver;
class Game;

class QGame : public QGraphicsView {
    Q_OBJECT

public:
    QGame(QWidget *parent = 0);
    void drawMenu();
    void drawOption();
    void drawGameOver();
    void setFinished();
    bool getFinished();

    QGraphicsScene *scene;

private:
    Game *game;
    QComboBox *combobox1, *combobox2, *combobox3;
    QGameOver gameOver;
    QBoard *board;
    QScore *score;
    QBest *best;
    int version;
    int dimension;
    int target;

public slots:
    void start();
    void play();
    void changeVersion(int version);
    void changeDimension(int dimension);
    void changeTarget(int target);
    void restart();

};

#endif // QGAME_H
