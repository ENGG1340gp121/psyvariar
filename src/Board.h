#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ncurses.h>
#include "Player.h"
#pragma once
using namespace std;
class Board{
public:
    int X, Y;
    WINDOW* win;
    WINDOW* win1;
    WINDOW* win2;
    WINDOW* win3;
    Player p;
    int HP, weapon,weapon_ATK,weapon_speed,enemy_defeated, level, score, rank, user_name, depth,overheating;
    string name, weapon_name;
    Board();
    Board(WINDOW* main_win, int _X, int _Y);
    void board(Player player,int enemies_defeated);
    void control_board();
    void spaceship_info();
    void exploit_info();
    void spaceship(WINDOW* win, int level, int weapon);
    void _HP(WINDOW* win);
};