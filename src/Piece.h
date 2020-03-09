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
        bool side;
    public:
        int getX() {return x;}
        void setX(int x) {this -> x = x;}
        int getY() {return y;}
        void setY(int y) {this -> y = y;}
        std::string getname() {return name;}
        char getSymbol() {return symbol;}
        int getRank() {return rank;}
        int getMovement() {return movement;}
        bool getSide() {return side;}
        void setSide(bool side) {this -> side = side;}
};
class Bomb : public Piece{
    protected:
        std::string name = "Bomb";
        char symbol = 'B';
        int rank = 11;
        int movement = 0;
};
class Captain : public Piece{
    protected:
        std::string name = "Captain";
        char symbol = '5';
        int rank = 6;
        int movement = 1;
};
class Colonel : public Piece{
    protected:
        std::string name = "Colonel";
        char symbol = '3';
        int rank = 8;
        int movement =1;
};
class Flag : public Piece{
    protected:
        std::string name = "Flag";
        char symbol = 'F';
        int rank = 0;
        int movement =0;
};
class General : public Piece{
    protected:
        std::string name = "General";
        char symbol = '2';
        int rank = 9;
        int movement =1;
};
class Lieutenant : public Piece{
    protected:
        std::string name = "Lieutenant";
        char symbol = '6';
        int rank = 5;
        int movement =1;
};
class Major : public Piece{
    protected:
        std::string name = "Major";
        char symbol = '4';
        int rank = 7;
        int movement =1;
};
class Marshall : public Piece{
    protected:
        std::string name = "Marshall";
        char symbol = '1';
        int rank = 10;
        int movement = 1;
};
class Miner : public Piece{
    protected:
        std::string name = "Miner";
        char symbol = '8';
        int rank = 3;
        int movement =1;
};
class Nopiece : public Piece{
    protected:
        std::string name = "Empty";
        char symbol = ' ';
        int rank = -1;
        int movement = 0;
};
class River : public Piece{
    protected:
        std::string name = "River";
        char symbol = '~';
        int rank = -1;
        int movement = 0;
};
class Scout : public Piece{
    protected:
        std::string name = "Scout";
        char symbol = '9';
        int rank = 2;
        int movement =10;
};
class Sergeant : public Piece{
    protected:
        std::string name = "Sergeant";
        char symbol = '7';
        int rank = 4;
        int movement =1;
};
class Spy : public Piece{
    protected:
        std::string name = "Spy";
        char symbol = 'S';
        int rank = 1;
        int movement =1;
};
#endif