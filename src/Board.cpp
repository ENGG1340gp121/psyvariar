#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//#include "menu.h"
#include <ncurses.h>
// #include "Player.h"
// #include "game.h"
#include "Board.h"
using namespace std;



/*
void System_message(WINDOW win){

    if (attacked){

    }
    if (overheating){
        wmove(win,10,1);
        wprintw("weapon overheating")

    }
}*/

Board::Board(){}

Board::Board(WINDOW* main_win, int _X, int _Y) {
    win = main_win;
    X = _X;
    Y = _Y;

    // control_board
    win1 = subwin(win, 20, 50, Y, 0);

    // spaceship_info
    win2 = subwin(win, 20, 50, Y, 50);

    // exploit_info
    win3 = subwin(win, 50, 50, 0, X);


}

void Board::board(Player player, int enemies_defeated){
    HP = player.HP;
    weapon = player.weapon;
    weapon_name = "weapon_name";
    score = enemies_defeated*10;
    weapon_ATK = 0;
    weapon_speed = 0;
    enemy_defeated = 0;
    overheating = player.gun_heat;
    // player.name;
    level = score/200;
    //depth;
    control_board();
    spaceship_info();
    exploit_info();
}

void Board::control_board(){
    wborder(win1,'|','|','--','--','+','+','+','+');
    wmove(win1,1,1);
    wprintw(win1,"%s","  <||          CENTROL   CONTROL          ||>");
    spaceship(win1,level,weapon);
    _HP(win1);
    // system_message(win1);
}


void Board::spaceship_info(){
    wborder(win2,'|','|','--','--','+','+','+','+');
    wmove(win2,1,3);
    wprintw(win2,"%s","code: ");
    wprintw(win2,"%d",user_name);
    wmove(win2,3,3);
    wprintw(win2,"%s","ship level: ");
    wprintw(win2,"%d",level);// enter player level;
    wmove(win2,5,3);
    wprintw(win2,"%s","level of authority: TOP");
    wmove(win2,7,3);
    wprintw(win2,"%s","depth explored: ");
    wprintw(win2,"%d",depth);
    wmove(win2,9,3);
    wprintw(win2,"%s", "weapon:" );
    wprintw(win2,"%s",weapon_name.c_str());
    wmove(win2,11,3);
    wprintw(win2,"%s","weapon ATK: ");
    wprintw(win2,"%d",weapon_ATK);
    wmove(win2,13,3);
    wprintw(win2,"%s","weapon speed: ");
    wprintw(win2,"%d",weapon_speed);
    wmove(win2,15,3);
    wprintw(win2,"%s","weapon durancy: ");

}

void Board::exploit_info(){// control the right board
    wborder(win3,'|','|','--','--','+','+','+','+');
    wmove(win3,1,3);
    wprintw(win3,"%s","_______ _______  _____   ______ _______");
    wmove(win3,2,3);
    wprintw(win3,"%s","|______ |       |     | |_____/ |______");
    wmove(win3,3,3);
    wprintw(win3,"%s","______| |_____  |_____| |     | |______");
    wmove(win3,4,3);
    wprintw(win3,"%s","___________________________________________");
    wmove(win3,6,22);
    wprintw(win3,"%d",score);
    wmove(win3,7,3);
    wprintw(win3,"%s","____________________________________________");
    wmove(win3,9,3); 
    wprintw(win3,"%s","<<|          SYSTEM   MESSAGE          |>>");
    wmove(win3,11,3);
    wprintw(win3,"%s","____________________________________________");
    wmove(win3,13,3);
    if (overheating >= 5){
        wprintw(win3,"%s","_____________!!!!warning!!!!____________");
        wmove(win3,14,3);
        wprintw(win3,"%s","          ! weapon overheating !         ");
        
    }
    else{
        wmove(win3,13,3);
        wprintw(win3,"%s","               weapon ready      ");

    }
    wmove(win3,15,3);
    wprintw(win3,"%s","____________________________________________");
    wmove(win3,17,3);
    if (HP <= 2){
        wprintw(win3,"%s","_____________!!!!warning!!!!______________");
        wmove(win3,18,3);
        wprintw(win3,"%s","            ! ship in danger !         ");
    }
    else{
        wmove(win3,17,3);
        wprintw(win3,"%s","              ship status normal      ");

    }
    wmove(win3,19,3);
    wprintw(win3,"%s","____________________________________________");
    wmove(win3,20,3);
    wprintw(win3,"%s","<<|          CONTROL   MESSAGE          |>>");
    wmove(win3,21,2);
    wprintw(win3,"%s","[press \"up\", \"down\", \"left\", \"right\" to move]");
    wmove(win3,22,2);
    wprintw(win3,"%s","[press \"space\" to shoot  ]");
    wmove(win3,23,2);
    wprintw(win3,"%s","[press \"q\" to quit  ]");
    wmove(win3,24,2);
    wprintw(win3,"%s","[press \"esc\" to slow down the time  ]");
    wmove(win3,25,2);
    wprintw(win3,"%s","[press \"r\" to resume  ]");
    wmove(win3,26,2);
    wprintw(win3,"%s","[press \"f\" to fire LASER CONNON  ]"); 
    wmove(win3,27,3);
    wprintw(win3,"%s","_____________________________________________");
    wmove(win3,28,3);
    wprintw(win3,"%s","<<|            EXPLOIT WALL             |=>>");
    wmove(win3,29,3);
    wprintw(win3,"%s","_____________________________________________");
    wmove(win3,30,3);
    wprintw(win3,"%s","<<=|----------EARTH-FEDERATION----------|=>>");
    wmove(win3,31,3);
    wprintw(win3,"%s","_____________________________________________");
    if (score > 50){
        wmove(win3,32,3);
        wprintw(win3,"%s","<<=|------------LANCE-CORPORAL------ ----|=>>");
    }
    wmove(win3,33,3);
    wprintw(win3,"%s","____________________________________________");
    if (score > 100){
        wmove(win3,34,3);
        wprintw(win3,"%s","<<=|----------------COLONEL--------------|=>>");
    }
    wmove(win3,35,3);
    wprintw(win3,"%s","____________________________________________");
    if (score > 200){
        wmove(win3,36,3);
        wprintw(win3,"%s","<<=|--------------AIR-MARSHAL------------|=>>");
    }
    wmove(win3,37,3);
    wprintw(win3,"%s","____________________________________________");
    if (score > 300){
        wmove(win3,38,3);
        wprintw(win3,"%s","<<=|----------------ADMIRAL--------------|=>>");
    }
    wmove(win3,39,3);
    wprintw(win3,"%s","____________________________________________");
    if (score > 500){
        wmove(win3,40,3);
        wprintw(win3,"%s","<<=|------------UNITED-MARSHAL-----------|=>>");
    }
    wmove(win3,41,3);
    wprintw(win3,"%s","____________________________________________");
    if (score > 1000){
        wmove(win3,42,3);
        wprintw(win3,"%s","<<=|---------------WAR-LEGEND-------------|=>>");
    }
    wmove(win3,43,3);
    wprintw(win3,"%s","____________________________________________");
    if (score > 2000){
        wmove(win3,44,3);
        wprintw(win3,"%s","<<=|---------------GOD-OF-WAR-------------|=>>");
    }
    wmove(win3,45,3);
    wprintw(win3,"%s","____________________________________________");
    wmove(win3,47,3); 
    wprintw(win3,"%s","fight on!!! you are the hope of earth!!!    ");
    wmove(win3,48,3);
    wprintw(win3,"%s","_____________________________________________");
    
}

void Board::spaceship(WINDOW* win, int level, int weapon){// draw the image of spaceship according to it's level
    if (level>=0){
        wmove(win,10,14);
        wprintw(win,"%s","=<=><+<->+><=>>>>");
    }
    if (level>=1){
        wmove(win,9,10);
        wprintw(win,"%s","<<:0:>=->");
        wmove(win,11,10);
        wprintw(win,"%s","<<:0:>=->");
    }
    if (level>=2){
        wmove(win,13-5,8+5);
        wprintw(win,"%s","8&8>>=");
        wmove(win,17-5,8+5);
        wprintw(win,"%s","8&8>>=");
    }
    if (level>=3){
        wmove(win,6,12);
        wprintw(win,"%s","-->0-->");
        wmove(win,14,12);
        wprintw(win,"%s","-->0-->");
    }
    if (level>=4){
        wmove(win,5,12);
        wprintw(win,"%s","66>-");
        wmove(win,15,12);
        wprintw(win,"%s","99>-");
    }
    if(level >= 5){
        wmove(win,4,12);
        wprintw(win,"%s","88");
        wmove(win,16,12);
        wprintw(win,"%s","88");
    }
    if (weapon){
        switch(weapon) {// weapon code ;
        case 1:
            wmove(win,3,14);
            wprintw(win,"%s","88>-");
            wmove(win,17,14);
            wprintw(win,"%s","88>-");
            break;
        case 2:
            wmove(win,17,14);
            wprintw(win,"%s",">>>>>");
            wmove(win,17,14);
            wprintw(win,"%s",">>>>>");
            break;
        case 3:
            wmove(win,3,14);
            wprintw(win,"%s",">>0>");
            wmove(win,17,14);
            wprintw(win,"%s",">>0>");
            break;
        case 4:
            wmove(win,3,14);
            wprintw(win,"%s",">>=0]");
            wmove(win,17,14);
            wprintw(win,"%s",">>=0]");
            break;
        }
    }
}

void Board::_HP(WINDOW* win){
    wmove(win,18,1);
    wprintw(win,"%s","<[HP: ");
    wmove(win,18,36);
    wprintw(win,"%s","]>");
    int temp=6;  
    for (int i = 1; i <= HP; i++) {
        wprintw(win,"%s","XXX");
        wmove(win,18,temp+i+i+i);   
    } 
}

   
