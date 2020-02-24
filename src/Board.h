

class Board {
private:
  int Piece[10][10];

public:
  bool validatePlacement();

  bool validateMovement();

  void printBoard();

  void printBlue();

  void printRed();

  void move();

  void place();
};