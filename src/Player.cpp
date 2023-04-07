#include <bits/stdc++.h>
#include <ncurses.h>
#include "Player.h"
using namespace std;
Player::Player(){}
Player::Player(int _LX, int _LY, int _RX, int _RY){
    LX = _LX, LY = _LY, RX = _RX, RY = _RY;
    HP = 0, x = 0, y = 0, weapon = 0, sym = '#';
}
Player::Player(int _HP, int _x, int _y, int _LX, int _LY, int _RX, int _RY , int _weapon, char _sym){
    LX = _LX, LY = _LY, RX = _RX, RY = _RY;
    HP = _HP, x = _x, y = _y, weapon = _weapon, sym = _sym;
}
void Player::keep_inside(){
    x = max(x, LX), x = min(x, RX);
    y = max(y, LY), y = min(y, RY);
}
void Player::move_left(){
    y--;
    keep_inside();
}
void Player::move_right(){
    y++;
    keep_inside();
}
void Player::move_down(){
    x++;
    keep_inside();
}
void Player::move_up(){
    x--;
    keep_inside();
}

void Player::draw(WINDOW* win){
    mvwaddch(win, x, y, sym);
}