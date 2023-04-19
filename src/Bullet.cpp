#include <bits/stdc++.h>
#include <curses.h>
#include "Bullet.h"
using namespace std;
Bullet::Bullet(int _x, int _y, int _LX, int _LY, int _RX, int _RY, char _sym){
    LX = _LX, LY = _LY, RX = _RX, RY = _RY;
    x = _x, y = _y;
    sym = _sym;
    clock = 0;
}
bool Bullet::is_inside(){
    return LX <= x && x <= RX && LY <= y && y <= RY;
}
void Bullet::move(){
    if(++clock == CLK){
        clock = 0;
        y++;
    }
}
void Bullet::draw(WINDOW* win){
    mvwaddch(win, x, y, sym);
}