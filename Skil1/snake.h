#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <iostream>
#include <string>
#include "snakegrid.h"
#include "console.h"

using namespace std;

class Snake {
public:
    Snake(Console &c);
    void processSnake(Console &c); // processes the snake game
private:
    short getGridSize(Console &c, string s); // gets user input grid size
    int getDirection(); // get next directon
    SnakeGrid grid;
};

#endif // SNAKE_H
