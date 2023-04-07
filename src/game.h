#include <bits/stdc++.h>
#include <curses.h>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
using namespace std;
class game{
    public:
        WINDOW *win;
        int TIME_OUT, MIN_ENEMIES;
        int LX, LY, RX, RY;
        Player player;
        vector<Enemy> enemies;
        vector<Bullet> bullets;
        game();
        game(int _TIME_OUT, int _MIN_ENEMIES);
        void play();
        void clear_hit_item();
        void check_hit();
    	void display();
    private:
};