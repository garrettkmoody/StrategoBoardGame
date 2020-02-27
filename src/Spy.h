#ifndef SPY_H
#define SPY_H

#include <string>
#include "Piece.h"

class Spy : public Piece{
    protected:
        std::string name = "Spy";
        char symbol = 'S';
        int rank = 1;
        int movement =1;
};
#endif