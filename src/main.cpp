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
	load.play();
	menu m;
	// m.Menu();
	if(argc == 1) load.play();
    int x = m.Menu_play();
	while (x != 0){
	    if (x == 1){
    		game g(0, 30, 100);
        	g.play();
    	}
	}
	return 0;

}
