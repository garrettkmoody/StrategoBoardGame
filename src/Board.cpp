#include "Board.h"
#include <iostream>

using namespace std;

void Board::printBoard() {
  cout << endl << "        || RED ||\n";
  cout << "========================\n";
  for (int i = 0; i < 10; i++) {
    cout << "| ";
    for (int j = 0; j < 10; j++) {
      cout << "[" << Pieces[i][j]->getSymbol() << "]";
    }
    cout << " |" << endl;
  }
  cout << "========================\n";
  cout << "       || BLUE ||\n" << endl;
}

 bool Board::validateMovement() {
    if()
}

bool Board::validatePlacement() {
    if(x < 0 || y < 0 || x > 9 || y > 9) {
        return false;
    } else { return true;}
}
//FROM GARRETT: I changed the name of the array to "Pieces" instead of "Piece"
Piece Board::selectPiece(int x, int y) {
        Piece piece = Piece[x][y];
        return piece;
}

void Board::move() {
    char move;
        Piece piece = selectPiece();
    cin >> move;
    switch(move) {
        case 'w': {piece.getX(); piece.getY() + 1;} break;
        case 'a': {piece.getX() - 1; piece.getY();} break;
        case 'd': {piece.getX() + 1; piece.getY();} break;
        case 's': {piece.getX(); piece.getY() - 1;} break;
    }
    return;
}

  void Board::place() {} 
