#include <bits/stdc++.h>
#include <curses.h>
#include "Enemy.h"

using namespace std;

Enemy::Enemy(int _x, int _y, int _LX, int _LY, int _RX, int _RY, char _sym){
    LX = _LX, LY = _LY, RX = _RX, RY = _RY;
    x = _x, y = _y;
    sym = _sym;
}
bool Enemy::is_inside(){
    return LX <= x && x <= RX && LY <= y && y <= RY;
}
bool Enemy::alive(){
    return y >= LY;
}
void Enemy::move(){
    y--;
}
void Enemy::draw(WINDOW* win){
    mvwaddch(win, x, y, sym);
}
