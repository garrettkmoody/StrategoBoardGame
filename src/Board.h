#ifndef BOARD_H
#define BOARD_H
#include "Piece.h"
#include <iostream>


class Board {
private:
  Piece* Pieces[10][10];

  

public:
  // Make a note with your name next to functions you will work on
  Board() {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        Pieces[i][j] = new Nopiece();
      }
    }
    Pieces[4][2] = new River();
    Pieces[4][3] = new River();
    Pieces[5][2] = new River();
    Pieces[5][3] = new River();
    Pieces[4][6] = new River();
    Pieces[4][7] = new River();
    Pieces[5][6] = new River();
    Pieces[5][7] = new River();
  }

  void randomizePieces();
  /* ^^^ only here if we want to create a function that randomizes pieces instead of players choosing where each
   one goes*/
  Piece* selectPiece(int x, int y);

  bool validatePlacement(int x, int y, bool playerTurn);

  bool validateMovement(int x, int y);

  void printBoard();

  void printBlue();

  void printRed();

  void move(Piece* piece, int x, int y);

  void place(Piece* piece);
};

#endif