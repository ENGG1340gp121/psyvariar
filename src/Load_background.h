#include <bits/stdc++.h>
#include <curses.h>
#include <unistd.h>

using namespace std;

class load_background{
    public:
        void initialize();
        const int Width = 150;  //窗口宽度
        const int Length = 50;  //窗口高度
        WINDOW *main_Win=newwin(Length, Width, 0, 0); //创建子窗口
        void start_win(WINDOW *main_Win);
        void probar(WINDOW *main_Win);
        void background_story(WINDOW *main_Win);
};