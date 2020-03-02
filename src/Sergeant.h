#ifndef SERGEANT_H
#define SERGEANT_H

#include <string>
#include "Piece.h"

class Sergeant : public Piece{
    protected:
        std::string name = "Sergeant";
        char symbol = '7';
        int rank = 4;
        int movement =1;
};
#endif