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
        std::string getName() {return name;}
        char getSymbol() {return symbol;}
        int getRank() {return rank;}
        int getMovement() {return movement;}
        bool getSide() {return side;}
        void setSide(bool side) {this -> side = side;}
};


//I had to create constructors for each of the subclasses because the values(name,symbol,rank,movement) weren't being
// initialized and my print function couldn't see them - Garrett Moody

//Also it might be helpful to create a variable in the class that lets you set the team of each piece
//There is one already in the superclass. -CM
class Bomb : public Piece{
    public:
    Bomb() {
        name = "Bomb";
        symbol = 'B';
        rank = 11;
        movement = 0; }
};
class Captain : public Piece{
    public:
    Captain() {
        name = "Captain";
        symbol = '5';
        rank = 6;
        movement = 1; }
};
class Colonel : public Piece{
    public:
    Colonel() {
        name = "Colonel";
        symbol = '3';
        rank = 8;
        movement =1; }
};
class Flag : public Piece{
    public:
    Flag() {
        name = "Flag";
        symbol = 'F';
        rank = 0;
        movement =0; }
};
class General : public Piece{
    public:
    General() {
        name = "General";
        symbol = '2';
        rank = 9;
        movement =1; }
};
class Lieutenant : public Piece{
    public:
    Lieutenant() {
        name = "Lieutenant";
        symbol = '6';
        rank = 5;
        movement =1; }
};
class Major : public Piece{
    public:
    Major() {
        name = "Major";
        symbol = '4';
        rank = 7;
        movement =1; }
};
class Marshall : public Piece{
    public:
    Marshall() {
        name = "Marshall";
        symbol = '1';
        rank = 10;
        movement = 1; }
};
class Miner : public Piece{
    public:
    Miner() {
        name = "Miner";
        symbol = '8';
        rank = 3;
        movement =1; }
};
class Nopiece : public Piece{
    public:
    Nopiece() {
        name = "Empty";
        symbol = ' ';
        rank = -1;
        movement = 0; }
};
class River : public Piece{
    public:
    River() {
        name = "River";
        symbol = '~';
        rank = -1;
        movement = 0; }
};
class Scout : public Piece{
    public:
    Scout() {
        name = "Scout";
        symbol = '9';
        rank = 2;
        movement =10; }
};
class Sergeant : public Piece{
    public:
    Sergeant() {
        name = "Sergeant";
        symbol = '7';
        rank = 4;
        movement =1; }
};
class Spy : public Piece{
    public:
    Spy() {
        name = "Spy";
        symbol = 'S';
        rank = 1;
        movement =1; }
};
#endif