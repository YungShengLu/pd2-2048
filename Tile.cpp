#include "Tile.h"

#define MULTIPLIER 2

Tile::Tile() {
    value.number = 2;
}

Tile::Tile(const Tile &other) {
    this->value.number = other.value.number;
}

Tile::Tile(int number) {
    this->value.number = number;
}

int Tile::getNumber() {
    return value.number;
}

string Tile::getWord(int number) {
    return match(number);
}

string Tile::match(int number) {
    switch(number) {
    case 2:
        value.number = 2;
        value.word = "夏";
        break;
    case 4:
        value.number = 4;
        value.word = "商";
        break;
    case 8:
        value.number = 8;
        value.word = "周";
        break;
    case 16:
        value.number = 16;
        value.word = "秦";
        break;
    case 32:
        value.number = 32;
        value.word = "漢";
        break;
    case 64:
        value.number = 64;
        value.word = "晉";
        break;
    case 128:
        value.number = 128;
        value.word = "隋";
        break;
    case 256:
        value.number = 256;
        value.word = "唐";
        break;
    case 512:
        value.number = 512;
        value.word = "宋";
        break;
    case 1024:
        value.number = 1024;
        value.word = "元";
        break;
    case 2048:
        value.number = 2048;
        value.word = "明";
        break;
    case 4096:
        value.number = 4096;
        value.word = "清";
        break;
    }

    return value.word;
}

void Tile::upgrade() {
    value.number *= MULTIPLIER;
}

