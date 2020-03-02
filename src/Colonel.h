#ifndef COLONEL_H
#define COLONEL_H

#include <string>
#include "Piece.h"

class Colonel : public Piece{
    protected:
        std::string name = "Colonel";
        char symbol = '3';
        int rank = 8;
        int movement =1;
};
#endif