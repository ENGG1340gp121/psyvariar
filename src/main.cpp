#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <curses.h>
#include "game.h"
#include "Load_background.h"
#include "menu.h"
using namespace std;
int main(int argc, char *argv[]){
	load_background load;
	if(argc == 1) load.play();
	menu *M = new menu;
    int x = (*M).Menu_play();
	delete(M);
	while (x != 0){
    	game g(0, 30, 100);
        g.play();
		menu *M = new menu;
		x = (*M).Menu_play();
		delete(M);
	}
	return 0;
}