#include <bits/stdc++.h>
#include <curses.h>
#include "Player.h"
#include "Enemies.h"
#include "Bullet.h"
using namespace std;
class game{
    public:
        WINDOW *win;
        int TIME_OUT, MIN_ENEMIES;
        int LX, LY, RX, RY;
        Player player;
        Enemies enemies;
        game();
        game(int _TIME_OUT, int _MIN_ENEMIES);
        void play();
        void all_move();
    	void display();
    private:
};