#include "Board.h"
#include <iostream>

using namespace std;

void Board::printBoard() {
  cout << endl << "            || RED ||\n";
  for (int i = 0; i < 10; i++) {
    cout << "  ";
    for (int j = 0; j < 10; j++) {
      cout << "[" << Piece[i][j] << "]";
    }
    cout << endl;
  }
  cout << "            || BLUE ||\n" << endl;
}

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
