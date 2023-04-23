#include <bits/stdc++.h>
#include <ncurses.h>
// #include "Player.h"
#pragma once
using namespace std;
class Board{
public:
    int HP, weapon,X,Y,weapon_ATK,weapon_speed,enemy_defeated, level, score, rank, user_name, depth;
    string name, weapon_name;
    Board();
    void board();
    void control_board();
    void spaceship_info();
    void exploit_info();
};