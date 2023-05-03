#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <curses.h>
#include "game.h"
#include "Load_background.h"
#include "menu.h"
#include "globals.h"
using namespace std;
int main(int argc, char *argv[]){
	load_background load;
	if(argc == 1) load.play();
	menu *M = new menu;
	M->Menu_init();
	(*M).Menu_play();
	delete(M);
	return 0;
}
