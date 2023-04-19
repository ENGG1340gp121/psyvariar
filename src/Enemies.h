#include <bits/stdc++.h>
#include <curses.h>
#include "Enemy.h"
class Enemies {
    public:
        Enemies();
        void draw(WINDOW* win);
        void add_enemy(Enemy tmp);
        void clear_enemy();
    private:
        int LX, LY, RX, RY;
        vector<Enemy> enemies;
};