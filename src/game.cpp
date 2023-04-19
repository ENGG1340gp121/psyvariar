#include <bits/stdc++.h>
#include <curses.h>
#include "game.h"
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
void game::clear_hit_item(){
    vector<Enemy> alive_enemies;
    vector<Bullet> alive_bullets;
    for(Enemy& enemy : enemies){
        bool alive_flag = 1;
        for(Bullet& bullet : bullets){
            if (enemy.x == bullet.x && enemy.y == bullet.y){
                alive_flag = 0;
                break;
            }
        }
        if (alive_flag) alive_enemies.push_back(enemy);
    }
    swap(enemies, alive_enemies);
    alive_enemies.clear();

    for(Bullet& bullet : bullets){
        bool alive_flag = 1;
        for(Enemy& enemy : enemies){
            if (enemy.x == bullet.x && enemy.y == bullet.y){
                alive_flag = 0;
                break;
            }
        }
        if (alive_flag) alive_bullets.push_back(bullet);
    }
    swap(bullets, alive_bullets);
    alive_bullets.clear();
}
void game::check_hit(){
    
    vector<Enemy> alive_enemies;
    vector<Bullet> alive_bullets;

    for(Bullet& bullet : bullets){
        bullet.move();
        if(bullet.alive())
            alive_bullets.push_back(bullet);
    }
    swap(bullets, alive_bullets);
    alive_bullets.clear();
    clear_hit_item();

    for(Enemy& enemy : enemies){
        enemy.move();
        if(enemy.alive())
            alive_enemies.push_back(enemy);
    }
    swap(enemies, alive_enemies);
    alive_enemies.clear();
    clear_hit_item();

}
void game::play(){
    int c;
    while((c = getch()) != KEY_F(1)){
        if (c == ' '){
            bullets
            bullets.push_back(Bullet(player.x, player.y, LX, LY, RX, RY, '-'));
        }
        else if (c == 'f'){
            bullets
        }
        else if (c == 'q'){

        }
        else player.move(c);
        bullets.move();
        check_hit();
        enemies.move();
        check_hit();
        enemies.add(MIN_ENEMIES);
        if (!player.check_alive())
            break;
        display();
    }
    endwin();
}
void game::display() {
    werase(win);
    wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
    player.draw(win);
    enemies.draw(win);
    bullets.draw(win);
    wrefresh(win);
}
