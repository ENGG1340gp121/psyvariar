#include <bits/stdc++.h>
#include <curses.h>

class Enemies {
    public:
        Enemies(int _LX, int _LY, int _RX, int _RY);
        void draw(WINDOW* win);
        void add_enemy(int x, int y, char sym);
    private:
        int LX, LY, RX, RY;
        vector<Enemy> enemies;
};