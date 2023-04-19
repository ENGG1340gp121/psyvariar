#include <bits/stdc++.h>
#include <curses.h>
#include "Enemies.h"

Enemies::Enemies(){}
Enemies::Enemies(int _difficulty, int _LX, int _LY, int _RX, int _RY){
	LX = _LX, LY = _LY, RX = _RX, RY = _RY;
    difficulty = _difficulty;
}

void Enemies::add_enemy(Enemy tmp){
    enemies.push_back(tmp);
}

void Enemies::clear_enemy(){
    vector<Enemy> new_enemies;
    for(Enemy& e : enemies) {
        if(e.alive())
            new_enemies.push_back(e);
    }
    swap(new_enemies, enemies);
}

void Enemies::draw(WINDOW* win){
    for(Enemy& e: enemies) {
        e.draw(win);
    }
}

void Enemies::move() {
    for(Enemy& e:enemies) {
        e.move();
    }
    clear_enemy();
}

Enemy Enemies::generate_enemy() {
    int x = rng() % (RX - LX + 1) + LX;
    int y = rng() % (RY - LY + 1) + RY + 1;
    int level = 0;
    return Enemy(x, y, level, LX, LY, RX, RY);
}

void Enemies::add(int MIN_ENEMIES) {
    while(int(enemies.size()) < MIN_ENEMIES) {
        enemies.push_back(generate_enemy());
    }
}

bool Enemies::hit(int bx, int by) {

}