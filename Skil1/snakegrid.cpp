#include "SnakeGrid.h"

using namespace std;

static int getRanInt(int size) {
    return rand() % size;
}

SnakeGrid::SnakeGrid()
{
    candyX = -1;
    candyY = -1;
}

void SnakeGrid::initialize() {
    for(int i = 0; i < 3; i++) {
        snakeX.push_back(0);
    }
    for(int i = 0; i < 3; i++) {
        snakeY.push_back(2 - i);
    }
    pushSnake();
    setRandomCandy();
    pushCandy();
    oldDirection = 3;
}

bool SnakeGrid::update(Console &c, int dir) {
    if((dir == 0 && oldDirection == 2) || (dir == 2 && oldDirection == 0) || (dir == 1 && oldDirection == 3) || (dir == 3 && oldDirection == 1)) {
        c.println("You can't move to that direction.");
        return true;
    }
    oldDirection = dir;
    resetGrid();
    if(!updateSnake(c, dir)) {
        return false;
    }
    pushSnake();
    pushCandy();
    return true;
}

bool SnakeGrid::hasWon() {
    for(int i = 0; i < gridSize; i++) {
        for(int j = 0; j < gridSize; j++) {
            if(grid[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

bool SnakeGrid::updateSnake(Console &c, int dir) {
    int offX = dir == 0 ? -1 : (dir == 2 ? 1 : 0);
    int offY = dir == 1 ? -1 : (dir == 3 ? 1 : 0);
    for(unsigned int i = 1; i < snakeX.size(); i++) {
        if(snakeX[0] + offX == snakeX[i] && snakeY[0] + offY == snakeY[i]) {
            c.println("Your snake collided with itself.");
            return false;
        }
    }
    int oldX = snakeX[snakeX.size() - 1];
    int oldY = snakeY[snakeY.size() - 1];
    for(unsigned int i = snakeX.size() - 1; i > 0; i--) {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }
    snakeX[0] = snakeX[0] + offX;
    snakeY[0] = snakeY[0] + offY;
    if(snakeX[0] == candyX && snakeY[0] == candyY) {
        snakeX.push_back(oldX);
        snakeY.push_back(oldY);
        pushSnake();
        if(hasWon()) {
            return false;
        }
        setRandomCandy();
        c.println("Ate candy!");
    }
    return !(snakeX[0] < 0 || snakeX[0] >= gridSize || snakeY[0] < 0 || snakeY[0] >= gridSize);
}

void SnakeGrid::pushSnake() {
    for(unsigned int i = 0; i < snakeX.size(); i++) {
        grid[snakeX[i]][snakeY[i]] = 1;
    }
}

void SnakeGrid::pushCandy() {
    grid[candyX][candyY] = 2;
}

void SnakeGrid::setRandomCandy() {
    do {
        candyX = getRanInt(gridSize);
        candyY = getRanInt(gridSize);
    } while(grid[candyX][candyY] == 1);
}

void SnakeGrid::setGrid(int size) {
    grid = new short*[size];
    for(int i = 0; i < size; i++) {
        grid[i] = new short[size];
        for(int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }
    gridSize = size;
}

void SnakeGrid::resetGrid() {
    for(int i = 0; i < gridSize; i++) {
        for(int j = 0; j < gridSize; j++) {
            grid[i][j] = 0;
        }
    }
}

int SnakeGrid::getSnakeSize() {
    return snakeX.size();
}

void SnakeGrid::setColor(unsigned short c) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void SnakeGrid::print(Console &c) {
     for(int i = 0; i < gridSize; i++) {
        for(int j = 0; j < gridSize; j++) {
            if(grid[i][j] == 1 || grid[i][j] == 2) {
                setColor(grid[i][j] == 1 ? 8 : 15);
            }
            string out = grid[i][j] == 0 ? "x" : (grid[i][j] == 1 ? "o" : "O");
            c.print(out + " ");
            if(grid[i][j] == 1 || grid[i][j] == 2) {
                setColor(7);
            }
        }
        c.newLine();
    }
    for(int i = 0; i < gridSize * 2; i++) {
        c.print("_");
    }
    c.newLine();
}
