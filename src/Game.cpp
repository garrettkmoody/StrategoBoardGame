#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
#include "Board.h"
#include "Game.h"

Game::Game() {
  // made a little progress on this for you -CM
  bool check1;
  char check2;
  vector<int> piecesRemainingB = {6, 1, 1, 2, 3, 4, 4, 4, 5, 8, 1, 1};
  vector<int> piecesRemainingR = {6, 1, 1, 2, 3, 4, 4, 4, 5, 8, 1, 1};
  for (int i = 40; i > 0; i--) {
    playerTurn = true;

    board.printBlue();
    // board.printBoard();
    printRemaining(piecesRemainingB);
    check1 = true;
    while (check1) {
      check1 = choosePiece(piecesRemainingB);
    }
    cout << "\033[2J\033[1;1H";
    cout << "Press any key when Red is ready." << endl;
    cin >> check2;

    playerTurn = false;

    // board.printRed();
    board.printBoard();
    printRemaining(piecesRemainingR);

    check1 = true;
    while (check1) {
      check1 = choosePiece(piecesRemainingR);
    }
    cout << "\033[2J\033[1;1H"; // this is clear console  format:
                                // \escape[command\escape[command;
    cout << "Press any key when Blue is ready." << endl << flush;
    cin >> check2;
  }
}

void Game::printRemaining(std::vector<int> piecesRemaining) {
cout << endl << "\tLeft to place: " << endl;
    cout << "Bomb: " << piecesRemaining.at(0)
         << "\t\tMarshall: " << piecesRemaining.at(1)
         << "\t\tGeneral: " << piecesRemaining.at(2) << endl;
    cout << "Colonel: " << piecesRemaining.at(3)
         << "\t\tMajor: " << piecesRemaining.at(4)
         << "\t\tCaptain: " << piecesRemaining.at(5) << endl;
    cout << "Lieutenant: " << piecesRemaining.at(6)
         << "\t\tSergeant: " << piecesRemaining.at(7)
         << "\t\tMiner: " << piecesRemaining.at(8) << endl;
    cout << "Scout: " << piecesRemaining.at(9)
         << "\t\tSpy: " << piecesRemaining.at(10)
         << "\t\tFlag: " << piecesRemaining.at(11) << endl;
}

bool Game::choosePiece(vector<int> &piecesRemaining) {
  cout << "Enter the name of the string you would like to select: ";
  string tempName;
  cin >> tempName;
  Piece *piece;
  if (tempName == "Bomb" && piecesRemaining.at(0) > 0) {
    cout << "I chose bomb!" << endl;
    piece = new Bomb;
    piece->setSide(playerTurn);
    selectLocation(piece);
    piecesRemaining.at(0)--;
    return false;
  } else if (tempName == "Marshall" && piecesRemaining.at(1) > 0) {
    piece = new Marshall;
    piece->setSide(playerTurn);
    selectLocation(piece);
    piecesRemaining.at(1)--;
    return false;
  } else if (tempName == "General" && piecesRemaining.at(2) > 0) {
    piece = new General;
    piece->setSide(playerTurn);
    selectLocation(piece);
    piecesRemaining.at(2)--;
    return false;
  } else if (tempName == "Colonel" && piecesRemaining.at(3) > 0) {
    piece = new Colonel;
    piece->setSide(playerTurn);
    selectLocation(piece);
    piecesRemaining.at(3)--;
    return false;
  } else if (tempName == "Major" && piecesRemaining.at(4) > 0) {
    piece = new Major;
    piece->setSide(playerTurn);
    selectLocation(piece);
    piecesRemaining.at(4)--;
    return false;
  } else if (tempName == "Captain" && piecesRemaining.at(5) > 0) {
    piece = new Captain;
    piece->setSide(playerTurn);
    selectLocation(piece);
    piecesRemaining.at(5)--;
    return false;
  } else if (tempName == "Lieutenant" && piecesRemaining.at(6) > 0) {
    piece = new Lieutenant;
    piece->setSide(playerTurn);
    selectLocation(piece);
    piecesRemaining.at(6)--;
    return false;
  } else if (tempName == "Sergeant" && piecesRemaining.at(7) > 0) {
    piece = new Sergeant;
    piece->setSide(playerTurn);
    selectLocation(piece);
    piecesRemaining.at(7)--;
    return false;
  } else if (tempName == "Miner" && piecesRemaining.at(8) > 0) {
    piece = new Miner;
    piece->setSide(playerTurn);
    selectLocation(piece);
    piecesRemaining.at(8)--;
    return false;
  } else if (tempName == "Scout" && piecesRemaining.at(9) > 0) {
    piece = new Scout;
    piece->setSide(playerTurn);
    selectLocation(piece);
    piecesRemaining.at(9)--;
    return false;
  } else if (tempName == "Spy" && piecesRemaining.at(10) > 0) {
    piece = new Spy;
    piece->setSide(playerTurn);
    selectLocation(piece);
    piecesRemaining.at(10)--;
    return false;
  } else if (tempName == "Flag" && piecesRemaining.at(11) > 0) {
    piece = new Flag;
    piece->setSide(playerTurn);
    selectLocation(piece);
    piecesRemaining.at(11)--;
    return false;
  } else {
    cout << "You have either entered an invalid piece or there are none of "
            "that piece left."
         << endl;
    cout << "Please try again." << endl;
    return true;
  }
}

void Game::selectLocation(Piece *piece) {
  int x, y;
  do {
    cout << "Select the location you would like to place your piece: " << endl;
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;
    if (board.validatePlacement(x, y, playerTurn)) {
      piece->setX(x);
      piece->setY(y);
      board.place(piece);
    } else {
      cout << "Invalid Location, please try again." << endl;
    }
  } while (!board.validatePlacement(x, y, playerTurn));
}

void Game::run() {
  bool continueGame = true;
  do {

    int xCoord = 0;
    int yCoord = 0;
    int xMove = 0;
    int yMove = 0;

    Piece *piecePtr;

    /*if (playerTurn == true) {
        board.printBlue();
        playerTurn = false;
    } else {
        board.printRed();
        playerTurn = true;
    }*/

    board.printBoard();
    cout << "Select the piece you would like to move: " << endl;
    cout << "x: ";
    cin >> xCoord;
    cout << "y: ";
    cin >> yCoord;

    // add selection validation

    // board.validateSelection(xCoord, yCoord, playerTurn);

    piecePtr = board.selectPiece(xCoord, yCoord, playerTurn);

    // board.validateMovement(piecePtr, xMove, yMove, piecePtr->getMovement(),
    // playerTurn);

    board.move(piecePtr, xMove, yMove, playerTurn);

    cout << "\033[2J\033[1;1H";

  } while (continueGame);
}

bool Game::getTurn() { return playerTurn; }