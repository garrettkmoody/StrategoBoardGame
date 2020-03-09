/*************************************************************************
 *
 * Project III: Start here.
 *
 * File Name:       main.cpp
 * Name(s):         ?
 * Course:          CPTR 142
 * Date:            ?
 *
 */
//g++ main.cpp Game.cpp Board.cpp && ./a.out
 #include <iostream>
 #include "Game.h"

 using namespace std;
#include "Game.h"
 void intro();

int main() {

    Game game;

    intro();
<<<<<<< HEAD
    Game Game;
    Game.initialize();
    // next need to use game class
=======

    game.initialize();

    game.run();

    cout << "Congratulations, ";
    if ( game.getTurn() == true ) {
        cout << "Player One ";
    } else {
        cout << "Player Two ";
    }
    cout << "has won the game!" << endl;

>>>>>>> 07832037cc867a8ec081b793b8c8ab8763093f01

    return 0;

}

void intro() {

    cout << "Welcome To The Stratego Simulator!" << endl;

    cout << "    Press Any Key To Continue     " << endl;
    cin.get();

}