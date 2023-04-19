#include <bits/stdc++.h>
#include <curses.h>
#include "Enemy.h"
#include <random>
class Enemies {
    public:
        Enemies();
        Enemies(int _LX, int _LY, int _RX, int _RY);
        void draw(WINDOW* win);
        void add_enemy(Enemy tmp);
        void move();
        void add(int MIN_ENEMIES);
    private:
        mt19937 rng;
        int LX, LY, RX, RY;
        vector<Enemy> enemies;
        Enemy generate_enemy();
        void clear_enemy();
};
