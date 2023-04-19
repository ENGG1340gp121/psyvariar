#include <bits/stdc++.h>
#include <curses.h>

using namespace std;

class Enemy {
    public:
        struct Enemy_char{
            int x, y;
            char sym;
            Enemy_char(char _sym, int _x, int _y){
                sym = _sym, x = _x, y = _y;
            }
        };
        int LX, LY, RX, RY;
        int x, y, HP, level;
        vector<Enemy_char> Enemy_figure[3];
        Enemy();
        Enemy(int _x, int _y, int _level, int _LX, int _LY, int _RX, int _RY);
        bool is_inside();
        bool alive();
        void move();
        void draw(WINDOW* win);
        void decrease_HP(int x);
    private:
};