#ifndef BOARD_H
#define BOARD_H
#include "Piece.h"

class Board {
private:
  Piece* Piece[10][10];

  

public:
  // Make a note with your name next to functions you will work on
  Board() {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        Piece[i][j] = '?';
      }
    }
  }

  Piece selectPiece(int x, int y);

  bool validatePlacement();

  bool validateMovement();

  void printBoard();

  void printBlue();

  void printRed();

  void move();

  void place();
};

#endif