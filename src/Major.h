#ifndef MAHOR_H
#define MAHOR_H

#include <string>
#include "Piece.h"

class Major : public Piece{
    protected:
        std::string name = "Major";
        char symbol = '4';
        int rank = 7;
        int movement =1;
};
#endif