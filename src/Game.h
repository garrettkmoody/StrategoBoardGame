#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include <vector>

class Game {

public:
  void initialize();
  void run();
  bool choosePiece(std::vector<int>);
  void selectLocation();

private:
  bool playerTurn = true;
  Board board;
};
#endif