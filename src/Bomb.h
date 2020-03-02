#ifndef BOMB_H
#define BOMB_H

#include <string>
#include "Piece.h"

class Bomb : public Piece{
    protected:
        std::string name = "Bomb";
        char symbol = 'B';
        int rank = 11;
        int movement = 0;
};
#endif