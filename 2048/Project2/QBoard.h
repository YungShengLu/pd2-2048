#ifndef QBOARD_H
#define QBOARD_H

#include "QHeaderfile.h"
#include "Headerfile.h"
#include "Observer.h"
#include "QHead.h"
#include "QHint.h"
#include "QBest.h"
#include "QScore.h"
#include "QNewbutton.h"
#include "QGameover.h"
#include "QWinning.h"

class QTile;
class QHint;
class QBest;
class QScore;
class QGameOver;
class QWinning;

class QBoard : public QWidget, public Observer {
    Q_OBJECT

public:
    QBoard(int version, int dimension, int target, QWidget *parent = 0);
    void notify();
    bool getFinished();

    Game *game;

private:
    QVector< QVector<QTile*> > playerBoard;
    QGridLayout *mainLayout;
    QGridLayout *board;
    QLabel *gameTitle;
    QHead *head;
    QHint *hint;
    QScore *score;
    QBest *best;
    QNewButton *reset;
    QGameOver gameOver;
    QWinning winning;
    int currVersion;
    int currDimension;
    bool finished;

    void drawBoard(int version, int dimension);

protected:
    void keyPressEvent(QKeyEvent *event);

signals:

private slots:
    void newGame();
    void resetGame();

};

#endif // QGAMEBOARD_H
