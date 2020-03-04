#ifndef LIEUTENANT_H
#define LIEUTENANT_H

#include <string>
#include "Piece.h"

class Lieutenant : public Piece{
    protected:
        std::string name = "Lieutenant";
        char symbol = '6';
        int rank = 5;
        int movement =1;
};
#endif