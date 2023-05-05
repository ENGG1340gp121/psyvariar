#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <curses.h>
#include "Bullet.h"
using namespace std;
// this function is used to initialize the bullet
// _x, _y are the initially coordinate of bullet
// _LX, _LY, _RX, _RY are the screen size
// _sym is the symbol of figure
Bullet::Bullet(int _x, int _y, int _LX, int _LY, int _RX, int _RY, char _sym){
    LX = _LX, LY = _LY, RX = _RX, RY = _RY;
    x = _x, y = _y;
    sym = _sym;
    clock = 0;
}
// this function is used to check whether a bullet is inside the screen
bool Bullet::is_inside(){
    return LX <= x && x <= RX && LY <= y && y <= RY;
}
// this function is used to move the bullet for one unit
// velocity is bullet's moving velocity
// direction means bullet moves from left or right
void Bullet::move(int velocity, int direction){
    clock++;
    if(clock >= velocity){
        clock = 0;
        y+=direction;
    }
}
// draw the bullet in screen
// win means where to draw
void Bullet::draw(WINDOW* win){
    if(is_inside()) {
        mvwaddch(win, x, y, sym);
    }
}