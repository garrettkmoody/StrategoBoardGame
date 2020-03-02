#ifndef RIVER_H
#define RIVER_H

#include <string>
#include "Piece.h"

class River : public Piece{
    protected:
        std::string name = "River";
        char symbol = '~';
        int rank = -1;
        int movement = 0;
};
#endif