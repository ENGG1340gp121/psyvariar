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
	menu m;
	if(argc == 1) load.play();
	pair<int, int> x = {0, 0};
	while (x.first != 5){
    	x = m.Menu_play();
	    if (x.first == 1){
			x = {0, 0};
    		game g(0, 30, 100);
        	g.play();
    	}
	}
	return 0;

}
