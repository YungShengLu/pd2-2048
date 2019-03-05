#ifndef TILE_H
#define TILE_H

#include <Headerfile.h>

using namespace std;

struct VALUE {
    int number;
    string word;
};

class Tile {
public:
    Tile();
    Tile(const Tile &tile);
    Tile(int number);
    int getNumber();
    string getWord(int number);
    string match(int number);
    void upgrade();

private:
    struct VALUE value;

};

#endif // TILE_H
