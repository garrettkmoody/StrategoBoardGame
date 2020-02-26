#ifndef CAPTAIN_H
#define CAPTAIN_H

#include <string>
#include "Piece.h"

class Captain : public Piece{
    protected:
        std::string name = "Captain";
        char symbol = '5';
        int rank = 6;
        int movement = 1;
};
#endif