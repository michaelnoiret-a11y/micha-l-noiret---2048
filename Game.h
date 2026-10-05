#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game
{
private:
    Board board;
    int score;

public:
    Game();

    void start();
    void display();
    void handleInput(char input);
};

#endif