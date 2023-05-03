#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <curses.h>
#include "Obstacles.h"
#include "Obstacle.h"
//Obstacles.cpp is used to generate the obstacles and draw them on the screen
Obstacles::Obstacles(){}
Obstacles::Obstacles(int _difficulty, int _LX, int _LY, int _RX, int _RY){
	LX = _LX, LY = _LY, RX = _RX, RY = _RY;
    difficulty = _difficulty;
}

void Obstacles::add_obstacle(Obstacle tmp){
    obstacles.push_back(tmp);
}

// Remove all dead obstacles
void Obstacles::clear_obstacle(){
    vector<Obstacle> new_obstacles;
    for(Obstacle& e : obstacles) {
        if(e.alive())
            new_obstacles.push_back(e);
    }
    swap(new_obstacles, obstacles);
}

// Draw all obstacles
void Obstacles::draw(WINDOW* win){
    for(Obstacle& e: Obstacles::obstacles){
        e.draw(win);
    }
}

// Update the positions of all enemies and remove dead ones
void Obstacles::move() {
    for(Obstacle& e : obstacles) {
        e.move(5);
    }
    clear_obstacle();
}

// Generate an obstacle that is to the right of the frame
Obstacle Obstacles::generate_obstacle() {
    int x = rng() % (RX - LX + 1 - 2) + LX;
    int y = rng() % (RY - LY + 1 - 2) + RY + 1;
    int level = 0;
    return Obstacle(difficulty, x, y, level, LX, LY, RX, RY);
}

// Add new obstacles until there are at least MIN obstacles
void Obstacles::add(int MIN) {
    while(int(obstacles.size()) < MIN) {
        obstacles.push_back(generate_obstacle());
    }
}

// Update the enemies and bullets if they are hit by a bullet (bx, by)
// Returns whether the bullet hits something
int Obstacles::hit(int bx, int by) {
    int hit_flag = 0;
    for(Obstacle& e : obstacles){
        for(Obstacle::Obstacle_char& t : e.Obstacle_figure[e.level]) {
            if(e.x + t.x == bx && e.y +  t.y == by) {
                hit_flag = 2;
            }
        }
    }
    return hit_flag;
}

vector<pair<int, int>> Obstacles::get_positions() {
    vector<pair<int, int>> ret;
    for(Obstacle& e : obstacles){
        for(Obstacle::Obstacle_char& t : e.Obstacle_figure[e.level]){
            ret.emplace_back(e.x + t.x, e.y + t.y);
        }
    }
    return ret;
}
