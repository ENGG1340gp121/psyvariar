#include <bits/stdc++.h>
#include <curses.h>
#include "Bullet.h"
#pragma once
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
        Enemy();
        Enemy(int _difficulty, int _x, int _y, int HP, int _level, int _LX, int _LY, int _RX, int _RY);
        bool is_inside();
        bool alive();
        void move(int velocity);
        void draw(WINDOW* win);
        void decrease_HP(int x);
        void shoot(int velocity);
        int LX, LY, RX, RY, difficulty;
        int x, y, HP, level, clock_shoot, clock;
        vector<Enemy_char> Enemy_figure[3];
        vector<Enemy_char> Gun[3];
        vector<Bullet> bullets;
    private:
};