#include <bits/stdc++.h>
#include <ncurses.h>
#include "Player.h"
#include "Bullet.h"
using namespace std;
Player::Player(){

}
Player::Player(int _LX, int _LY, int _RX, int _RY, int _Level, int _HP, int _x, int _y){
    Plane[0].push_back(plane_char('>', 0, 0));
    Plane[0].push_back(plane_char('=', 0, 1));
    Plane[0].push_back(plane_char('-', 0, 2));
    Plane[0].push_back(plane_char(')', 1, 1));
    Plane[0].push_back(plane_char('+', 1, 2));
    Plane[0].push_back(plane_char('=', 1, 3));
    Plane[0].push_back(plane_char('>', 1, 4));
    Plane[0].push_back(plane_char('>', 2, 0));
    Plane[0].push_back(plane_char('=', 2, 1));
    Plane[0].push_back(plane_char('-', 2, 2));
    Gun[0].push_back(plane_char('-', 0, 2));
    Gun[0].push_back(plane_char('-', 2, 2));
    atk[0] = 1;
    MAX_HEAT[0]=5;
    LX = _LX, LY = _LY, RX = _RX, RY = _RY, Level = _Level, HP = _HP, x = _x, y = _y;
}
bool Player::check_inside(){
    for(plane_char& c : Plane[Level]){
        int X = x + c.x, Y = y + c.y;
        if(X > RX || X < LX || Y > RY || Y < LX) return 0;
    }
    return 1;
}
void Player::move_left(){
    // for(plane_char& c : Plane[Level]){
    //     c.y--;
    // }
    y--;
    if (!check_inside()){
        // for(plane_char& c : Plane[Level]){
        //     c.y++;
        // }
        y++;
    }
}
void Player::move_right(){
    /*
    for(plane_char& c : Plane[Level]){
        c.y++;
    }
    */
    y++;
    if (!check_inside()){
        // for(plane_char& c : Plane[Level]){
        //     c.y--;
        // }
        y--;
    }
}
void Player::move_down(){
/*
    for(plane_char& c : Plane[Level]){
        c.x++;
    }*/
	x++;
    if (!check_inside()){
    /*    for(plane_char& c : Plane[Level]){
            c.x--;
        }*/
		x--;
    }
	
}
void Player::move_up(){
    /*
    for(plane_char& c : Plane[Level]){
        c.x--;
    }
    */
    x--;
    if (!check_inside()){
        x++;
    }
}
void Player::move(int c){
    if(c == KEY_LEFT){
		Player::move_left();
	}
    else if(c == KEY_RIGHT){
        Player::move_right();
	}
    else if(c == KEY_UP){
		Player::move_up();
	}
    else if(c == KEY_DOWN) {
		Player::move_down();
	}
}
void Player::draw(WINDOW* win){
    for(plane_char& c : Plane[Level]){
        mvwaddch(win, x+c.x, y+c.y, c.sym);
    }
    for(Bullet& b : Bullets){
        mvwaddch(win, b.x, b.y, b.sym);
    }
}
bool Player::shoot(){
    if(gun_heat >= MAX_HEAT[Level]) return 0;
    gun_heat ++;
    for(plane_char& c : Gun[Level]){
        Bullets.push_back(Bullet(x+c.x, y+c.y, LX, LY, RX, RY, '-'));
    }
}
void Player::get_damage(int value){
    HP -= value;
}
void Player::gun_heat_annealing(){
    gun_heat--;
}

vector<pair<int, int>> Player::get_positions() {
    vector<pair<int, int>> ret;
    for(plane_char& t : Plane[Level]){
        ret.emplace_back(x + t.x, y + t.y);
    }
    return ret;
}