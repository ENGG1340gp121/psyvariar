#include <iostream>
#include <string>
#include <curses.h>
#include <math.h>
using namespace std;
class menu{
    public:
        WINDOW *win;
    	string globle_username;
        int show_menu_get_input();
        int process_input(int n);
        int change_difficulty_level();
        void game_instructions();
        void print_rank_board();
        string get_username();
	void Menu_play();
	void Menu_ending(int score);
	void Menu();
    void Menu_init();
    private:
};
