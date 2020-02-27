#ifndef SCOUT_H
#define SCOUT_H

#include <string>
#include "Piece.h"

class Scout : public Piece{
    protected:
        std::string name = "Scout";
        char symbol = '9';
        int rank = 2;
        int movement =10;
};
#endif