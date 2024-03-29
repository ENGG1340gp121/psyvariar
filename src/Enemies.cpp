#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <algorithm>
#include <curses.h>
#include "Enemies.h"
#include "Enemy.h"
//Enemies.cpp is used to generate the enemies and draw them on the screen
//This is the constructor of the enemy
Enemies::Enemies(){}
// initiate the enemies
// _difficulty is to set the difficulty
// _LX, _LY, _RX, _RY are the screen size
Enemies::Enemies(int _difficulty, int _LX, int _LY, int _RX, int _RY){
	LX = _LX, LY = _LY, RX = _RX, RY = _RY;
    difficulty = _difficulty;
    rng = mt19937(time(0));
}
// Add an enemy tmp to the vector
void Enemies::add_enemy(Enemy tmp){
    enemies.push_back(tmp);
}

// Remove all dead enemies
void Enemies::clear_enemy(){
    vector<Enemy> new_enemies;
    for(Enemy& e : enemies) {
        if(e.alive() || e.bullets.size()>0)
            new_enemies.push_back(e);
    }
    swap(new_enemies, enemies);
}

// Draw all enemies
// win is a pointer to the WINDOW object
void Enemies::draw(WINDOW* win){
    vector<Enemy> tmp;
    for(Enemy& e: Enemies::enemies){
        e.draw(win);
        if(e.alive() || e.bullets.size()>0) tmp.push_back(e);
    }
    swap(enemies, tmp);
}

// Update the positions of all enemies and remove dead ones
void Enemies::move() {
    for(Enemy& e : enemies) {
        e.move(5);
    }
    clear_enemy();
}

// Generate an enemy thet is that is to the right of the frame
// returns the generated enemy
Enemy Enemies::generate_enemy() {
    srand(time(NULL));
    int x = rng() % (RX - LX + 1 - 2) + LX;
    int y = rng() % (RY - LY + 1 - 2) + RY + 1;
    int level = 0;
    return Enemy(difficulty, x, y, level, LX, LY, RX, RY, 5);
}

// Add new enemies until there are at least MIN_ENEMIES eneimes
void Enemies::add(int MIN_ENEMIES) {
	int alive_cnt = 0;
	for(auto&e:enemies) {
		if(e.alive()) {
			alive_cnt++;
		}
	}
    while(alive_cnt < MIN_ENEMIES) {
        enemies.push_back(generate_enemy());
		alive_cnt++;
    }
}

// Update the enemies and bullets if they are hit by a bullet (bx, by) that can do "atk" damages
// Returns whether the bullet hits somehting
int Enemies::hit(int bx, int by, int atk) {
    int hit_flag = 0;
    for(Enemy& e : enemies){
        for(Enemy::Enemy_char& t : e.Enemy_figure[e.level])
            if(e.x +  t.x == bx && e.y +  t.y == by){
                e.decrease_HP(atk);
                hit_flag = 2;
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

void Enemies::shoot(int velocity) {
    for(Enemy& e : enemies) {
        if (e.alive())
            e.shoot(velocity);
    }
}

// returns a vector that contains all the positions on the screen that is occupied by an enemy
vector<pair<int, int>> Enemies::get_positions() {
    vector<pair<int, int>> ret;
    for(Enemy& e : enemies){
        for(Enemy::Enemy_char& t : e.Enemy_figure[e.level]){
            ret.emplace_back(e.x + t.x, e.y + t.y);
        }
    }
    return ret;
}
