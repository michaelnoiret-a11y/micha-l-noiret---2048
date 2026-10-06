#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Board::Board()
{
    scoreGained = 0;
    initialize();
}

int Board::getScoreGained()
{
    return scoreGained;
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

    // Ligne horizontale
    cout << "+-------+-------+-------+-------+\n";

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "|";

            if (grid[i][j] == 0)
            {
                cout << "       ";
            }
            else
            {
                cout << "  " << grid[i][j] << "   ";
            }
        }

        cout << "|\n";

        cout << "+-------+-------+-------+-------+\n";
    }
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
    scoreGained = 0;
    bool moved = false;

    for (int i = 0; i < 4; i++)
    {
        // 1. Faire glisser les tuiles vers la gauche
        for (int k = 0; k < 3; k++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[i][j] == 0 && grid[i][j + 1] != 0)
                {
                    grid[i][j] = grid[i][j + 1];
                    grid[i][j + 1] = 0;

                    moved = true;
                }
            }
        }

        // 2. Une case fusionnée ne pourra pas refusionner
        bool merged[4] = {false, false, false, false};

        // 3. Fusionner de gauche à droite
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] != 0 &&
                grid[i][j] == grid[i][j + 1] &&
                !merged[j])
            {
                grid[i][j] *= 2;
                scoreGained += grid[i][j];
                grid[i][j + 1] = 0;

                merged[j] = true;

                moved = true;
            }
        }

        // 4. Faire glisser une nouvelle fois
        for (int k = 0; k < 3; k++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[i][j] == 0 && grid[i][j + 1] != 0)
                {
                    grid[i][j] = grid[i][j + 1];
                    grid[i][j + 1] = 0;

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
        // 1. Faire glisser les tuiles vers la droite
        for (int k = 0; k < 3; k++)
        {
            for (int j = 3; j > 0; j--)
            {
                if (grid[i][j] == 0 && grid[i][j - 1] != 0)
                {
                    grid[i][j] = grid[i][j - 1];
                    grid[i][j - 1] = 0;

                    moved = true;
                }
            }
        }

        // 2. Tableau indiquant les cases déjà fusionnées
        bool merged[4] = {false, false, false, false};

        // 3. Fusionner de droite à gauche
        for (int j = 3; j > 0; j--)
        {
            if (grid[i][j] != 0 &&
                grid[i][j] == grid[i][j - 1] &&
                !merged[j])
            {
                grid[i][j] *= 2;
                scoreGained += grid[i][j];
                grid[i][j - 1] = 0;

                merged[j] = true;

                moved = true;
            }
        }

        // 4. Faire glisser une nouvelle fois
        for (int k = 0; k < 3; k++)
        {
            for (int j = 3; j > 0; j--)
            {
                if (grid[i][j] == 0 && grid[i][j - 1] != 0)
                {
                    grid[i][j] = grid[i][j - 1];
                    grid[i][j - 1] = 0;

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
        // 1. Faire glisser les tuiles vers le haut
        for (int k = 0; k < 3; k++)
        {
            for (int i = 0; i < 3; i++)
            {
                if (grid[i][j] == 0 && grid[i + 1][j] != 0)
                {
                    grid[i][j] = grid[i + 1][j];
                    grid[i + 1][j] = 0;

                    moved = true;
                }
            }
        }

        // 2. Cases déjà fusionnées
        bool merged[4] = {false, false, false, false};

        // 3. Fusionner de haut en bas
        for (int i = 0; i < 3; i++)
        {
            if (grid[i][j] != 0 &&
                grid[i][j] == grid[i + 1][j] &&
                !merged[i])
            {
                grid[i][j] *= 2;
                scoreGained += grid[i][j];
                grid[i + 1][j] = 0;

                merged[i] = true;

                moved = true;
            }
        }

        // 4. Faire glisser à nouveau
        for (int k = 0; k < 3; k++)
        {
            for (int i = 0; i < 3; i++)
            {
                if (grid[i][j] == 0 && grid[i + 1][j] != 0)
                {
                    grid[i][j] = grid[i + 1][j];
                    grid[i + 1][j] = 0;

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
        // 1. Faire glisser les tuiles vers le bas
        for (int k = 0; k < 3; k++)
        {
            for (int i = 3; i > 0; i--)
            {
                if (grid[i][j] == 0 && grid[i - 1][j] != 0)
                {
                    grid[i][j] = grid[i - 1][j];
                    grid[i - 1][j] = 0;

                    moved = true;
                }
            }
        }

        // 2. Cases déjà fusionnées
        bool merged[4] = {false, false, false, false};

        // 3. Fusionner de bas en haut
        for (int i = 3; i > 0; i--)
        {
            if (grid[i][j] != 0 &&
                grid[i][j] == grid[i - 1][j] &&
                !merged[i])
            {
                grid[i][j] *= 2;
                scoreGained += grid[i][j];
                grid[i - 1][j] = 0;

                merged[i] = true;

                moved = true;
            }
        }

        // 4. Faire glisser à nouveau
        for (int k = 0; k < 3; k++)
        {
            for (int i = 3; i > 0; i--)
            {
                if (grid[i][j] == 0 && grid[i - 1][j] != 0)
                {
                    grid[i][j] = grid[i - 1][j];
                    grid[i - 1][j] = 0;

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