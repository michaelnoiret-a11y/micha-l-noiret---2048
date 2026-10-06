#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
    int grid[4][4];
    int scoreGained;

public:
    Board();

    void initialize();
    void display();

    void addTile();

    bool moveLeft();
    bool moveRight();
    bool moveUp();
    bool moveDown();

    int getScoreGained();

    bool isGameOver();
    bool hasWon();
};

#endif