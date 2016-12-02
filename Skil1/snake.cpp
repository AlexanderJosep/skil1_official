#include "snake.h"

using namespace std;

const char keys[8] = {'W', 'A', 'S', 'D', 'w', 'a', 's', 'd'};

Snake::Snake(Console &c) {
    short gridSize = getGridSize(c, "Grid size(3-50):");
    grid.setGrid(gridSize);
    grid.initialize();
}

short Snake::getGridSize(Console &c, string s) {
    short in;
    while(true) {
        cout << s;
        cin >> in;
        if(in < 3 || in > 50) {
            c.println("Please select a grid size between 3 - 50.");
            c.clearBuffer();
            continue;
        }
        break;
    }
    return in;
}

int Snake::getDirection(Console &c) {
    cout << "Enter key: ";
    char in;
    cin >> in;
    for(int i = 0; i < 4; i++) {
        if(keys[i] == in || keys[i + 4] == in) {
            return i;
        }
    }
    c.println("Invalid key, use WASD.");
    c.clearBuffer();
    return getDirection(c);
}

void Snake::processSnake(Console &c) {
    while(true) {
        grid.print(c);
        if(!grid.update(c, getDirection(c))) {
            if(grid.hasWon()) {
                 c.println("You WIN. Points: " + to_string(grid.getSnakeSize() - 3));
            } else {
                 c.println("You lose. Points: " + to_string(grid.getSnakeSize() - 3));
            }
            break;
        }
    }
}
