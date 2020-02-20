# CPTR 142: Project III Specifications

The specifications outlines the project design specifications and project management.
This is done BEFORE CODING!

Here are the things to include in this document.

* ___Complete UML diagrams___ of classes, member variables, member functions, and relationships between classes.
  What structures and menus will be required?  

| Main |
| ---- |
| + void intro() |
| + int main() |

    |
    |
    V

| Game |
| ---- |
| - bool playerTurn = false |
| - Board board |
| + void initialize() |
| + void run() |

    |
    |
    V
    
| Board |
| ----- |
| - Piece[10][10] board |
| - bool validatePlacement() |
| - bool validateMovement() |
| + void printBoard() |
| + void printBlue() |
| + void printRed() |
| + void move() |
| + void place() |

    |
    |
    V

| Piece |
| ----- |
| - int x,y |
| - virtual string name |
| - virtual char symbol |
| - virtual int rank |
| - virtual int movement |
| + int getX() |
| + void setX(int x) |
| + int getY() |
| + void setY(int y) |
| + string getName() |
| + char getSymbol() |
| + int getRank() |
| + int getMovement() |

    |
    |
    _
    V
    
| Flag | Spy | Scout | Miner | Sergeant | Lieutenant | Captain | Major | Colonel | General | Marshall | Bomb |
| ---- | --- | ----- | ----- | -------- | ---------- | ------- | ----- | ------- | ------- | -------- | ---- |
| - string name = "Flag"| - string name = "Spy"| - string name = "Scout"| - string name = "Miner"| - string name = "Sergeant"| - string name = "Lieutenant"| - string name = "Captain"| - string name = "Major"| - string name = "Colonel"| - string name = "General"| - string name = "Marshall"| - string name = "Bomb"|
| - char symbol = 'F' | - char symbol = 'S' | - char symbol = '9' | - char symbol = '8' | - char symbol = '7' | - char symbol = '6' | - char symbol = '5' | - char symbol = '4' | - char symbol = '3' | - char symbol = '2' | - char symbol = '1' | - char symbol = 'B' |
| - int rank = 0 | - int rank = 1 | - int rank = 2 | - int rank = 3 | - int rank = 4 | - int rank = 5 | - int rank = 6 | - int rank = 7 | - int rank = 8 | - int rank = 9 | - int rank = 10 | - int rank = 11 |
| - int movement = 0 | - int movement = 1 | - int movement = 10 | - int movement = 1 | - int movement = 1 | - int movement = 1 | - int movement = 1 | - int movement = 1 | - int movement = 1 | - int movement = 1 | - int movement = 1 | - int movement = 0 |

* ___Procedural Flow Diagram___ The logical flow of your program

| Program Begins | -> 
| Introduction Desplayed | -> 
| Press Any Button To Start | -> 
| Game initialized And Board Created | -> 
| Players Place Pieces | ->
| Turn Starts | ->
| Pieces Move/Attack | ->
< Is A Flag Captured? > if no, return to "Turn Starts", if yes, -> 
| Game Ends | ->
| Winner Announced |

* ___Anticipated challenges___ and how will you address them?
    * Updating the board to display each side piece ranks, while obscuring their opponents
        -Use of the print(red/blue) functions to print the correct board for each player
    * Moving pieces
        -Use of a 2d array to hold piece placement
    * Action Validation
        -Use of the validate functions to perform tests on each action before it is performed

* ___Project Management Plan___
  * Name __individual group member tasks/responsibilities__.
    Split up the tasks and implementation into portions per group member.
  * Corey Bronson - Main() and Game()
  * Andrew Platner - Piece() and its children
  * Cadyn Maddocks - Board()
  * Garrett Moody - Board()
  -
  * __Timeline__ of individual and group delivery dates.
  * Week 7 - Function outlines and a runnable program, albeit one without functionality
  * Week 8 - Fully operational functions, though not without bugs
  * Week 9 - Bug fixes and polish
