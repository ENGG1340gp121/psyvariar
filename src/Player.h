#include <bits/stdc++.h>
#include <curses.h>
#include "Bullet.h"
using namespace std;
class Player{
    public:
        struct plane_char{
            char sym;
            int x,y;
            plane_char(char _sym, int _x, int _y){
                sym = _sym;
                x = _x;
                y = _y;
            }
        };
        int HP, Level, weapon, x, y;
        int LX, LY, RX, RY;
        int atk[2];
        vector<plane_char> Plane[2];
        vector<plane_char> Gun[2];
        vector<Bullet> Bullets;
        Player();
        Player(int _LX, int _LY, int _RX, int _RY, int _Level, int _HP, int _x, int _y);
        bool check_inside();
        void move(int c);
        void move_left();
        void move_right();
        void move_down();
        void move_up();
        void shoot();
        void get_damage(int value);
        void draw(WINDOW* win);
    private:
};