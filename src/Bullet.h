#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <curses.h>
using namespace std;
#pragma once
class Bullet{
	public:
        int LX, LY, RX, RY, x, y, clock;
        char sym;
        Bullet(int _x, int _y, int _LX, int _LY, int _RX, int _RY, char _sym);
        bool is_inside();
        void move(int velocity, int direction);
        void draw(WINDOW* win);
    private:
};