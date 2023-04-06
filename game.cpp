#include <curses.h>
#include <bits/stdc++.h>
#include "game.h"
using namespace std;
game::game(){

}
game::game(int _TIME_OUT, int _MIN_ENEMIES){
    TIME_OUT = _TIME_OUT, MIN_ENEMIES = _MIN_ENEMIES;
    initscr();
    cbreak();
    timeout(TIME_OUT);
    keypad(stdscr, TRUE);
    LX = 1, RY = COLS - 2;
    LY = 1, RX = LINES - 2;
    win = stdscr;
    player = Player(1, 1, 1, 1, '#');
}
void game::play(){
    int c;
    while((c = getch()) != KEY_F(1)){
        
        if(c == KEY_LEFT){
            player.move_left();
        }
        else if(c == KEY_RIGHT){
            player.move_right();
        }
        else if(c == KEY_UP){
            player.move_up();
        }
        else if(c == KEY_DOWN){
            player.move_down();
        }

        vector<Enemy> alive_enemies;
        for(Enemy& enemy : enemies){
            enemy.move();
            if(enemy.alive())
                alive_enemies.push_back(enemy);
        }
        swap(enemies, alive_enemies);
        while(int(enemies.size()) < MIN_ENEMIES){
            enemies.push_back(Enemy(rand() % RX + 1, RY + rand() % RY, LX, LY, RX, RY, '@'));
        }

        bool hit = false;
        for(Enemy& enemy : enemies){
            if(enemy.x == player.x && enemy.y == player.y) {
                hit = true;
                break;
            }
        }
        if(hit) break;
        
        display();
    }
    endwin();
}
void game::display() {
    werase(win);
    wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
    player.draw(win);
    for(Enemy& enemy : enemies){
        if(enemy.is_inside()){
            enemy.draw(win);
        }
    }
    wrefresh(win);
}