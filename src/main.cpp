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

 using namespace std;
#include "Game.h"
 void intro();

int main() {

    intro();
    Game Game;
    Game.initialize();
    // next need to use game class

    return 0;

}

void intro() {

    cout << "Welcome To The Stratego Simulator!" << endl;

    cout << "    Press Any Key To Continue     " << endl;
    cin.get();

}