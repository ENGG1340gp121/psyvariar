#include <bits/stdc++.h>
#include <ncurses.h>
#include "Player.h"
#include "Enemy.h"
using namespace std;
class game{
    public:
        WINDOW *win;
        int TIME_OUT, MIN_ENEMIES;
        int LX, LY, RX, RY;
        Player player;
        vector<Enemy> enemies;
        game();
        game(int _TIME_OUT, int _MIN_ENEMIES);
        void play();
    	void display();
    private:
};