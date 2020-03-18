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
 void finish(bool turn);

int main() {

    intro();

    Game game;

    game.run();

    finish(game.getTurn());

    

    return 0;

}

void intro() {

    cout << "Welcome To The Stratego Simulator!" << endl;

    cout << "    Press Any Key To Continue     " << endl;
    cin.get();

}

void finish(bool turn) {

    cout << "Congratulations, ";
    if ( turn == true ) {
        cout << "Player One ";
    } else {
        cout << "Player Two ";
    }
    cout << "has won the game!" << endl;
}