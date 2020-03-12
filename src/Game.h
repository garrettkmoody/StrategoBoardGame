#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include <vector>

class Game {

public:
  Game();
  void run();
  bool choosePiece(std::vector<int>&);
  void selectLocation(Piece*);
  bool getTurn();
private:
  bool playerTurn = true;
  Board board;
};
#endif