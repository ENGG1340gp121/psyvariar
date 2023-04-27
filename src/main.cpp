#include <bits/stdc++.h>
#include <curses.h>
#include "game.h"
#include "Load_background.h"
using namespace std;
int main(){
	load_background load;
	//load.play();
	//Menu::menu()
	game g(0, 30, 100);
	g.play();
	return 0;

}
