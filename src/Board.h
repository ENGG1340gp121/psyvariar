#include <bits/stdc++.h>
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
    int HP, weapon,weapon_ATK,weapon_speed,enemy_defeated, level, score, rank, user_name, depth;
    string name, weapon_name;
    Board();
    Board(WINDOW* main_win, int _X, int _Y);
    void board(Player player);
    void control_board();
    void spaceship_info();
    void exploit_info();
    void spaceship(WINDOW* win, int level, int weapon);
    void _HP(WINDOW* win);
};