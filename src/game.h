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
        game(int difficulty, int X_size,int Y_size);
        void play();
        void all_move();
    	void display();
        void draw_border();
    private:
};
