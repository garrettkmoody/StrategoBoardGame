#ifndef GENERAL_H
#define GENERAL_H

#include <string>
#include "Piece.h"

class General : public Piece{
    protected:
        std::string name = "General";
        char symbol = '2';
        int rank = 9;
        int movement =1;
};
#endif