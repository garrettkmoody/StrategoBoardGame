#include "Board.h"
#include <iostream>

using namespace std;

void Board::printBoard() {
  cout << endl << "            || RED ||\n";
  for (int i = 0; i < 10; i++) {
    cout << "  ";
    for (int j = 0; j < 10; j++) {
      cout << "[" << Piece[i][j] << "]";
    }
    cout << endl;
  }
  cout << "            || BLUE ||\n" << endl;
}
