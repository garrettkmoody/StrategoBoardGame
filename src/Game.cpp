#include <iostream>
#include <vector>
using namespace std;
#include "Board.h"
#include "Game.h"

void Game::initialize() {
  // made a little progress on this for you -CM
  bool check1;

  for (int i = 40; i > 0; i--) {
    vector<int> piecesRemainingB = {6, 1, 1, 2, 3, 4, 4, 4, 5, 8, 1, 1};
    board.printBlue();
    cout << endl << "\tLeft to place: " << endl;
    cout << "Bomb: " << piecesRemainingB.at(0)
         << "\tMarshall: " << piecesRemainingB.at(1)
         << "\tGeneral: " << piecesRemainingB.at(2) << endl;
    cout << "Colonel: " << piecesRemainingB.at(3)
         << "\tMajor: " << piecesRemainingB.at(4)
         << "\tCaptain: " << piecesRemainingB.at(5) << endl;
    cout << "Lieutenant: " << piecesRemainingB.at(6)
         << "\tSergeant: " << piecesRemainingB.at(7)
         << "\tMiner: " << piecesRemainingB.at(8) << endl;
    cout << "Scout: " << piecesRemainingB.at(9)
         << "\tSpy: " << piecesRemainingB.at(10)
         << "\tFlag: " << piecesRemainingB.at(11) << endl;

    check1 = true;
    while (check1) {
      check1 = choosePiece(piecesRemainingB);
    }
    cout << "\033[2J\033[1;1H";
    vector<int> piecesRemainingR = {6, 1, 1, 2, 3, 4, 4, 4, 5, 8, 1, 1};
    board.printRed();
    cout << endl << "\tLeft to place: " << endl;
    cout << "Bomb: " << piecesRemainingR.at(0)
         << "\tMarshall: " << piecesRemainingR.at(1)
         << "\tGeneral: " << piecesRemainingR.at(2) << endl;
    cout << "Colonel: " << piecesRemainingR.at(3)
         << "\tMajor: " << piecesRemainingR.at(4)
         << "\tCaptain: " << piecesRemainingR.at(5) << endl;
    cout << "Lieutenant: " << piecesRemainingR.at(6)
         << "\tSergeant: " << piecesRemainingR.at(7)
         << "\tMiner: " << piecesRemainingR.at(8) << endl;
    cout << "Scout: " << piecesRemainingR.at(9)
         << "\tSpy: " << piecesRemainingR.at(10)
         << "\tFlag: " << piecesRemainingR.at(11) << endl;

    check1 = true;
    while (check1) {
      check1 = choosePiece(piecesRemainingR);
    }
  }
  cout << "\033[2J\033[1;1H"; // this is clear line  format: \escape[command\escape[command;
}
bool Game::choosePiece(vector<int> piecesRemaining) {
  cout << "Enter the name of the string you would like to select: ";
  string tempName;
  cin >> tempName;
  if (tempName == "Bomb" || piecesRemaining.at(0) > 0) {
    Bomb* bomb;
    selectLocation();
    return false;
  } else if (tempName == "Marshall" || piecesRemaining.at(1) > 0) {
    Marshall* Marshall;
    selectLocation();
    return false;
  } else if (tempName == "General" || piecesRemaining.at(2) > 0) {
    General* General;
    selectLocation();
    return false;
  } else if (tempName == "Colonel" || piecesRemaining.at(3) > 0) {
    Colonel* Colonel;
    selectLocation();
    return false;
  } else if (tempName == "Major" || piecesRemaining.at(4) > 0) {
    Major* Major;
    selectLocation();
    return false;
  } else if (tempName == "Captain" || piecesRemaining.at(5) > 0) {
    Captain* Captain;
    selectLocation();
    return false;
  } else if (tempName == "Lieutenant" || piecesRemaining.at(6) > 0) {
    Lieutenant* Lieutenant;
    selectLocation();
    return false;
  } else if (tempName == "Sergeant" || piecesRemaining.at(7) > 0) {
    Sergeant* Sergeant;
    selectLocation();
    return false;
  } else if (tempName == "Miner" || piecesRemaining.at(8) > 0) {
    Miner* Miner;
    selectLocation();
    return false;
  } else if (tempName == "Scout" || piecesRemaining.at(9) > 0) {
    Scout* Scout;
    selectLocation();
    return false;
  } else if (tempName == "Spy" || piecesRemaining.at(10) > 0) {
    Spy* Spy;
    selectLocation();
    return false;
  } else if (tempName == "Flag" || piecesRemaining.at(11) > 0) {
    Flag* Flag;
    selectLocation();
    return false;
  } else {
    cout << "You have either entered an invalid piece or there are none of "
            "that piece left."
         << endl;
    cout << "Please try again." << endl;
    return true;
  }
}

void Game::selectLocation() {
  // I'm gonna stop here for now feel free to continue or adjust my work at your
  // leasure- CM
  // place needs to be worked on
  // wondering if I should declare a temporary instance that will get assigned
  // to the array later, which I think would reduce the number of if else ifs.
}
void Game::run() {}