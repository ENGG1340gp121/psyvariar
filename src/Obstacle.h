#include <bits/stdc++.h>
#include <curses.h>
#pragma once
using namespace std;

class Obstacle {
    public:
        struct Obstacle_char{
            int x, y;
            char sym;
            Obstacle_char(char _sym, int _x, int _y){
                sym = _sym, x = _x, y = _y;
            }
        };
        Obstacle();
        Obstacle(int _difficulty, int _x, int _y, int _level, int _LX, int _LY, int _RX, int _RY);
        bool is_inside();
        bool alive();
        void move(int velocity);
        void draw(WINDOW* win);
        int LX, LY, RX, RY, difficulty;
        int x, y, level, clock;
        vector<Obstacle_char> Obstacle_figure[3];
    private:
};