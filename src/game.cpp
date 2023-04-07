#include <bits/stdc++.h>
#include <curses.h>
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
        else if(c == ' '){
            bullets.push_back(Bullet(player.x, player.y, LX, LY, RX, RY, '-'));
        }

        check_hit();

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
    for(Bullet& bullet : bullets){
        if(bullet.is_inside()){
            bullet.draw(win);
        }
    }
    wrefresh(win);
}