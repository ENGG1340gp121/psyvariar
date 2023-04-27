#include <bits/stdc++.h>
#include <curses.h>
#include "game.h"
#include "Load_background.h"
#include "menu.h"
using namespace std;
int main(){
	load_background load;
	load.play();
	menu m;
	m.Menu();
	return 0;

}
