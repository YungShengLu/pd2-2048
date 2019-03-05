#include "QHeaderfile.h"
#include "QBoard.h"
#include "QTile.h"
#include "QButton.h"
#include "QNewbutton.h"
#include "QResetbutton.h"
#include "Board.h"
#include "Tile.h"
#include "Game.h"

QBoard::QBoard(int version, int dimension, int target, QWidget *parent) : QWidget(parent) {
    setFixedSize(750, 900);

    currVersion = version;
    currDimension = dimension;

    mainLayout = new QGridLayout();
    setLayout(mainLayout);
    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

    board = NULL;

    // create the game and register as observer
    game = new Game(dimension, target);
    game->registerObs(this);

    // create the gui board and draw it
    playerBoard.resize(game->getGameBoard()->getDimension());

    for (int i = 0; i < game->getGameBoard()->getDimension(); i++)
        playerBoard[i].resize(game->getGameBoard()->getDimension());

    for (int i = 0; i < game->getGameBoard()->getDimension(); i++) {
        for (int j = 0; j < game->getGameBoard()->getDimension(); j++)
            playerBoard[i][j] = NULL;
    }

    head = new QHead(version, target);
    mainLayout->addWidget(head, 0, 0, 1, 1);

    best = new QBest();
    mainLayout->addWidget(best, 0, 1, 1, 1);

    score = new QScore();
    mainLayout->addWidget(score, 0, 2, 1, 1);

    hint = new QHint(target);
    mainLayout->addWidget(hint, 1, 0, 1, 1);

    reset = new QNewButton();
    mainLayout->addWidget(reset, 1, 2, 1, 1);

    drawBoard(version, dimension);

    // style sheet of the board
    setStyleSheet("QBoard { background-color: rgb(187,173,160); }");

    connect(reset, SIGNAL(clicked()), this, SLOT(resetGame()));
    connect(gameOver.getResetBtn(), SIGNAL(clicked()), this, SLOT(resetGame()));
    connect(winning.getResetBtn(), SIGNAL(clicked()), this, SLOT(resetGame()));
}

void QBoard::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Up:
        game->playerMove(UP);
        break;
    case Qt::Key_Left:
        game->playerMove(LEFT);
        break;
    case Qt::Key_Right:
        game->playerMove(RIGHT);
        break;
    case Qt::Key_Down:
        game->playerMove(DOWN);
        break;
    }
}

void QBoard::notify() {
    if (game->isGameOver())
        gameOver.show();

    if (game->isFinished())
        winning.show();

    QString getBest = best->getBest();
    int temp = getBest.toInt();

    if (game->isFinished()) {
        QString getCurr = score->getScore();
        int curr = getCurr.toInt();

        if (curr > temp)
            best->setBest(QString("%1").arg(curr));

        score->setScore(QString("%1").arg(game->getScore()));
    }
    else {
        best->setBest(QString("%1").arg(temp));
        score->setScore(QString("%1").arg(game->getScore()));
    }

    drawBoard(currVersion, currDimension);
}

void QBoard::drawBoard(int version, int dimension) {
    delete board;
    board = new QGridLayout();
    board->setSizeConstraint(QLayout::SetFixedSize);

    for (int i = 0; i < game->getGameBoard()->getDimension(); i++) {
        for (int j = 0; j < game->getGameBoard()->getDimension(); j++) {
            delete playerBoard[i][j];
            playerBoard[i][j] = new QTile(game->getGameBoard()->getTile(i, j));
            board->addWidget(playerBoard[i][j], i, j);
            playerBoard[i][j]->drawTile(version, dimension);
        }
    }

    mainLayout->addLayout(board, 2, 0, 1, 3);
}

bool QBoard::getFinished() {
    return game->isFinished();
}

void QBoard::newGame() {
    game->restart();
    best->setBest(QString("%1").arg(game->getBest()));
    score->setScore(QString("%1").arg(game->getScore()));
    drawBoard(currVersion, currDimension);
    gameOver.hide();
}

void QBoard::resetGame() {
    game->restart();
    best->setBest(QString("%1").arg(game->getBest()));
    score->setScore(QString("%1").arg(game->getScore()));
    drawBoard(currVersion, currDimension);
    gameOver.hide();
}
