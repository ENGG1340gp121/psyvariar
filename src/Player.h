#include <bits/stdc++.h>
#include <curses.h>
using namespace std;
class Player{
    public:
        int HP, x, y, weapon; 
        char sym;
        Player();
        Player(int _HP, int _x, int _y,int _weapon, char _sym);
        void keep_inside();
        void move_left();
        void move_right();
        void move_down();
        void move_up();
        void draw(WINDOW* win);
    private:
};