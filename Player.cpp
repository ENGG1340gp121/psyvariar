#include <bits/stdc++.h>
#include <ncurses.h>
#include "Player.h"
using namespace std;
Player::Player(){
    HP = 0, x = 0, y = 0, weapon = 0, sym = '#';
}
Player::Player(int _HP, int _x, int _y, int _weapon, char _sym){
    HP = _HP, x = _x, y = _y, weapon = _weapon, sym = _sym;
}
void Player::keep_inside(){

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