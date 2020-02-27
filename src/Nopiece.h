#ifndef NOPIECE_H
#define NOPIECE_H

#include <string>
#include "Piece.h"

class Nopiece : public Piece{
    protected:
        std::string name = "Empty";
        char symbol = '-';
        int rank = -1;
        int movement = 0;
};
#endif