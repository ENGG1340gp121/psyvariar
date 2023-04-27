#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <curses.h>
#include "game.h"
#include "Load_background.h"
using namespace std;
int main(int argc, char *argv[]){
	load_background load;
	if(argc == 1) load.play();
	//Menu::menu()
	game g(0, 30, 100);
	g.play();
	return 0;

}
