#include <bits/stdc++.h>
#include <curses.h>
#include "Enemies.h"

Enemies::Enemies(){}

void Enemies::add_enemy(Enemy tmp){
    enemies.push_back(tmp);
}

void Enemies::clear_enemy(){
    vector<Enemy> new_enemies;
    for(Enemy e : enemies){
        if(e.is_inside())
            new_enemies.push_back(e);
    }
    swap(new_enemies, enemies);
}

void Enemies::draw(WINDOW* win){
    for(Enemy e : enemies){
            e.draw(win);
    }
}