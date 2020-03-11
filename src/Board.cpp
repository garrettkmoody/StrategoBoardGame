#include "Board.h"
#include <cstdlib>
#include <iostream>

using namespace std;
//Blue is 1 red is 0;
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
  cout << endl << "             || RED ||\n";
  cout << "==================================\n";
  for (int i = 0; i < 10; i++) {
    cout << "| ";
    for (int j = 0; j < 10; j++) {
      if (Pieces[i][j]->getSide() == 1) {
        cout << "[" << Pieces[i][j]->getSymbol() << "]";
      } else {
        cout << "[" << '?' << "]";
      }
    }
    cout << " |" << endl;
  }
  cout << "==================================\n";
  cout << "            || BLUE ||\n" << endl;
}

void Board::printRed() {}

// note that validateMovement needs to consider the movement abilities of the
// piece in question.
bool Board::validateMovement(Piece *piece, int x, int y, int movement,
                             bool playerTurn) {
  if ((!(abs(piece->getX() - x) <= movement && abs(piece->getY() - y) == 0) &&
       !(abs(piece->getY() - y) <= movement && abs(piece->getX() - x) == 0))) {
    return false;
  } else if ((x < 0 || y < 0 || x > 9 || y > 9) ||
             Pieces[y][x]->getName() == "River" ||
             playerTurn == Pieces[y][x]->getSide()) {
    return false;
  } else {
    return true;
  }
}

// Seperated the function of validate into a validate selection and validate
// movement to support scout movement speed
bool Board::validateSelection(int x, int y, bool playerTurn) {
  if (x < 0 || y < 0 || x > 9 || y > 9) {
    return false;
  } else if (Pieces[y][x]->getName() == "River" ||
             playerTurn != Pieces[y][x]->getSide()) {
    return false;
  } else {
    return true;
  }
}

// Garrett seems to be making the board with (0,0) in the top left keep that in
// mind. Blue seems to work ok, but red needs work -CM
// If you restrict the placement to the x and y values you have, then there's
// no way to hit a river piece. -AP
bool Board::validatePlacement(int x, int y, bool playerTurn) {
  if (playerTurn) { // blue
    if (x >= 0 || y >= 6 || x <= 9 || y <= 9) {
      return true;
    } else {
      return false;
    }
  } else { // red
    if (x >= 0 || y >= 0 || x <= 9 || y <= 3) {
      return true;
    } else {
      return false;
    }
  }
}

// Blue is 1, Red is 0.
// FROM GARRETT: I changed the name of the array to "Pieces" instead of "Piece"
Piece *Board::selectPiece(int x, int y, bool playerTurn) {
  Piece *piece;
  do {
    if (validateSelection(x, y, playerTurn) &&
        Pieces[y][x]->getSide() == playerTurn) {
      piece = Pieces[y][x];
      piece->setY(y);
      piece->setX(x);
    } else {
      cout << "You cannot select this piece." << endl;
    }
  } while (!validateSelection(x, y, piece->getMovement()));
  return piece;
}
// doesn't look like x or y is passed by reference and since you don't set x
// or y of piece how does this affect the piece's location.
// Also, you need to consider things like the scout's movement ability, which
// lets you select the distance you want to move in a particular direction. When
// you do move in that direction you need to do a for loop and "move" it through
// every space to make sure there isn't anything in the way.-CM
void Board::move(Piece *piece, int x, int y, bool playerTurn) {
  if (validateMovement(piece, x, y, piece->getMovement(), playerTurn)) {
  }
}
// Fixed.
void Board::place(Piece *piece) {
  Pieces[piece->getY()][piece->getX()] = piece;
}
