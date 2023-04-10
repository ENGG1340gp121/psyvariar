#include <bits/stdc++.h>
#include <curses.h>

using namespace std;

class Enemy {
    public:
        Enemy(int _x, int _y, int _LX, int _LY, int _RX, int _RY, char _sym);
        bool is_inside();
        bool alive();
        void move();
        void draw(WINDOW* win);
    private:
        int LX, LY, RX, RY, x, y;
        char sym;
};