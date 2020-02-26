#ifndef PIECE_H
#define PIECE_H

#include <string>

class Piece {
    protected:
        int x, y;
        std::string name;
        char symbol;
        int rank;
        int movement;
    public:
        int getX() {return x;}
        void setX(int x) {this -> x = x;}
        int getY() {return y;}
        void setY(int y) {this -> y = y;}
        std::string getname() {return name;}
        char getSymbol() {return symbol;}
        int getRank() {return rank;}
        int getMovement() {return movement;}
};
#endif