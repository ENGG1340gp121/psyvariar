#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <curses.h>
#include "game.h"
#include "Enemies.h"
#include "Bullet.h"
#include "Board.h"
#define INF 1000000
using namespace std;
game::game(){

}
game::game(int difficulty, int X_size,int Y_size){
	TIME_OUT = 20;
	MIN_ENEMIES = 10;
    initscr();
    win = stdscr; //newwin(50,150,0,0);
    cbreak();
    timeout(TIME_OUT);
    keypad(stdscr, TRUE);
    LX = 1, RY = Y_size - 2;
    LY = 1, RX = X_size - 2;
    player = Player(LX, LY, RX, RY, 0, 10, 1, 1);
    enemies = Enemies(difficulty, LX, LY, RX, RY);
    obstacles = Obstacles(difficulty, LX, LY, RX, RY);
    b = Board(win, Y_size, X_size);
    enemies_defeated = 0;
}


void game::all_move(){
    
    enemies.shoot(40);
    
    for(Enemy& e : enemies.enemies){
        for(Bullet& b : e.bullets){
            b.move(1, -1);
        }
    }
    vector<Bullet> alive_bullets;
    for(Bullet& bullet : player.Bullets){
        int flag = enemies.hit(bullet.x, bullet.y, player.atk[player.Level]);
        if(flag == 2)
            enemies_defeated ++;
        if(bullet.is_inside()&&!flag)
            alive_bullets.push_back(bullet);
    }
    swap(player.Bullets, alive_bullets);
    alive_bullets.clear();

    for(Bullet& bullet : player.Bullets){
        bullet.move(1, 1);
        int flag = enemies.hit(bullet.x, bullet.y, player.atk[player.Level]);
        if(flag == 2)
            enemies_defeated ++;
        if(bullet.is_inside()&&!flag)
            alive_bullets.push_back(bullet);
    }
    swap(player.Bullets, alive_bullets);
    alive_bullets.clear();

    enemies.move();
    for(Bullet& bullet : player.Bullets){
        int flag = enemies.hit(bullet.x, bullet.y, player.atk[player.Level]);
        if(flag == 2)
            enemies_defeated ++;
        if(bullet.is_inside()&&!flag)
            alive_bullets.push_back(bullet);
    }
    swap(player.Bullets, alive_bullets);
    alive_bullets.clear();

    for(Bullet& bullet : player.Bullets){
        int flag = obstacles.hit(bullet.x, bullet.y);
        if(bullet.is_inside()&&!flag)
            alive_bullets.push_back(bullet);
    }
    swap(player.Bullets, alive_bullets);
    alive_bullets.clear();

    for(Bullet& bullet : player.Bullets){
        bullet.move(1, 1);
        int flag = obstacles.hit(bullet.x, bullet.y);
        if(bullet.is_inside()&&!flag)
            alive_bullets.push_back(bullet);
    }
    swap(player.Bullets, alive_bullets);
    alive_bullets.clear();

    obstacles.move();
    for(Bullet& bullet : player.Bullets){
        int flag = obstacles.hit(bullet.x, bullet.y);
        if(bullet.is_inside()&&!flag)
            alive_bullets.push_back(bullet);
    }
    swap(player.Bullets, alive_bullets);
    alive_bullets.clear();
}
void game::check_player_damage(){
    vector<pair<int, int>> p_pos = player.get_positions();
    vector<pair<int, int>> e_pos = enemies.get_positions();
    vector<pair<int, int>> o_pos = obstacles.get_positions();

    for(Enemy& e : enemies.enemies){
        for(Player::plane_char& p : player.Plane[player.Level]){
            vector<Bullet> tmp;
            for(Bullet& b : e.bullets){
                if(b.x == player.x + p.x && b.y == player.y + p.y){
                    player.get_damage(1);
                }
                else
                    tmp.push_back(b);
            }
            swap(tmp, e.bullets);
        }
    }

    auto crash = [] (vector<pair<int, int>> a, vector<pair<int, int>> b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(int i = 0, j = 0; i < int(a.size()) && j < int(b.size());) {
            if(a[i] == b[j]) return true;
            if(a[i] < b[j]) i++;
            else j++;
        }
        return false;
    };
    for(Enemy& e : enemies.enemies){
        vector<pair<int, int>> pos = e.get_positions();
        if(crash(pos, o_pos)) {
            e.decrease_HP(INF);
        }
    }
    if(crash(p_pos, e_pos) || crash(p_pos, o_pos)) {
        player.get_damage(INF);        
    }
}
void game::play(){
    curs_set(0);
    int c;
    int count = 0;
    while((c = getch()) != KEY_F(1)){
        if (c == ' '){
            if(player.shoot() == 0)
                //show_over_heat_warning();
                continue;
        }
        else if (c == 'f'){
            enemies.enemies.clear();
            continue;
        }
        else if (c == 'q'){
            break;
        }
        else player.move(c);
        all_move();
        enemies.add(MIN_ENEMIES);
        obstacles.add(5);
        check_player_damage();
        if (player.HP <= 0) break;
        display();
        count = (count + 1) % 25;
        if (count == 0)
            player.gun_heat_annealing();
    }
    curs_set(1);
    delwin(win);
    endwin();
}

// Draw the border of the frame
void game::draw_border() {
    mvwaddch(win, LX - 1, LY - 1, '+');
    mvwaddch(win, LX - 1, RY + 1, '+');
    mvwaddch(win, RX + 1, LY - 1, '+');
    mvwaddch(win, RX + 1, RY + 1, '+');
    for(int i = LX; i <= RX; i++) {
        mvwaddch(win, i, RY + 1, '|');
        mvwaddch(win, i, LY - 1, '|');
    }
    for(int i = LY; i <= RY; i++) {
        mvwaddch(win, RX + 1, i, '-');
        mvwaddch(win, LX - 1, i, '-');
    }
}

void game::display() {
    werase(win);
    draw_border();
    player.draw(win);
    enemies.draw(win);
    obstacles.draw(win);
    b.board(player,enemies_defeated);
	refresh();
    wrefresh(win);
}
