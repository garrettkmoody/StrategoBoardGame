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

  Piece* selectPiece(int x, int y, bool playerTurn);

  bool validateSelection(int x, int y, bool playerTurn);

  bool validatePlacement(int x, int y, bool playerTurn);

  bool validateMovement(Piece * piece, int x, int y, bool playerTurn);

  bool resolveAttack(Piece* piece, int x, int y);

  void printBoard();

  void printBlue();

  void printRed();

  void move(Piece* piece, int x, int y, bool playerTurn);

  void place(Piece* piece);
};

#endif