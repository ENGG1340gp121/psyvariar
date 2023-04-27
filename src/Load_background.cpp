#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <curses.h>
#include <unistd.h>
#include "Load_background.h"

using namespace std;

void load_background::play(){
    initscr();  //按键不需要输入回车直接交互
    cbreak();   //按键不显示
    noecho();   //隐藏光标
    refresh();  //刷新屏幕
    const int Width = 150;  //窗口宽度
    const int Length = 50;  //窗口高度
    WINDOW *main_Win=newwin(Length, Width, 0, 0); //创建子窗口
    wrefresh(main_Win); //刷新窗口
    start_win(main_Win);
    probar(main_Win);
    background_story(main_Win);
    delwin(main_Win);   //删除窗口
}

void load_background::start_win(WINDOW *main_Win){
    box(main_Win, '.', '.');//窗口边框
    wmove(main_Win, 20, 1);   //移动光标
    wprintw(main_Win, "%s", "        ______                                                                                                                                        ");  //窗口打印
    wmove(main_Win, 21, 1); 
    wprintw(main_Win, "%s", "  _____|\\     \\          _____   ______   _____ _______    ______    _____        ___________        ____________      _____        ___________       "); 
    wmove(main_Win, 22, 1); 
    wprintw(main_Win, "%s", " /     / |     |    _____\\    \\ |\\     \\ |     |\\      |  |      | /      |_      \\          \\      /            \\   /      |_      \\          \\      "); 
    wmove(main_Win, 23, 1); 
    wprintw(main_Win, "%s", "|      |/     /|   /    / \\    |\\ \\     \\|     | |     /  /     /|/         \\      \\    /\\   \\    |\\___/\\  \\___/| /         \\      \\    /\\    \\     "); 
    wmove(main_Win, 24, 1); 
    wprintw(main_Win, "%s", "|\\     \\    | /____\\    \\ |   ||  \\ \\____      | \\ \\    \\ |    | |    |  |    \\     |      ___/           |  |     |    |  |    \\     |      ___/     "); 
    wmove(main_Win, 25, 1); 
    wprintw(main_Win, "%s", "| \\     \\___|//    /\\    \\|___|/   \\|___/     /|  \\|     \\|    | |     \\/      \\    |      \\  ____   __  /   / __  |     \\/      \\    |      \\  ____ "); 
    wmove(main_Win, 26, 1); 
    wprintw(main_Win, "%s", "|  \\     \\   |    |/ \\    \\            /     / |   |\\         /| |\\      /\\     \\  /     /\\ \\/    \\ /  \\/   /_/  | |\\      /\\     \\  /     /\\ \\/    \\ "); 
    wmove(main_Win, 27, 1); 
    wprintw(main_Win, "%s", " \\  \\_____\\  |\\____\\ /____/|          /_____/  /   | \\_______/ | | \\_____\\ \\_____\\/_____/ |\\______||____________/| | \\_____\\ \\_____\\/_____/ |\\______| "); 
    wmove(main_Win, 28, 1);
    wprintw(main_Win, "%s","  \\ |     |  | |   ||    | |          |     | /     \\ |     | /  | |     | |     ||     | | |     ||           | / | |     | |     ||     | | |     | ");
    wmove(main_Win, 29, 1);
    wprintw(main_Win, "%s","   \\|_____|   \\|___||____|/           |_____|/       \\|_____|/    \\|_____|\\|_____||_____|/ \\|_____||___________|/   \\|_____|\\|_____||_____|/ \\|_____| ");
    wmove(main_Win, 45, 53);
    wprintw(main_Win, "%s","<-------- Press Space To Continue -------->");
    wrefresh(main_Win);
    while (true) {
        if (getch() == ' ') break;
    }
}

void load_background::probar(WINDOW *main_Win){
    wclear(main_Win);
    box(main_Win, '.', '.');
    wrefresh(main_Win);
    int rate=0;
    char pro[102];
    memset(pro,'\0',sizeof(pro));
    const char* spin="-\\|/";
    wmove(main_Win,30,60);
    wprintw(main_Win, "%s", "<-------- Loading -------->");
    wmove(main_Win,25,5);
    while (rate <= 100){
        wprintw(main_Win, "[%-100s][%d%][%c]\r", pro, rate, spin[ rate%4]);
        pro[ rate++ ] = '=';
        usleep(30000);
        fflush(stdout);
        wrefresh(main_Win);
    }
    wprintw(main_Win, "\n");
    wrefresh(main_Win);
}

void load_background::background_story(WINDOW *main_Win) {
    wclear(main_Win);
    box(main_Win, '.', '.');
    wrefresh(main_Win);
    while (true) {
        wmove(main_Win, 18, 2);
        wprintw(main_Win, "%s", "With the rapid development of human space technology");
        wrefresh(main_Win);
        usleep(1200000);
        wmove(main_Win, 20, 2);
        wprintw(main_Win, "%s", "Hope crystals are being developed and used by more and more scientists as a core energy source");
        wrefresh(main_Win);
        usleep(1200000);
        wmove(main_Win, 22, 2);
        wprintw(main_Win, "%s", "Human society also began to gradually divide into two factions because of the competition for crystal resources");
        wrefresh(main_Win);
        usleep(1200000);
        wmove(main_Win, 24, 2);
        wprintw(main_Win, "%s", "The ordinary people who stayed on Earth formed the Earth Federation, while the new humans who moved to the moons established the Planetary Alliance");
        wrefresh(main_Win);
        usleep(1200000);
        wmove(main_Win, 26, 2);
        wprintw(main_Win, "%s", "And the two forces began to develop their own armaments, and the strife began. ");
        wrefresh(main_Win);
        usleep(1200000);
        wmove(main_Win, 28, 2);
        wprintw(main_Win, "%s", "Across the twelve constellations, a war for the crystals starts, and the reckless war ignites the quiet sea of stars.");
        wrefresh(main_Win);
        usleep(1200000);
        break;
    }
    wmove(main_Win, 45, 53);
    wprintw(main_Win, "%s","<-------- Press Space To Continue -------->");
    wrefresh(main_Win);
    while (true) {
        if (getch() == ' ') break;
    }
}


