#include <bits/stdc++.h>
#include <curses.h>
#include "Enemies.h"
Enemies::Enemies(int _LX, int _LY, int _RX, int _RY){
    LX = _LX, LY = _LY, RX = _RX, RY = _RY;
}

void Enemies::add_enemy(int x, int y, char sym) {
    enemies.emplace_back(x, y, LX, LY, RX, RY, sym);
}

void Enemies::draw(WINDOW* win) {
    for(Enemy e:enemies) {
        if(e.is_inside()) {
            e.draw(win);
        }
    }
}