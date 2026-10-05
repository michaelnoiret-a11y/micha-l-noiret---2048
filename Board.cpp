#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Board::Board()
{
    initialize();
}

void Board::initialize()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            grid[i][j] = 0;
        }
    }

    srand(time(nullptr));

    addTile();
    addTile();
}

void Board::display()
{
    cout << "\n";

    for (int i = 0; i < 4; i++)
    {
        cout << "+----+----+----+----+\n";

        for (int j = 0; j < 4; j++)
        {
            if (grid[i][j] == 0)
                cout << "|    ";
            else
                cout << "|  " << grid[i][j] << " ";
        }

        cout << "|\n";
    }

    cout << "+----+----+----+----+\n";
}

void Board::addTile()
{
    int emptyCells[16][2];
    int count = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (grid[i][j] == 0)
            {
                emptyCells[count][0] = i;
                emptyCells[count][1] = j;
                count++;
            }
        }
    }

    if (count == 0)
        return;

    int randomCell = rand() % count;

    int row = emptyCells[randomCell][0];
    int column = emptyCells[randomCell][1];

    int value = (rand() % 10 == 0) ? 4 : 2;

    grid[row][column] = value;
}

bool Board::moveLeft()
{
    bool moved = false;

    for (int i = 0; i < 4; i++)
    {
        // Faire glisser les cases vers la gauche
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (grid[i][k] == 0 && grid[i][k + 1] != 0)
                {
                    grid[i][k] = grid[i][k + 1];
                    grid[i][k + 1] = 0;
                    moved = true;
                }
            }
        }

        // Fusionner les cases identiques
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] != 0 &&
                grid[i][j] == grid[i][j + 1])
            {
                grid[i][j] *= 2;
                grid[i][j + 1] = 0;

                moved = true;
            }
        }

        // Refaire glisser après les fusions
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (grid[i][k] == 0 && grid[i][k + 1] != 0)
                {
                    grid[i][k] = grid[i][k + 1];
                    grid[i][k + 1] = 0;
                    moved = true;
                }
            }
        }
    }

    return moved;
}

bool Board::moveRight()
{
    bool moved = false;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 3; j > 0; j--)
        {
            for (int k = 3; k > 0; k--)
            {
                if (grid[i][k] == 0 && grid[i][k - 1] != 0)
                {
                    grid[i][k] = grid[i][k - 1];
                    grid[i][k - 1] = 0;
                    moved = true;
                }
            }
        }

        for (int j = 3; j > 0; j--)
        {
            if (grid[i][j] != 0 &&
                grid[i][j] == grid[i][j - 1])
            {
                grid[i][j] *= 2;
                grid[i][j - 1] = 0;

                moved = true;
            }
        }

        for (int j = 3; j > 0; j--)
        {
            for (int k = 3; k > 0; k--)
            {
                if (grid[i][k] == 0 && grid[i][k - 1] != 0)
                {
                    grid[i][k] = grid[i][k - 1];
                    grid[i][k - 1] = 0;
                    moved = true;
                }
            }
        }
    }

    return moved;
}

bool Board::moveUp()
{
    bool moved = false;

    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (grid[k][j] == 0 && grid[k + 1][j] != 0)
                {
                    grid[k][j] = grid[k + 1][j];
                    grid[k + 1][j] = 0;
                    moved = true;
                }
            }
        }

        for (int i = 0; i < 3; i++)
        {
            if (grid[i][j] != 0 &&
                grid[i][j] == grid[i + 1][j])
            {
                grid[i][j] *= 2;
                grid[i + 1][j] = 0;

                moved = true;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (grid[k][j] == 0 && grid[k + 1][j] != 0)
                {
                    grid[k][j] = grid[k + 1][j];
                    grid[k + 1][j] = 0;
                    moved = true;
                }
            }
        }
    }

    return moved;
}

bool Board::moveDown()
{
    bool moved = false;

    for (int j = 0; j < 4; j++)
    {
        for (int i = 3; i > 0; i--)
        {
            for (int k = 3; k > 0; k--)
            {
                if (grid[k][j] == 0 && grid[k - 1][j] != 0)
                {
                    grid[k][j] = grid[k - 1][j];
                    grid[k - 1][j] = 0;
                    moved = true;
                }
            }
        }

        for (int i = 3; i > 0; i--)
        {
            if (grid[i][j] != 0 &&
                grid[i][j] == grid[i - 1][j])
            {
                grid[i][j] *= 2;
                grid[i - 1][j] = 0;

                moved = true;
            }
        }

        for (int i = 3; i > 0; i--)
        {
            for (int k = 3; k > 0; k--)
            {
                if (grid[k][j] == 0 && grid[k - 1][j] != 0)
                {
                    grid[k][j] = grid[k - 1][j];
                    grid[k - 1][j] = 0;
                    moved = true;
                }
            }
        }
    }

    return moved;
}

bool Board::isGameOver()
{
    // S'il reste une case vide,
    // le joueur peut encore jouer.
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (grid[i][j] == 0)
                return false;
        }
    }

    // Vérifier les lignes
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] == grid[i][j + 1])
                return false;
        }
    }

    // Vérifier les colonnes
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (grid[i][j] == grid[i + 1][j])
                return false;
        }
    }

    return true;
}

bool Board::hasWon()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (grid[i][j] >= 2048)
                return true;
        }
    }

    return false;
}