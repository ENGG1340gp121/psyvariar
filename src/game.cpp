#include <bits/stdc++.h>
#include <curses.h>
#include "game.h"
#include "Enemies.h"
#include "Bullet.h"
using namespace std;
game::game(){

}
game::game(int difficulty, int X_size,int Y_size){
    enemies = Enemies(difficulty, X_size, Y_size);
    obstacles = Obstacles(X_size, Y_size);
    initscr();
    cbreak();
    timeout(TIME_OUT);
    keypad(stdscr, TRUE);
    LX = 1, RY = X_size - 2;
    LY = 1, RX = Y_size - 2;
    win = stdscr;
    player = Player(0, 1, 1, LX, LY, RX, RY, 0, '#');
}
void game::all_move(){
    
    vector<Bullet> alive_bullets;
    for(Bullet& bullet : player.Bullets){
        bullet.move();
        bool flag = enemies.hit(bullet.x, bullet.y);
        if(bullet.is_inside()&&!flag)
            alive_bullets.push_back(bullet);
    }
    swap(player.Bullets, alive_bullets);
    alive_bullets.clear();
    enemies.move();
    
    for(Bullet& bullet : player.Bullets){
        bool flag = enemies.hit(bullet.x, bullet.y);
        if(bullet.is_inside()&&!flag)
            alive_bullets.push_back(bullet);
    }
    swap(player.Bullets, alive_bullets);
    alive_bullets.clear();
}
void game::play(){
    int c;
    while((c = getch()) != KEY_F(1)){
        if (c == ' '){
            player.shoot();
        }
        else if (c == 'f'){
            continue;
        }
        else if (c == 'q'){
            break;
        }
        else player.move(c);
        for(Bullet& b : player.Bullets){
            b.move();
        }
        all_move();
        enemies.add(MIN_ENEMIES);
        if (player.HP <= 0) break;
        display();
    }
    endwin();
}
void game::display() {
    werase(win);
    wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
    player.draw(win);
    enemies.draw(win);
    
    wrefresh(win);
}
