#include <iostream>
#include <curses.h>
#include <string>
#include <vector>
#include <algorithm>
#include "menu.h"
#include "game.h"
#include "save.h"
#include "globals.h"
using namespace std;
//Menu.cpp is used to show the menu of the game and get the input from the user
void menu::Menu(){

}
//This function converts the character input by the user to an integer.
int mygetch() {
	int res = -1;
	while(res == -1) {
		res = getch();
	}
	return res;
}
//This function prints the menu on the screen and asks the player to select an option.
//This function returns the option number input by the player.
int menu::show_menu_get_input(){
    initscr();
    WINDOW *win = newwin(50,150,0,0);
//	keypad(stdscr, TRUE);
	cbreak();
	noecho();
    //+-------------------------------------+
    //|                Menu                 |
    //|         1. Start a New Game         |
    //|          2. Game Handbook           |
    //|        3. Print Ranking Board       |
    //|            4. Quit Game             |
    //| Please enter an integer from 1 to 4:|
    //+-------------------------------------+
    wmove(win,0,0);
    wprintw(win,"+-------------------------------------+");
    wmove(win,1,0);
    wprintw(win,"|                Menu                 |");
    wmove(win,2,0);
    wprintw(win,"|         1. Start a New Game         |");
    wmove(win,3,0);
    wprintw(win,"|          2. Game Handbook           |");
    wmove(win,4,0);
    wprintw(win,"|        3. Print Ranking Board       |");
    wmove(win,5,0);
    wprintw(win,"|            4. Quit Game             |");
    wmove(win,6,0);
    wprintw(win,"| Please enter an integer from 1 to 4:|");
    wmove(win,7,0);
    wprintw(win,"+-------------------------------------+");
    refresh();
    wrefresh(win);
    int n = mygetch() - '0';
    int line = 9;
    while (n != 1 && n != 2 && n != 3 && n != 4){
        wmove(win,line,0);
        wprintw(win,"Invalid input! Please enter an integer from 1 to 4");
        refresh();
	    wrefresh(win);
	    n = mygetch() - '0';
//        line += 1;
    }
    refresh();
    wrefresh(win);
    delwin(win);
    endwin();
    return n;
}
// This function prints the current difficulty level and enables the player to change the difficulty level.
// return the difficulty player input
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
        Menu_play();
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
        Menu_play();
    }
    return difficulty;
}
//This function prints the game handbook. Players can enter anything to return to the menu.
void menu::game_instructions(){
    initscr();
    WINDOW *new_win = newwin(50,150,0,0);
//	keypad(stdscr, TRUE);
    cbreak();
    noecho();
    wmove(new_win,0,0);
    wprintw(new_win,"Game Instructions:");
    wmove(new_win,2,0);
    wprintw(new_win, "1. Introduction:\nWelcome to Psyvariar, a text-based game where you control a fighter plane and battle against waves of enemy planes. Your mission is to survive as long as possible.\n2. Controls:\nUse the arrow keys to move your plane up, down, left, and right. Press the spacebar to fire bullets at the enemy planes.\n3. Gameplay:\nThe game consists of 3 levels, each with increasing difficulty. During the game, you will face waves of enemy planes that will try to shoot you down.\nAlso be careful not to collide with any enemy planes or obstacles, as this will result in your plane being destroyed.\n4. Game Over:\nThe game will end when your plane is destroyed. Your final flying distance will be displayed, and you will have the option to play again.\n\nThat's it! We hope this helps you get started on your Plane War game. Good luck!");
    wprintw(new_win, " Please input anything to return.");
    refresh();
    wrefresh(new_win);
    curs_set(0);
    while(getch() == -1);
    curs_set(1);
    delwin(new_win);
    endwin();
    //Print the menu and get the user's input again.
    Menu_play();
}
//This function prints the usernames and the scores of top ten players. It is called "Rank Board". Players can enter anything to return. 
void menu::print_rank_board(){
    initscr();
    WINDOW *new_win = newwin(50,150,0,0);
    Save s;
    vector<Save::record> records = s.read("rank_board.txt");
    int line = 3;
    wmove(new_win,0,0);
    wprintw(new_win,"+---------------------------+");
    wmove(new_win,1,0);
    wprintw(new_win,"|                           |");
    wmove(new_win,2,0);
    wprintw(new_win,"|  rank   username   score  |");
    refresh();
    wrefresh(new_win);
    for (int i=0; i<records.size(); ++i){
        wmove(new_win,line,0);
        const char* user_name = records[i].username.c_str();
        wprintw(new_win, "|  %4d   %8s   %5d  |\n", i+1, user_name, records[i].score);
        refresh();
        wrefresh(new_win);
        line++;
    }
    wmove(new_win,line,0);
    line++;
    wprintw(new_win,"|                           |");
    wmove(new_win,line,0);
    line++;
    wprintw(new_win,"+---------------------------+");
    wmove(new_win,line,0);
    line++;
    wmove(new_win,line,0);
    line++;
    wprintw(new_win,"* Please input \'r\' to quit the rank board.");
    refresh();
    wrefresh(new_win);
    while(mygetch() != 'r');
    delwin(new_win);
    endwin();
    //Print the menu and get the user's input again.
    Menu_play();
}
//This function asks the user to input his/her username.
//This function returns the username of the player.
string menu::get_username(){
    initscr();
    WINDOW *new_win = newwin(50,150,0,0);
//    cbreak();
//    noecho();
    wmove(new_win,0,0);
    wprintw(new_win,"Please input your username (press \"enter\" when finished): ");
    refresh();
    wrefresh(new_win);
    char* user_name = new char[100];
    char* cur = user_name;
    char x = 0;
    while(x != -1 && x != 10){
        x = mygetch();
        if(x == 127){
            cur --;
            *cur = '\0';
        }
        else{
            *cur = x;
            cur++;
        }
        wmove(new_win, 0, 0);
        werase(new_win);
        wprintw(new_win,"Please input your username (press \"enter\" when finished): %s", user_name);
        refresh();
        wrefresh(new_win);
    }
    wmove(new_win,1,0);
    wprintw(new_win,"Your username is: ");
    wprintw(new_win, "%s", user_name);
    wmove(new_win,2,0);
    wprintw(new_win,"Please press spacebar to enter the game menu. Enjoy!");
    refresh();
    wrefresh(new_win);
    mygetch();
    delwin(new_win);
    string username_str(user_name);
    delete[] user_name;
    return username_str;
}
//This function shows the final score when game is over. Players are able to see the rank board.
void menu::Menu_ending(int score){
    initscr();
    WINDOW *new_win = newwin(50,150,0,0);
    wmove(new_win,0,0);
    wprintw(new_win,"Game over! Your final score is: %d", score);
    wmove(new_win,1,0);
    wprintw(new_win,"Input \'p\' to see the ranking table");
    refresh();
    wrefresh(new_win);

    while(mygetch() != 'p');
    print_rank_board();
    delwin(new_win);
}
//This is the main function for menu.
void menu::Menu_play(){
    int n = show_menu_get_input();
    while (n != 4){
        if (n == 1){
            game g(0,30,100);
            g.play();
            int enemies_defeated = g.score_return();
            int score = enemies_defeated*10;
            Save s;
            s.insert_rank("rank_board.txt", globle_username, score);
            Menu_ending(score);
        }
        else if (n == 2){
            game_instructions();
        }
        else if (n == 3){
            print_rank_board();
        }
        n = show_menu_get_input();
    }
}
//This function converts the player's username to a global varaible so that it can be accessed in "Menu_play()" function.
void menu::Menu_init(){
    globle_username = get_username();
}