#include "QHeaderfile.h"
#include "Headerfile.h"
#include "Board.h"
#include "Tile.h"

using namespace std;

Board::Board(int dimension) {
    lastPoints = 0;
    lastCollision = false;
    this->dimension = dimension;
    initialize();
}

Board::Board(const Board &brd) {
    dimension = brd.dimension;
    initialize();
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (brd.board[i][j] == NULL)
                board[i][j] = NULL;
            else
                board[i][j] = new Tile(*(brd.board[i][j]));
        }
    }
}

Board::~Board() {
    for (int i = 0 ; i < dimension; i++) {
        for (int j = 0; j < dimension; j++)
            delete board[i][j];
    }
}

Tile* Board::getTile(int i, int j) {
    return board[i][j];
}

void Board::initialize() {
    board.resize(dimension);
    for (int i = 0; i < dimension; i++)
        board[i].resize(dimension);

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++)
            board[i][j] = NULL;
    }
}

void Board::move(DIRECTION direction) {
    Board pre_move_board(*this);
    lastCollision = false;
    lastPoints = 0;

    switch (direction) {
        case UP:
            for (int i = 0; i < dimension; i++) {
                for (int j = 0; j < dimension; j++)
                    moveVertical(i, j, UP);
            }
            break;
        case DOWN:
            for (int i = dimension-1; i >= 0; i--) {
                for (int j = 0; j < dimension; j++)
                    moveVertical(i, j, DOWN);
            }
            break;
        case LEFT:
            for (int i = 0; i < dimension; i++) {
                for (int j = 0; j < dimension; j++)
                    moveHorizontal(i, j, LEFT);
            }
            break;
        case RIGHT:
            for (int i = 0; i < dimension; i++) {
                for (int j = dimension-1; j >= 0; j--)
                    moveHorizontal(i, j, RIGHT);
            }
            break;
    }

    if (isChanged(pre_move_board)) {
        QVector<int> newpos = freePosition();
        board[newpos[0]][newpos[1]] = new Tile();
    }

    notifyObs();
}

void Board::reset() {
    lastPoints = 0;
    lastCollision = false;
    for (int i = 0; i < dimension ; i++) {
        for (int j = 0; j < dimension; j++) {
            delete board[i][j];
            board[i][j] = NULL;
        }
    }

    QVector<int> start = freePosition();
    board[start[0]][start[1]] = new Tile();

    start = freePosition();
    board[start[0]][start[1]] = new Tile();

}

int Board::getDimension() const {
    return dimension;
}

int Board::getPoints() const {
    return lastPoints;
}

QVector<int> Board::freePosition() {
    QVector<int> position;
    if (isFull()) {
        position.append(-1);
        position.append(-1);
    }
    else {
        int i, j;

        do {
            i = rand() % dimension;
            j = rand() % dimension;
        } while (board[i][j] != NULL);

        position.append(i);
        position.append(j);
    }

    return position;
}

void Board::moveHorizontal(int i, int j, DIRECTION dir) {
    if (board[i][j] != NULL) {
        bool isCollision = false;
        int newj;

        if (dir == RIGHT)
            newj = j + 1;
        else
            newj = j - 1;

        while (isInBounds(i,newj) && board[i][newj] == NULL) {
            if (dir == RIGHT)
                newj++;
            else
                newj--;
        }


        if (!isInBounds(i, newj)) {
            if (dir == RIGHT)
                board[i][dimension-1] = board[i][j];
            else
                board[i][0] = board[i][j];
        }
        else {
            if (board[i][newj]->getNumber() == board[i][j]->getNumber()) {
                board[i][newj]->upgrade();
                isCollision = true;
                lastPoints += board[i][newj]->getNumber();
            }
            else {
                if (dir == RIGHT)
                    board[i][newj-1] = board[i][j];
                else
                    board[i][newj+1] = board[i][j];
            }
        }

        if ((dir == RIGHT && newj-1 != j) || (dir == LEFT && newj+1 != j) || isCollision)
            board[i][j] = NULL;

        if (isCollision)
            lastCollision = true;
    }
}

void Board::moveVertical(int i, int j, DIRECTION dir) {
    if (board[i][j] != NULL) {
        bool isCollision = false;
        int newi;

        if (dir == UP)
            newi = i - 1;
        else
            newi = i + 1;

        while (isInBounds(newi, j) && board[newi][j] == NULL) {
            if (dir == UP)
                newi--;
            else
                newi++;
        }


        if (!isInBounds(newi, j)) {
            if (dir == UP)
                board[0][j] = board[i][j];
            else
                board[dimension-1][j] = board[i][j];
        }
        else {
            if (board[newi][j]->getNumber() == board[i][j]->getNumber()) {
                board[newi][j]->upgrade();
                isCollision = true;
                lastPoints += board[newi][j]->getNumber();
            }
            else {
                if (dir == UP)
                    board[newi+1][j] = board[i][j];
                else
                    board[newi-1][j] = board[i][j];
            }
        }

        if ((dir == UP && newi+1 != i) || (dir == DOWN && newi-1 != i) || isCollision)
            board[i][j] = NULL;

        if (isCollision)
            lastCollision = true;
    }
}

bool Board::isChanged(Board &brd) const {
    if (dimension != brd.dimension)
        return false;

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (((board[i][j] == NULL && brd.board[i][j] != NULL) ||
                (board[i][j] != NULL && brd.board[i][j] == NULL)) ||
                 ((board[i][j] != NULL && brd.board[i][j] != NULL) &&
                board[i][j]->getNumber() != brd.board[i][j]->getNumber()))
                return true;
        }
    }

    return false;
}

bool Board::isMovePossible() const {
    if (isFull()) {
        Board newBoard(*this);

        newBoard.move(UP);
        if (isChanged(newBoard))
            return true;

        newBoard.move(DOWN);
        if (isChanged(newBoard))
            return true;

        newBoard.move(LEFT);
        if (isChanged(newBoard))
            return true;

        newBoard.move(RIGHT);
        if (isChanged(newBoard))
            return true;

        return false;
    }
    else
        return true;
}

bool Board::isFull() const {
    bool flag = true;

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (board[i][j] == NULL)
                flag = false;
        }
    }

    return flag;
}

bool Board::isCollision() const {
    return lastCollision;
}

bool Board::isInBounds(int i, int j) {
    return (i >= 0 && j >= 0 && i < dimension && j < dimension);
}
