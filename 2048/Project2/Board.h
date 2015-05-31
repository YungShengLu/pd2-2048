#ifndef BOARD_H
#define BOARD_H

#include "QHeaderfile.h"
#include "Subject.h"

class Tile;

enum DIRECTION {
    UP, DOWN, LEFT, RIGHT
};

class Board : public Subject {
public:
    Board(int dimension);
    Board(const Board &brd);
    ~Board();

    Tile* getTile(int i, int j);
    void move(DIRECTION direction);
    void reset();
    int getDimension() const;
    int getPoints() const;
    bool isFull() const;
    bool isCollision() const;
    bool isMovePossible() const;

private:  
    QVector<int> freePosition();
    void initialize();
    void moveHorizontal(int i, int j, DIRECTION dir);
    void moveVertical(int i, int j, DIRECTION dir);
    bool isChanged(Board &brd) const;
    bool isInBounds(int i, int j);

    QVector< QVector<Tile*> > board;
    int dimension;
    int lastPoints;
    bool lastCollision;

};

#endif // BOARD_H
