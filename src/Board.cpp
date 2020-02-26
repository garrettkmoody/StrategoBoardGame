#include <iostream>
#include "Board.h"

bool Board::validateMovement() {
    if()
}

bool Board::validatePlacement() {
    if(x < 0 || y < 0 || x > 9 || y > 9) {
        return false;
    } else { return true;}
}

void Board::move() {
    char move;
    std::cin >> move;
    switch(move) {
        case 'w': {Piece.getX(); Piece.getY() + 1;} break;
        case 'a': {Piece.getX() - 1; Piece.getY();} break;
        case 'd': {Piece.getX() + 1; Piece.getY();} break;
        case 's': {Piece.getX(); Piece.getY() - 1;} break;
    }
    return;
}

  void Board::place() {}