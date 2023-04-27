#include <bits/stdc++.h>
#include <curses.h>
#include "Enemy.h"

using namespace std;

Enemy::Enemy(){
    clock = 0;
}
Enemy::Enemy(int _difficulty, int _x, int _y, int _level, int _LX, int _LY, int _RX, int _RY, int _HP){
    Enemy_figure[0].push_back(Enemy_char('<', 0, 2));
    Enemy_figure[0].push_back(Enemy_char('<', 1, 0));
    Enemy_figure[0].push_back(Enemy_char('=', 1, 1));
    Enemy_figure[0].push_back(Enemy_char('(', 1, 2));
    Enemy_figure[0].push_back(Enemy_char('<', 2, 2));
    Gun[0].push_back(Enemy_char('<', 0, 2));
    Gun[0].push_back(Enemy_char('<', 2, 2));
    x = _x, y = _y, level = _level;
    LX = _LX, LY = _LY, RX = _RX, RY = _RY;
    difficulty = _difficulty;
	HP = 1, clock = 0, clock_shoot = 0;
}

// Returns whether the enemy is alive
// The enemy is dead if HP <= 0 or will never appear in frame
bool Enemy::alive() {
    if(HP <= 0) return false;
    for(Enemy_char& c : Enemy_figure[level]){
        int X = x + c.x, Y = y + c.y;
        if(LX <= X && X <= RX && Y >= LY)
            return true;
    }
    return false;
}

// Update position (y-- every "velocity" cycles)
void Enemy::move(int velocity){
    clock++;
    if (clock >= velocity){
        clock = 0;
        y--;
    }
}

// Draw the plan and bullets
// Only draw the part that is in the frame
void Enemy::draw(WINDOW* win){
    if(HP >0){
        for(Enemy_char& c : Enemy_figure[level]){
            int X = x + c.x, Y = y + c.y;
            if(X < LX || X > RX || Y < LY || Y > RY) continue;
            mvwaddch(win, X, Y, c.sym);
        }
    }
    for(Bullet b : bullets){
        b.draw(win);
    }
}

void Enemy::decrease_HP(int x) {
    HP -= x;
}

// Update bullets (add one bullet every "velocity" cycles)
void Enemy::shoot(int velocity){
    for(Enemy_char& c : Enemy_figure[level]){
        int X = x + c.x, Y = y + c.y;
        if(X < LX || X > RX || Y < LY || Y > RY) return;
    }
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

vector<pair<int, int>> Enemy::get_positions() {
    vector<pair<int, int>> ret;
    for(Enemy_char& t : Enemy_figure[level]){
        ret.emplace_back(x + t.x, y + t.y);
    }
    return ret;
}
