#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <curses.h>
#include "Obstacle.h"
#include <random>
#pragma once

class Obstacles {
    public:
        Obstacles();
        Obstacles(int _difficulty, int _LX, int _LY, int _RX, int _RY);
        void draw(WINDOW* win);
        void add_obstacle(Obstacle tmp);
        void move();
        void add(int MIN);
        int hit(int bx, int by);
        mt19937 rng;
        int LX, LY, RX, RY, difficulty;
        vector<Obstacle> obstacles;
        Obstacle generate_obstacle();
        void clear_obstacle();
        vector<pair<int, int>> get_positions();
    private:
};
