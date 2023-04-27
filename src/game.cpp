#include <bits/stdc++.h>
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
    cbreak();
    timeout(TIME_OUT);
    keypad(stdscr, TRUE);
    LX = 1, RY = Y_size - 2;
    LY = 1, RX = X_size - 2;
    win = stdscr;
    player = Player(LX, LY, RX, RY, 0, 10, 1, 1);
    enemies = Enemies(difficulty, LX, LY, RX, RY);
//    obstacles = Obstacles(LX, LY, RX, RY);
    b = Board(win, Y_size, X_size);
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
}
void game::check_player_damage(){
    bool hit_flag_crash = 0;
    for(Enemy& e : enemies.enemies){
        for(Player::plane_char& p : player.Plane[player.Level]){
            for(Enemy::Enemy_char& t : e.Enemy_figure[e.level]){
                if(e.x + t.x == player.x + p.x && e.y +  t.y == player.y + p.y){
                    hit_flag_crash = 1;
                }
            }
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
    if (hit_flag_crash) player.get_damage(INF);
}
void game::play(){
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
        check_player_damage();
        if (player.HP <= 0) break;
        display();
        count = (count + 1) % 25;
        if (count == 0)
            player.gun_heat_annealing();
    }
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
    b.board(player);
    wrefresh(win);
}