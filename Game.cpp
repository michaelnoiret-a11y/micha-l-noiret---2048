#include "Game.h"
#include <iostream>

using namespace std;

Game::Game()
{
    score = 0;
}

void Game::display()
{
    board.display();

    cout << "Score : " << score << endl;

    cout << "\n";
    cout << "Z = Haut" << endl;
    cout << "S = Bas" << endl;
    cout << "Q = Gauche" << endl;
    cout << "D = Droite" << endl;
    cout << "X = Quitter" << endl;
}

void Game::handleInput(char input)
{
    bool moved = false;

    if (input == 'q' || input == 'Q')
    {
        moved = board.moveLeft();
    }
    else if (input == 'd' || input == 'D')
    {
        moved = board.moveRight();
    }
    else if (input == 'z' || input == 'Z')
    {
        moved = board.moveUp();
    }
    else if (input == 's' || input == 'S')
    {
        moved = board.moveDown();
    }

    if (moved)
    {
        score += board.getScoreGained();
        board.addTile();
    }
}

void Game::start()
{
    char input;

    while (true)
    {
        display();

        if (board.hasWon())
        {
            cout << "\n🎉 Tu as atteint 2048 !\n";
            break;
        }

        if (board.isGameOver())
        {
            cout << "\n💀 GAME OVER !\n";
            break;
        }

        cout << "\nTon choix : ";
        cin >> input;

        if (input == 'x' || input == 'X')
        {
            cout << "\nAu revoir !\n";
            break;
        }

        handleInput(input);
    }
}