
#include "Board.h"

class Game {

    public:
        void initialize();
        void run();

    private:
        bool playerTurn = true;
        Board board;

};