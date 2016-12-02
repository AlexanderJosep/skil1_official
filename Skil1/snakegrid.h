#ifndef SNAKEGRID_H
#define SNAKEGRID_H
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "console.h"

using namespace std;

class SnakeGrid {
public:
    SnakeGrid();
    void initialize(); // initializes the grid
    bool update(Console &c, int dir); // updates the snake with the next direction
    bool hasWon(); // check if the player won
    int getSnakeSize(); // gets snake size for calculating points
    void setGrid(int size); // sets grid size
    void print(Console &c); // prints the snake game out
private:
    bool updateSnake(Console &c, int dir); // updates the snakes position and checks for collision and walking out of grid
    void pushSnake(); // pushes the snake onto the grid
    void pushCandy(); // pushes the candy onto the grid
    void setRandomCandy(); // sets candy to a random pos
    void resetGrid(); // resets the grid
    void setColor(unsigned short col); // sets console color
    short** grid;
    short gridSize;
    short candyX;
    short candyY;
    vector<int> snakeX;
    vector<int> snakeY;
    int oldDirection;
};

#endif // SNAKEGRID_H
