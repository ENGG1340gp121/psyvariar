#include <bits/stdc++.h>
//#include "menu.h"
#include <ncurses.h>
// #include "Player.h"
// #include "game.h"
#include "Board.h"
using namespace std;

void spaceship(WINDOW* win, int level, int weapon){
    if (level>=1){
        wmove(win,5,4);
        wprintw(win,"%s","<=><+<->+><=>");
    }
    if (level>=2){
        wmove(win,4,3);
        wprintw(win,"%s","<<:0:>=-");
        wmove(win,6,3);
        wprintw(win,"%s","<<:0:>=-");
    }
    if (level>=3){
        wmove(win,3,3);
        wprintw(win,"%s","8&8>>=");
        wmove(win,7,3);
        wprintw(win,"%s","8&8>>=");
    }
    if (weapon){
        switch(weapon) {// weapon code ;
        case 1:
            wmove(win,2,2);
            wprintw(win,"%s","88>-");
            wmove(win,8,2);
            wprintw(win,"%s","88>-");
            break;
        case 2:
            wmove(win,2,2);
            wprintw(win,"%s",">>>>>");
            wmove(win,8,2);
            wprintw(win,"%s",">>>>>");
            break;
        case 3:
            wmove(win,2,2);
            wprintw(win,"%s",">>0>");
            wmove(win,8,2);
            wprintw(win,"%s",">>0>");
            break;
        case 4:
            wmove(win,2,2);
            wprintw(win,"%s",">>=0]");
            wmove(win,8,2);
            wprintw(win,"%s",">>=0]");
            break;
        }
    }
}

void _HP(WINDOW* win){
    // wmove(win,9,1);
    // wprintw(win,"%s","HP:");
    // int temp=4;
    // for (int i = 0; i<= HP/10) {
    //     wprintw(win,"%s","X");
    //     wmove(win,9,temp+1);   
    // } 
}

/*
void System_message(WINDOW win){

    if (attacked){

    }
    if (overheating){
        wmove(win,10,1);
        wprintw("weapon overheating")

    }
}*/




// color control
void set_color(){
    start_color();
    init_pair(1,COLOR_BLACK,COLOR_BLACK);

}

Board::Board(){}
/*
Board::Board(Player player, WINDOW main_win){
    HP = player.HP, weapon = player.weapon;
    weapon_name;
    weapon_ATK;
    weapon_speed;
    enemy_defeated;
    player.name;
    level = player.level;
    depth;
    getmaxyx(win, Y, X);
}*/

void Board::board(){
    control_board();
    spaceship_info();
    exploit_info();
}

void Board::control_board(){
    WINDOW* win1 = newwin(11,20,Y,0);
    wborder(win1,'|','|','--','--','+','+','+','+');
    wmove(win1,1,1);
    wprintw(win1,"%s"," CENTROL CONTROL");
    spaceship(win1,level,weapon);
    _HP(win1);
    //system_message(win1);
}


void Board::spaceship_info(){
    WINDOW* win2 = newwin(11,30,Y,20);
    wborder(win2,'|','|','--','--','+','+','+','+');
    wmove(win2,1,1);
    wprintw(win2,"%s","code: ");
    wprintw(win2,"%s",user_name);
    wmove(win2,2,1);
    wprintw(win2,"%s","ship level: ");
    wprintw(win2,"%d",level);// enter player level;
    wmove(win2,3,1);
    wprintw(win2,"%s","level of authority: TOP");
    wmove(win2,4,1);
    wprintw(win2,"%s","depth explored: ");
    wprintw(win2,"%s",depth);
    wmove(win2,5,1);
    wprintw(win2,"%s", "weapon:" );
    wprintw(win2,"%s",weapon_name);
    wmove(win2,6,1);
    wprintw(win2,"%s","weapon ATK:");
    wprintw(win2,"%s",weapon_ATK);
    wmove(win2,7,1);
    wprintw(win2,"%s","weapon speed");
    wprintw(win2,"%s",weapon_speed);
    wmove(win2,8,1);

}

void Board::exploit_info(){
    WINDOW* win3 = newwin(11,30,Y,50);
    wborder(win3,'|','|','--','--','+','+','+','+');
    wmove(win3,1,1);
    wprintw(win3,"%s","Enemy defeated:");
    wprintw(win3,"%s",enemy_defeated);
    wmove(win3,2,1);
    wprintw(win3,"%s","rank:");
    wprintw(win3,"%s",rank);
    wmove(win3,3,1);
    wprintw(win3,"%s","SCORE");
    wprintw(win3,"%s",score);

}
