#include <bits/stdc++.h>
#include <curses.h>
#include "Enemy.h"

using namespace std;

Enemy::Enemy(){
    clock = 0;
}
Enemy::Enemy(int _x, int _y, int _level, int _LX, int _LY, int _RX, int _RY, int _HP){
    Enemy_figure[0].push_back(Enemy_char('<', 0, 2));
    Enemy_figure[0].push_back(Enemy_char('<', 1, 0));
    Enemy_figure[0].push_back(Enemy_char('=', 1, 1));
    Enemy_figure[0].push_back(Enemy_char('(', 1, 2));
    Enemy_figure[0].push_back(Enemy_char('<', 2, 2));
    Gun[0].push_back(Enemy_char('<', 0, 2));
    Gun[0].push_back(Enemy_char('<', 2, 2));
    x = _x, y = _y, level = _level;
    LX = _LX, LY = _LY, RX = _RX, RY = _RY;
	HP = 1, clock = 0, clock_shoot = 0;
}
bool Enemy::alive() {
    if(HP <= 0) return false;
    for(Enemy_char& c : Enemy_figure[level]){
        int X = x + c.x, Y = y + c.y;
        if(LX <= X && X <= RX && Y >= LY)
            return true;
    }
    return false;
}

void Enemy::move(int CLK){
    clock++;
    if (clock >= CLK){
        clock = 0;
        y--;
    }
}
void Enemy::draw(WINDOW* win){
    for(Enemy_char& c : Enemy_figure[level]){
        int X = x + c.x, Y = y + c.y;
        if(X < LX || X > RX || Y < LY || Y > RY) continue;
        mvwaddch(win, X, Y, c.sym);
    }
}
void Enemy::decrease_HP(int x) {
    HP -= x;
}
void Enemy::shoot(int velocity){
//    ofstream f;    
//    f.open("1.txt", ios::app);
    clock_shoot++;
//    f<<clock_shoot<<" "<<CLK<<endl;
    if (clock_shoot >= velocity){
        clock_shoot = 0;
        for(Enemy_char&  gun : Gun[level]){
            bullets.push_back(Bullet(x + gun.x, y + gun.y, LX, LY, RX, RY, '*'));
        }
    }
}