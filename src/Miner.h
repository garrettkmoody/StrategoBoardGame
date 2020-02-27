#ifndef MINER_H
#define MINER_H

#include <string>
#include "Piece.h"

class Miner : public Piece{
    protected:
        std::string name = "Miner";
        char symbol = '8';
        int rank = 3;
        int movement =1;
};
#endif