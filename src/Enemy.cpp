#include <bits/stdc++.h>
#include <curses.h>
#include "Enemy.h"

using namespace std;


Enemy::Enemy(){
    Enemy_figure[0].push_back(Enemy_char('<', 0, 2));
    Enemy_figure[0].push_back(Enemy_char('<', 1, 0));
    Enemy_figure[0].push_back(Enemy_char('=', 1, 1));
    Enemy_figure[0].push_back(Enemy_char('(', 1, 2));
    Enemy_figure[0].push_back(Enemy_char('<', 2, 2));
}
Enemy::Enemy(int _x, int _y, int _level, int _LX, int _LY, int _RX, int _RY){
    x = _x, y = _y, level = _level;
    LX = _LX, LY = _LY, RX = _RX, RY = _RY;
}
bool Enemy::is_inside(){
    for(Enemy_char& c : Enemy_figure[level]){
        int X = x + c.x, Y = y + c.y;
        if(X < LX || X > RX || Y < LY || Y > RY) return 0;
    }
    return 1;
}
void Enemy::move(){
    for(Enemy_char& c : Enemy_figure[level]){
        c.y--;
    }
}
void Enemy::draw(WINDOW* win){
    for(Enemy_char& c : Enemy_figure[level]){
        int X = x + c.x, Y = y + c.y;
        if(X < LX || X > RX || Y < LY || Y > RY) continue;
        mvwaddch(win, X, Y, c.sym);
    }
}