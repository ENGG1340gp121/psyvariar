#include <bits/stdc++.h>
#include <curses.h>
using namespace std;
class Player{
    public:
        int HP, x, y, weapon, LX, LY, RX, RY; 
        char sym;
        Player();
        Player(int _LX, int _LY, int _RX, int _RY);
        Player(int _HP, int _x, int _y, int _LX, int _LY, int _RX, int _RY ,int _weapon, char _sym);
        void keep_inside();
        void move_left();
        void move_right();
        void move_down();
        void move_up();
        void draw(WINDOW* win);
    private:
};