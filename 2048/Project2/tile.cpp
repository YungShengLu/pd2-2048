#include "Tile.h"

#define MULTIPLIER 2

Tile::Tile() {
    number = 2;
}

Tile::Tile(const Tile &tile) {
    this->number = tile.number;
}

Tile::Tile(int value) {
    number = value;
}

int Tile::getNumber() {
    return number;
}

void Tile::upgrade() {
    number *= MULTIPLIER;
}


