#include "Board.h"
#include <cstdlib>
#include <iostream>

using namespace std;

// Blue is 1 red is 0;
// Keep in mind to consider Blue to be natural bottom of the board.
// 2d array is [rows][columns] or [y][x]
// i is row j is column.

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

// added another check so it prints rivers -CM

void Board::printBlue() {
  string ind = " ";
  cout << endl << "                || RED ||\n";
  cout << "      1  2  3  4  5  6  7  8  9  10\n";
  cout << "   ==================================\n";
  
  for (int i = 0; i < 10; i++) {
    if (i > 8) {
      ind = "";
    }
    cout << ind << i + 1 << " | ";
    for (int j = 0; j < 10; j++) {
      if (Pieces[i][j]->getSide() == 1 || Pieces[i][j]->getRank() == -1) {
        cout << "[" << Pieces[i][j]->getSymbol() << "]";
      } else {
        cout << "[" << '?' << "]";
      }
    }
    cout << " |" << endl;
  }
  cout << "   ==================================\n";
  cout << "               || BLUE ||\n" << endl;
}

void Board::printRed() {
    string ind = "";
  cout << endl << "               || BLUE ||\n";
  cout << "      10 9  8  7  6  5  4  3  2  1\n";
  cout << "   ==================================\n";
  for (int i = 9; i >= 0; i--) {
      if(i < 9) {
          ind = " "; 
      }
    cout << ind << i + 1 << " | ";
    for (int j = 9; j >= 0; j--) {
      if (Pieces[i][j]->getSide() == 0 || Pieces[i][j]->getRank() == -1) {
        cout << "[" << Pieces[i][j]->getSymbol() << "]";
      } else {
        cout << "[" << '?' << "]";
      }
    }
    cout << " |" << endl;
  }
  cout << "   ==================================\n";
  cout << "               || RED ||\n" << endl;
}

// note that validateMovement needs to consider the movement abilities of the
// piece in question. We need to have seperate else ifs for x and y restrictions
// else it will return junk when we call the board to check if the end location
// is a river or an ally.    

bool Board::validateMovement(Piece *piece, int x, int y, bool playerTurn) {
  if (x < 0 || x > 9 || y < 0 || y > 9) {
    return false;
  } else if (Pieces[y][x]->getName() == "River" ||
	  (Pieces[y][x]->getName() != "Empty" && playerTurn == Pieces[y][x]->getSide())) {
    return false;
  } else {
    return true;
  }
}

// Seperated the function of validate into a validate selection and validate
// movement to support scout movement speed

bool Board::validateSelection(int x, int y, bool playerTurn) {
  if (x < 0 || y < 0 || x > 9 || y > 9) {
    throw runtime_error("This location isn't on the board.");
    cout << "This location isn't on the board." << endl;
    return false;
  } else if (Pieces[y][x]->getMovement() == 0 ||
             playerTurn != Pieces[y][x]->getSide()) {
    throw runtime_error("This piece cannot be moved.");
    cout << "This piece cannot be moved." << endl;
    return false;
  } else {
    return true;
  }
  
}

bool Board::validatePlacement(int x, int y, bool playerTurn) {
  if (playerTurn) { // blue
    if (x >= 0 && y >= 6 && x <= 9 && y <= 9 && Pieces[y][x]->getRank() < 0) {
      return true;
    } else {
      return false;
    }
  } else { // red
    if (x >= 0 && y >= 0 && x <= 9 && y <= 3 && Pieces[y][x]->getRank() < 0) {
      return true;
    } else {
      return false;
    }
  }
}

bool Board::resolveAttack(Piece* piece, int x, int y) {
	bool isSpy = (piece->getName() == "Spy");
	bool isMiner = (piece->getName() == "Miner");
	bool isMarshall = (Pieces[y][x]->getName() == "Marshall");
	bool isBomb = (Pieces[y][x]->getName() == "Bomb");

	if (Pieces[y][x]->getRank() > piece->getRank()) {
		return true;
	}
	else if (isSpy && isMarshall) {
		return true;
	}
	else if (isMiner && isBomb) {
		return true;
	}
	return false;
}

// Blue is 1, Red is 0.
// FROM GARRETT: I changed the name of the array to "Pieces" instead of "Piece"

Piece *Board::selectPiece(int x, int y, bool playerTurn) {
  Piece *piece;
  
    try {
      /* if(Pieces[y][x]->getSide() == playerTurn) {
          return 0;
      }*/
      validateSelection(x, y, playerTurn);   
      piece = Pieces[y][x];
      piece->setY(y);
      piece->setX(x); }
     catch(runtime_error & except) {
      cout << except.what() << endl;
    }
  
  return piece;
}

// doesn't look like x or y is passed by reference and since you don't set x
// or y of piece how does this affect the piece's location.
// Also, you need to consider things like the scout's movement ability, which
// lets you select the distance you want to move in a particular direction. When
// you do move in that direction you need to do a loop and "move" it through
// every space to make sure there isn't anything in the way.-CM

// THE PLAN(ish)
//=================================
// select direction
// if movement > 1 enter a distance
// validate movement
// if there is an enemy piece in the new location, fight.
// else move to location.
// replace old location with nopiece.


bool Board::move(Piece *piece) {
  char direction;
  int distance;
  bool check1 = true;
  cout << "what direction(wasd) would you like to move the piece: ";
  cin >> direction;

  while(check1) {
	  if (piece->getMovement() > 1) {
		  cout << "What distance would you like to move this piece: ";
		  cin >> distance;
		  if (distance <= piece->getMovement()) {
			  check1 = false;
		  }
		  else {
			  cout << "You can't move that far." << endl;
		  }
	  } else {
          distance = piece->getMovement();
          check1 = false;
      }
  }
    if (piece->getSide()==1) {
        distance = distance*=-1;
    }
  switch (direction) {
  case 'w': {
	  if (!validateMovement(piece, piece->getX(), piece->getY() + distance, piece->getSide())) {
		  cout << "Invalid move" << endl;
		  return false;
	  }
      else if(Pieces[piece->getY() + distance][piece->getX()]->getName() == "Empty") {
          cout << "You have moved forwards.\n";
          piece->setX(piece->getX());
		  piece->setY(piece->getY() + distance);
          Pieces[piece->getY()][piece->getX()] = piece;
          return true;
      }
	  else if (resolveAttack(piece, piece->getX(), piece->getY() + distance)) {
		  cout << "Your " << piece->getName() << " threw himself valliantly against the enemy " << Pieces[piece->getY() + distance][piece->getX()]->getName() << "."<< endl;
		  Pieces[piece->getY()][piece->getX()] = new Nopiece;
		  return true;
	  }
	  else  {
		  Pieces[piece->getY()][piece->getX()] = new Nopiece;
		  cout << "Your " << piece->getName() << " destroyed the enemy " << Pieces[piece->getY() + distance][piece->getX()]->getName() << "." << endl;
		  piece->setX(piece->getX());
		  piece->setY(piece->getY() + distance);
		  Pieces[piece->getY()][piece->getX()] = piece;
		  return true;
	  }
  }; break;
  case 's': {
	  if (!validateMovement(piece, piece->getX(), piece->getY() - distance, piece->getSide())) {
		  cout << "Invalid move" << endl;
		  return false;
	  }
      else if(Pieces[piece->getY() - distance][piece->getX()]->getName() == "Empty") {
          cout << "You have moved backwards.\n";
          piece->setX(piece->getX());
		  piece->setY(piece->getY() - distance);
          Pieces[piece->getY()][piece->getX()] = piece;
          return true;
      }
	  else if (resolveAttack(piece, piece->getX(), piece->getY() - distance)) {
		  cout << "Your " << piece->getName() << " threw himself valliantly against the enemy " << Pieces[piece->getY() - distance][piece->getX()]->getName() << "." << endl;
		  Pieces[piece->getY()][piece->getX()] = new Nopiece;
		  return true;
	  }
	  else  {
		  Pieces[piece->getY()][piece->getX()] = new Nopiece;
		  cout << "Your " << piece->getName() << " destroyed the enemy " << Pieces[piece->getY() - distance][piece->getX()]->getName() << "." << endl;
		  piece->setX(piece->getX());
		  piece->setY(piece->getY() - distance);
		  Pieces[piece->getY()][piece->getX()] = piece;
		  return true;
	  }
  }; break;
  case 'd': {
	  if (!validateMovement(piece, piece->getX() - distance, piece->getY(), piece->getSide())) {
		  cout << "Invalid move" << endl;
		  return false;
	  }
      else if(Pieces[piece->getY()][piece->getX() - distance]->getName() == "Empty") {
          cout << "You have moved right.\n";
          piece->setX(piece->getX() + distance);
		  piece->setY(piece->getY());
          Pieces[piece->getY()][piece->getX()] = piece;
          return true;
      }
	  else if (resolveAttack(piece, piece->getX() - distance, piece->getY())) {
		  cout << "Your " << piece->getName() << " threw himself valliantly against the enemy " << Pieces[piece->getY()][piece->getX() - distance]->getName() << "." << endl;
		  Pieces[piece->getY()][piece->getX()] = new Nopiece;
		  return true;
	  }
	  else  {
		  Pieces[piece->getY()][piece->getX()] = new Nopiece;
		  cout << "Your " << piece->getName() << " destroyed the enemy " << Pieces[piece->getY() - distance][piece->getX()]->getName() << "." << endl;
		  piece->setX(piece->getX() + distance);
		  piece->setY(piece->getY());
		  Pieces[piece->getY()][piece->getX()] = piece;
		  return true;
	  }
  }; break;
  case 'a': {
	  if (!validateMovement(piece, piece->getX() + distance, piece->getY(), piece->getSide())) {
		  cout << "Invalid move" << endl;
   		  return false;
	  }
      else if(Pieces[piece->getY()][piece->getX() + distance]->getName() == "Empty") {
          cout << "You have moved right.\n";
          piece->setX(piece->getX() - distance);
		  piece->setY(piece->getY());
          Pieces[piece->getY()][piece->getX()] = piece;
          return true;
      }
	  else if (resolveAttack(piece, piece->getX() + distance, piece->getY())) {
		  cout << "Your " << piece->getName() << " threw himself valliantly against the enemy " << Pieces[piece->getY()][piece->getX() + distance]->getName() << "." << endl;
		  Pieces[piece->getY()][piece->getX()] = new Nopiece;
		  return true;
	  }
	  else {
		  Pieces[piece->getY()][piece->getX()] = new Nopiece;
		  cout << "Your " << piece->getName() << " destroyed the enemy " << Pieces[piece->getY() - distance][piece->getX()]->getName() << "." << endl;
		  piece->setX(piece->getX() - distance);
		  piece->setY(piece->getY());
		  Pieces[piece->getY()][piece->getX()] = piece;
		  return true;
	  }
  }; break;
  default: {
	  cout << "Invalid move" << endl;
	  return false;
  }
  }
  
}

void Board::place(Piece *piece) {
  Pieces[piece->getY()][piece->getX()] = piece;
}
