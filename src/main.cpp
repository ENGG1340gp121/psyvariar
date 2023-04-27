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
<<<<<<< HEAD
	load.play();
	menu m;
	m.Menu();
=======
	if(argc == 1) load.play();
	//Menu::menu()
	game g(0, 30, 100);
	g.play();
>>>>>>> 1e4794c7dc295c9ea111ef2fe4ea1ca27e77f334
	return 0;

}
