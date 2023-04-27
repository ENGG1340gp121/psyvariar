#include <bits/stdc++.h>
#include <curses.h>
#include "Enemy.h"
#include <random>
#pragma once

class Enemies {
    public:
        Enemies();
        Enemies(int _difficulty, int _LX, int _LY, int _RX, int _RY);
        void draw(WINDOW* win);
        void add_enemy(Enemy tmp);
        void move();
        void add(int MIN_ENEMIES);
        void shoot(int velocity);
        int hit(int bx, int by, int atk);
        mt19937 rng;
        int LX, LY, RX, RY, difficulty;
        vector<Enemy> enemies;
        Enemy generate_enemy();
        void clear_enemy();
    private:
};
