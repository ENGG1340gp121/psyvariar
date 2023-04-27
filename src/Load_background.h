#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <curses.h>
#include <unistd.h>
#pragma once
using namespace std;

class load_background{
    public:
        void play();
        void start_win(WINDOW *main_Win);
        void probar(WINDOW *main_Win);
        void background_story(WINDOW *main_Win);
};