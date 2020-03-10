#include "Board.h"
#include "Piece.h"
#include <iostream>
using namespace std;

// Keep in mind to consider Blue to be natural bottom of the board.
// 2d array is [rows][columns] or [y][x]
void Board::printBoard() {
  cout << endl << "             || RED ||\n";
  cout << "==================================\n";
  for (int i = 0; i < 10; i++) {
    cout << "| ";
    for (int j = 0; j < 10; j++) {
      cout << "[" << Pieces[i][j]->getSymbol() << "]";
    }
    cout << " |" << endl;
  }
  cout << "==================================\n";
  cout << "            || BLUE ||\n" << endl;
}
void Board::printBlue() {

}
    
void Board::printRed() {
    
}

// note that validateMovement needs to consider the movement abilities of the
// piece in question.
bool Board::validateMovement(int x, int y) {
  if (x < 0 || y < 0 || x > 9 || y > 9 || Pieces[y][x]->getname() != "River") {
    return false;
  } else {
    return true;
  }
}
// Garrett seems to be making the board with (0,0) in the top left keep that in
// mind. Blue seems to work ok, but red needs work -CM
bool Board::validatePlacement(int x, int y, bool playerTurn) {
  if (playerTurn) { // blue
    if (x >= 0 || y >= 6 || x <= 9 || y <= 9 ||
        Pieces[y][x]->getname() != "River") {
      return true;
    } else {
      return false;
    }
  } else { // red
    if (x >= 0 || y >= 0 || x <= 9 || y <= 3 ||
        Pieces[y][x]->getname() != "River") {
      return true;
    } else {
      return false;
    }
  }
}
// Blue is 1, Red is 0.
// FROM GARRETT: I changed the name of the array to "Pieces" instead of "Piece"
Piece *Board::selectPiece(int x, int y) {

  Piece *piece;
  do {
  if (validateMovement(x, y) || Pieces[y][x]->getSide()) {
    piece = Pieces[y][x];
  } else {
      cout << "You cannot select this piece." << endl;
  }
  } while (!validateMovement(x,y));
  return piece;
}
// doesn't look like x or y is passed by reference and since you don't set x
// or y of piece how does this affect the piece's location.
// Also, you need to consider things like the scout's movement ability, which
// lets you select the distance you want to move in a particular direction. When
// you do move in that direction you need to do a for loop and "move" it through
// every space to make sure there isn't anything in the way.
void Board::move(Piece *piece, int x, int y) {
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
// Fixed.
void Board::place(Piece *piece) {
  Pieces[piece->getY()][piece->getX()] = piece;
}
