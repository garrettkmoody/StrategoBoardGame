#ifndef MARSHALL_H
#define MARSHALL_H

#include <string>
#include "Piece.h"

class Marshall : public Piece{
    protected:
        std::string name = "Marshall";
        char symbol = '1';
        int rank = 10;
        int movement = 1;
};
#endif