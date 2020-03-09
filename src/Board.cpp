#include "Board.h"
#include <iostream>
using namespace std;

// Keep in mind to consider Blue to be natural bottom of the board.
// 2d array is [rows][columns] or [y][x]
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
// note that validateMovement needs to consider the movement abilities of the
// piece in question
bool Board::validateMovement(int x, int y) {
  if (x < 0 || y < 0 || x > 9 || y > 9 || Pieces[x][y]->getname() != "River") {
    return false;
  } else {
    return true;
  }
}
// Garrett seems to be making the board with (0,0) in the top left
// This needs some work. Good news though the program runs! -CM
bool Board::validatePlacement(int x, int y, bool playerTurn) {
  if (playerTurn) { // blue
    if (x < 0 || y < 5 || x > 9 || y > 9 ||
        Pieces[y][x]->getname() == "River") {
      return false;
    } else {
      return true;
    }
  } else { // red
    if (x < 0 || y < 0 || x > 9 || y > 3 ||
        Pieces[y][x]->getname() != "River") {
      return false;
    } else {
      return true;
    }
  }
}
// FROM GARRETT: I changed the name of the array to "Pieces" instead of "Piece"
Piece *Board::selectPiece(int x, int y) {
  Piece *piece;
  if (validateMovement(x, y)) {
    piece = Pieces[x][y];
  } else {
    piece = new Nopiece;
  }
  return piece;
}

void Board::move(Piece *piece, int x, int y) {
  // doesn't look like x or y is passed by reference and since you don't set x
  // or y of piece how does this affect the piece's location.
  char move;
  cin >> move;
  switch (move) {
  case 'w': {
    y++;
  } break;
  case 'a': {
    x--;
  } break;
  case 'd': {
    x++;
  } break;
  case 's': {
    y--;
  } break;
  }
  return;
}
// Problem seems to be here, besides that Game is working as intended.
void Board::place(Piece *piece) {
  Pieces[piece->getY()][piece->getX()] = piece;
}
