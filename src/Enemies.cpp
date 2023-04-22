#include <bits/stdc++.h>
#include <curses.h>
#include "Enemies.h"
#include "Enemy.h"

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
    for(Enemy& e: Enemies::enemies){
        for(Bullet b : e.bullets){
            b.draw(win);
        }
        e.draw(win);
    }
}

void Enemies::move() {
    for(Enemy& e : enemies) {
        e.move(5);
    }
    clear_enemy();
}

Enemy Enemies::generate_enemy() {
    int x = rng() % (RX - LX + 1) + LX;
    int y = rng() % (RY - LY + 1) + RY + 1;
    int level = 0;
    return Enemy(x, y, level, LX, LY, RX, RY, 5);
}

void Enemies::add(int MIN_ENEMIES) {
    while(int(enemies.size()) < MIN_ENEMIES) {
        enemies.push_back(generate_enemy());
    }
}

bool Enemies::hit(int bx, int by, int atk) {
    bool hit_flag = 0;
    for(Enemy& e : enemies){
        for(Enemy::Enemy_char& t : e.Enemy_figure[e.level])
            if(e.x +  t.x == bx && e.y +  t.y == by){
                e.decrease_HP(atk);
                hit_flag = 1;
            }
        vector<Bullet> bullet_alive;
        for(Bullet& b : e.bullets){
            if(b.x == bx && b.y == by){
                hit_flag = 1;
            }
            else if (b.is_inside()){
                bullet_alive.push_back(b);
            }
        }
        swap(bullet_alive, e.bullets);
    }
    return hit_flag;
}