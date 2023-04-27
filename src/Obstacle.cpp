#include <bits/stdc++.h>
#include <curses.h>
#include "Obstacle.h"

using namespace std;

Obstacle::Obstacle(){

}
Obstacle::Obstacle(int _difficulty, int _x, int _y, int _level, int _LX, int _LY, int _RX, int _RY){
    Obstacle_figure[0].push_back(Obstacle_char('#', 0, 0));
    Obstacle_figure[0].push_back(Obstacle_char('#', 0, 1));
    Obstacle_figure[0].push_back(Obstacle_char('#', 0, 2));
    Obstacle_figure[0].push_back(Obstacle_char('#', 1, 1));
    Obstacle_figure[0].push_back(Obstacle_char('#', 1, 0));
    Obstacle_figure[0].push_back(Obstacle_char('#', 1, 2));
    Obstacle_figure[0].push_back(Obstacle_char('#', 2, 1));
    Obstacle_figure[0].push_back(Obstacle_char('#', 2, 0));
    Obstacle_figure[0].push_back(Obstacle_char('#', 2, 2));
    x = _x, y = _y, level = _level;
    LX = _LX, LY = _LY, RX = _RX, RY = _RY;
    difficulty = _difficulty;
    clock = 0;
}

// Returns whether the Obstacle is alive
// The Obstacle is dead if it will never appear in frame
bool Obstacle::alive() {
    for(Obstacle_char& c : Obstacle_figure[level]){
        int X = x + c.x, Y = y + c.y;
        if(LX <= X && X <= RX && Y >= LY)
            return true;
    }
    return false;
}

// Update position (y-- every "velocity" cycles)
void Obstacle::move(int velocity){
    clock++;
    if (clock >= velocity){
        clock = 0;
        y--;
    }
}

// Draw the object
// Only draw the part that is in the frame
void Obstacle::draw(WINDOW* win){
    for(Obstacle_char& c : Obstacle_figure[level]){
        int X = x + c.x, Y = y + c.y;
        if(X < LX || X > RX || Y < LY || Y > RY) continue;
        mvwaddch(win, X, Y, c.sym);
    }
}