#include <bits/stdc++.h>
#include <ncurses.h>
using namespace std;
class Enemy{
    public:
        int LX, LY, RX, RY, x, y, clock;
        char sym;
        static const int CLK = 2;
        Enemy(int _x, int _y, int _LX, int _LY, int _RX, int _RY, char _sym);
        bool is_inside();
        bool alive();
        void move();
        void draw(WINDOW* win);
    private:
};