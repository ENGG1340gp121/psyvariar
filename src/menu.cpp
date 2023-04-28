#include <iostream>
#include <curses.h>
#include <string>
#include "menu.h"
using namespace std;
void menu::Menu(){
    
}
int mygetch() {
	int res = -1;
	while(res == -1) {
		res = getch();
	}
	return res;
}
int menu::show_menu_get_input(){
    initscr();
    WINDOW *win = newwin(50,150,0,0);
//	keypad(stdscr, TRUE);
	cbreak();
	noecho();
    wmove(win,0,0);
    wprintw(win,"Menu:");
    wmove(win,1,0);
    wprintw(win,"1. Start a New Game");
    wmove(win,2,0);
    wprintw(win,"2. Game Handbook");
    wmove(win,3,0);
    wprintw(win,"3. Print Ranking Board");
    wmove(win,4,0);
    wprintw(win,"4. Quit Game");
    wmove(win,7,0);
    wprintw(win,"Please enter an integer from 1 to 4: ");
    refresh();
    wrefresh(win);
	int n = mygetch() - '0', line;
    line = 8;
    while (n!=1 && n!=2 && n!=3 && n!=4 && n!=5){
        wmove(win,line,0);
        wprintw(win,"Invalid input! Please enter an integer from 1 to 5: ");
       refresh();
		wrefresh(win);
		n = mygetch() - '0';
        line += 1;
    }
    refresh();
    wrefresh(win);
    delwin(win);
    endwin();
    return n;
}
int menu::process_input(int n){
    if (n == 1){
        return 1;
    }
    else if (n == 2){
        game_instructions();
        return 2;
    }
    else if (n == 3){
        print_rank_board();
        return 2;
    }
    return 0;
}
int menu::change_difficulty_level(){
    initscr();
    WINDOW *new_win = newwin(50,150,0,0);
//	keypad(stdscr, TRUE);
	cbreak();
    int difficulty, line;
    difficulty = 1;
    line = 2;
    wmove(new_win,0,0);
    wprintw(new_win,"The current difficulty level is: ");
    string diff_str = to_string(difficulty);
    const char* diff_cstr = diff_str.c_str();
    wprintw(new_win,diff_cstr);
    wmove(new_win,1,0);
    wprintw(new_win,"Enter 'c' to change the difficulty level / Enter 'q' to quit: ");
    refresh();
    wrefresh(new_win);
    char input1;
    input1 = mygetch();
    while (input1!='c' && input1!='q'){
        wmove(new_win,line,0);
        wprintw(new_win,"Invalid input! Please enter 'c' or 'q': ");
        wrefresh(new_win);
        input1 = mygetch();
        line += 1;
    }
    wrefresh(new_win);
    if (input1 == 'q'){
        delwin(new_win);
        show_menu_get_input();
    }
    else{
        wmove(new_win,line,0);
        wprintw(new_win,"Please choose a difficulty level (from 1 to 3): ");
        wrefresh(new_win);
        int input2;
        input2 = mygetch() - '0';
        while (input2!=1 && input2!=2 && input2!=3){
            wmove(new_win,line+1,0);
            wprintw(new_win,"Invalid input! Please enter an integer from 1 to 3: ");
            wrefresh(new_win);
            input2 = mygetch() - '0';
            line += 1;
        } 
        wrefresh(new_win);
        difficulty = input2;
        delwin(new_win);
        show_menu_get_input();
    }
    return difficulty;
}
void menu::game_instructions(){
    initscr();
    WINDOW *new_win = newwin(50,150,0,0);
//	keypad(stdscr, TRUE);
	cbreak();
    wmove(new_win,0,0);
    wprintw(new_win,"Game Instructions:");
    wmove(new_win,2,0);
    wprintw(new_win, "1. Introduction:\nWelcome to Psyvariar, a text-based game where you control a fighter plane and battle against waves of enemy planes. Your mission is to survive as long as possible.\n2. Controls:\nUse the arrow keys to move your plane up, down, left, and right. Press the spacebar to fire bullets at the enemy planes.\n3. Gameplay:\nThe game consists of 3 levels, each with increasing difficulty. During the game, you will face waves of enemy planes that will try to shoot you down.\nAlso be careful not to collide with any enemy planes or obstacles, as this will result in your plane being destroyed.\n4. Game Over:\nThe game will end when your plane is destroyed. Your final flying distance will be displayed, and you will have the option to play again.\n\nThat's it! We hope this helps you get started on your Plane War game. Good luck!");
    refresh();
    wrefresh(new_win);
    curs_set(0);
    while(getch() == -1);
    curs_set(1);
    delwin(new_win);
    endwin();
    show_menu_get_input();
}
void menu::print_rank_board(){
    
}
int menu::Menu_play(){
    while(1){
        int n = show_menu_get_input();
        int x = process_input(n);
        if (x == 1){
            return 1;
        }
        if (x == 0){
            return 0;
        }
    }
}
// void menu::Menu(){
//     int x = Menu_play();
//     if (x == 1){
//     	game g(0, 30, 100);
//         g.play();
//     }
// }
