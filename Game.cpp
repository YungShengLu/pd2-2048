#include "Headerfile.h"
#include "Game.h"
#include "Tile.h"

Game::Game(int dimension, int target) {
    finish = target;
    score = 0;
    ifstream fin("best", ios::in);
    fin >> best;
    cout << best << endl;
    board = new Board(dimension);
    restart();
}

Board* Game::getGameBoard() const {
    return board;
}

void Game::playerMove(DIRECTION dir) {
    board->move(dir);

    if (board->isCollision())
        score += board->getPoints();

    if (!board->isMovePossible())
        gameOver = true;

    notifyObs();
}

void Game::restart() {
    board->reset();
    gameOver = false;
    score = 0;
}

int Game::getScore() const {
    return score;
}

int Game::getBest() const {

    return best;
}

bool Game::isGameOver() const {
    if (!board->isMovePossible())
        return true;
    else
        return false;
}

bool Game::isFinished() const {
    for (int i = 0; i < board->getDimension(); i++) {
        for (int j = 0; j < board->getDimension(); j++) {
            if (board->getTile(i, j) != NULL && board->getTile(i, j)->getNumber() == finish)
                return true;
        }
    }

    return false;
}
