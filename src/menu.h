#include <iostream>
#include <ncurses.h>
using namespace std;
class menu{
    public:
        WINDOW *win;
        int show_menu_get_input();
        int process_input(int n);
        int change_difficulty_level();
        void game_instructions();
        void highest_scores();
        int Menu_play();
	void Menu();

    private:
};
