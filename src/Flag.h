#ifndef FLAG_H
#define FLAG_H

#include <string>
#include "Piece.h"

class Flag : public Piece{
    protected:
        std::string name = "Flag";
        char symbol = 'F';
        int rank = 0;
        int movement =0;
};
#endif