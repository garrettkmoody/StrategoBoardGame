#ifndef BOARD_H
#define BOARD_H

class Board {
private:
  int Piece[10][10];

public:
  // Make a note with your name next to functions you will work on
  bool validatePlacement();

  bool validateMovement();

  void printBoard();

  void printBlue();

  void printRed();

  void move();

  void place();
};

#endif