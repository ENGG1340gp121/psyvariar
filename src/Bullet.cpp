#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
void Bullet::move(int velocity, int direction){
    clock++;
    if(clock >= velocity){
        clock = 0;
        y+=direction;
    }
}
void Bullet::draw(WINDOW* win){
    if(is_inside()) {
        mvwaddch(win, x, y, sym);
    }
}