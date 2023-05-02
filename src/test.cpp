#include <iostream>
#include <vector>
#include <string>
#include <cstring>
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
    endwin();
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
        wmove(main_Win, 2, 38);
        wprintw(main_Win,"%s","######################################################################");
        wmove(main_Win, 3, 38);
        wprintw(main_Win,"%s","##########################,,tt,,iiii,,::,,tt##########################");
        wmove(main_Win, 4, 38);
        wprintw(main_Win,"%s","####################..tt::;;ttjjttttttiii;;ii;;;ii####################");
        wmove(main_Win, 5, 38);
        wprintw(main_Win,"%s","##################,,,,::;;iiiiiiffiittiiiitt,,ffjjjj##################");
        wmove(main_Win, 6, 38);
        wprintw(main_Win,"%s","##############,,;;;;;;tt;;;;iittjj,,iijjDDGGLLLLLLffffff##############");
        wmove(main_Win, 7, 38);
        wprintw(main_Win,"%s","############ii;;;;;;iittjjjjjjffffffffttttffjjLLGGff;;;;ff############");
        wmove(main_Win, 8, 38);
        wprintw(main_Win,"%s","##########::;;iiiijjjjffLLffffff;;iittttLLLLjjLLLLff,,;;ffff##########");
        wmove(main_Win, 9, 38);
        wprintw(main_Win,"%s","##########,,ttjjjjff..ttjjjjjj::ttiittGGGGiittGGjjttLLttttjj##########");
        wmove(main_Win, 10, 38);
        wprintw(main_Win,"%s","########iittjjttttiijjGGLLiiffiijjjjjjffLL;;;;....ff,,LLffffff########");
        wmove(main_Win, 11, 38);
        wprintw(main_Win,"%s","######KKjjjjffff;;jjffii,,jj,,;;jjffjj,,,,ffjjDDGG;;ii::ffttjj########");
        wmove(main_Win, 12, 38);
        wprintw(main_Win,"%s","######tt;;ffffjjii::::;....jj:;;;;;;;;LLLLGGGGDDGGDDGGffffGGttff######");
        wmove(main_Win, 13, 38);
        wprintw(main_Win,"%s","######iiiijjjjttLL::;;,,tt::jjttttttGGiiLLLLjjGGLLLLjjttjjttLLff######");
        wmove(main_Win, 14, 38);
        wprintw(main_Win,"%s","####iiiiff;;jjiiGGLL..ii;;iitt..;;LLtt::::jjDDDDGGDDffffGGjj;;LLDD####");
        wmove(main_Win, 15, 38);
        wprintw(main_Win,"%s","####ttffttLLttGGttGG;;jjfftt..,,ttffGG;;,,jjLLLLDDLLDDLLLLffttLLLL####");
        wmove(main_Win, 16, 38);
        wprintw(main_Win,"%s","####jjjjLL....ffGGGGGGffttiijjffLLLLGGffEEEEGGLLGGDDLLffGGLLffffGG####");
        wmove(main_Win, 17, 38);
        wprintw(main_Win,"%s","####jjjjiiDD;;;;ttiijjjjttjjffffffLLGGDDDD::DDGGiiLLDDGGLLLLLLLLff####");
        wmove(main_Win, 18, 38);
        wprintw(main_Win,"%s","####ttLLLLiiLLLLGGDDGG;;;;..jjffLLffLLjjjjDDLLGGLL;;ffffGGffGGLLLL####");
        wmove(main_Win, 19, 38);
        wprintw(main_Win,"%s","####ttLLGGGGffDDLLLLGGff,,;;ffffffLLLLGGffGGGGGGLLDD;;jjGGLLffffLL####");
        wmove(main_Win, 20, 38);
        wprintw(main_Win,"%s","####ttLLLLtttt,,,,tt::::::::,,ff::::ffGGDDDDffGGDDDDff::GGLLffffLL####");
        wmove(main_Win, 21, 38);
        wprintw(main_Win,"%s","####;;,,,,iiffGGKK,,,,LLffGGGG,,....::::LLDDLLffEELLffDDLLGGjjffGG####");
        wmove(main_Win, 22, 38);
        wprintw(main_Win,"%s","####::,,,,::::,,,,;;;;LLDDDDGGiiLLjjjj......iiLLDDttDDDD,,GGLLffKK####");
        wmove(main_Win, 23, 38);
        wprintw(main_Win,"%s","######,,..ffDDttttGGGGLL......DD..ttLLLLjj,,..;;;;jjLLff,,ttttff######");
        wmove(main_Win, 24, 38);
        wprintw(main_Win,"%s","######tt..,,ff,,;;,,LLLL,,::,,....;;;;LLffEEiiLL..::::tt;;ttGGGG######");
        wmove(main_Win, 25, 38);
        wprintw(main_Win,"%s","########::,,iitttttt;;jj;;::,,,,::;;ff,,iiiiDD;;jjii,,,,iiLLGG########");
        wmove(main_Win, 26, 38);
        wprintw(main_Win,"%s","########ii,,;;tt::tt..,,,,ii,,,,;;ttiijjjjjj,,ttLLLLEE;;ttffGG########");
        wmove(main_Win, 27, 38);
        wprintw(main_Win,"%s","##########tt::GG,,,,jj::ff::;;,,,,GG,,DD,,::,,ttGGii::ttffff##########");
        wmove(main_Win, 28, 38);
        wprintw(main_Win,"%s","############jjjjttttGGDD;;::::ii,,,,::;;iijj::;;iittiittjjKK##########");
        wmove(main_Win, 29, 38);
        wprintw(main_Win,"%s","############ff;;,,,,tt::::::,,::::::::,,::;;tt;;iiiiiittGG############");
        wmove(main_Win, 30, 38);
        wprintw(main_Win,"%s","################;;;;::,,::,,::,,::::::::::::,,,,;;LLjjGG##############");
        wmove(main_Win, 31, 38);
        wprintw(main_Win,"%s","##################ii;;;;,,;;::::::::,,,,,,,,;;;;iiff##################");
        wmove(main_Win, 32, 38);
        wprintw(main_Win,"%s","######################ii,,,,,,,,,,,,,,;;;;;;iittWW####################");
        wmove(main_Win, 33, 38);
        wprintw(main_Win,"%s","##########################;;iiii;;;;;;iiiijj##########################");
        wmove(main_Win, 34, 38);
        wprintw(main_Win,"%s","######################################################################");
        wrefresh(main_Win);
        wmove(main_Win, 37, 10);
        wprintw(main_Win, "%s", "With the rapid development of human space technology");
        wrefresh(main_Win);
        usleep(1200000);
        wmove(main_Win, 39, 10);
        wprintw(main_Win, "%s", "Hope crystals are being developed and used by more and more scientists as a core energy source");
        wrefresh(main_Win);
        usleep(1200000);
        wmove(main_Win, 41, 10);
        wprintw(main_Win, "%s", "Human society also began to gradually divide into two factions because of the competition for crystal resources");
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

    wclear(main_Win);
    box(main_Win, '.', '.');
    wrefresh(main_Win);
    wmove(main_Win,8,1);
    wprintw(main_Win, "%s", "                  ............]]O\\]...........                                                                                                               ");
    wmove(main_Win,9,1);
    wprintw(main_Win, "%s", "                .....,]/@@@@@@@@@@@@@@@@@@@]`...............                                                        ........................................ ");
    wmove(main_Win,10,1);
    wprintw(main_Win, "%s", "                ..[@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O\\]........                                                         ............]]]]OO@@@@@@@@@@@@@@@@@@@@`");
    wmove(main_Win,11,1);
    wprintw(main_Win, "%s", "                    ..,\\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@]`.................................... ....    ......]]]]]/O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^   ");
    wmove(main_Win,12,1);
    wprintw(main_Win, "%s", "                    ......,[O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/`..   ");
    wmove(main_Win,13,1);
    wprintw(main_Win, "%s", "                        ........[@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O[[.. ....... ");
    wmove(main_Win,14,1);
    wprintw(main_Win, "%s", "                   .    ............[\\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/[...........           ");
    wmove(main_Win,15,1);
    wprintw(main_Win, "%s", "    ...................,@@@@@@@@@@@@\\]`..,\\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O[[`.....                      ");
    wmove(main_Win,16,1);
    wprintw(main_Win, "%s", "    ........]/@@@OO]]]`=@@@@@@@@@@@@@@@@@@\\]..O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/[[`..............                       ");
    wmove(main_Win,17,1);
    wprintw(main_Win, "%s", ".....,]@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/`.........                                   ");
    wmove(main_Win,18,1);
    wprintw(main_Win, "%s", "./@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@[`.....                                           ");
    wmove(main_Win,19,1);
    wprintw(main_Win, "%s", ".......[\\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@[..                                                   ");
    wmove(main_Win,20,1);
    wprintw(main_Win, "%s", "    ..........,\\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/`......                                                   ");
    wmove(main_Win,21,1);
    wprintw(main_Win, "%s", "            ....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/[......                                                       ");
    wmove(main_Win,22,1);
    wprintw(main_Win, "%s", "            ...=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/`......                                                           ");
    wmove(main_Win,23,1);
    wprintw(main_Win, "%s", "            ...=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@`.                                                                   ");
    wmove(main_Win,24,1);
    wprintw(main_Win, "%s", "            ....,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/`..=@@@@@@@@@@@@@@@@@@@@@@@O...                                                                   ");
    wmove(main_Win,25,1);
    wprintw(main_Win, "%s", "                ...[@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@[[.....   .=@@@@@@@@@@@@@@@@@@@@@@^....                                                                   ");
    wmove(main_Win,26,1);
    wprintw(main_Win, "%s", "                ...........,@@@@@@@@@@@@@@@@@@@@/...........   .=@@@@@@@@@@@@@@@@@@@@@`.                                                                       ");
    wmove(main_Win,27,1);
    wprintw(main_Win, "%s", "                        ...,@@@@@@@@@@@@@@@@@@@`....           .=@@@@@@@@@@@@@@@@@@@@...                                                                       ");
    wmove(main_Win,28,1);
    wprintw(main_Win, "%s", "                        ..=@@@@@@@@@@@@@@@@@@/......           .O@@@@@@@@@@@@@@@@@@/....                                                                       ");
    wmove(main_Win,29,1);
    wprintw(main_Win, "%s", "                    ..../@@@@@@@@@@@@@@@@@@/....            ....O@@@@@@@@@@@@@@@@@`.                                                                           ");
    wmove(main_Win,30,1);
    wprintw(main_Win, "%s", "                    ..,@@@@@@@@@@@@@@@@@/[`.....            ....@@@@@@@@@@@@@@@@@^..                                                                           ");
    wmove(main_Win,31,1);
    wprintw(main_Win, "%s", "                ....,@@@@@@O/[[`............                ...=@@@@@@@@@@@@@@@@^...                                                                           ");
    wmove(main_Win,32,1);
    wprintw(main_Win, "%s", "                .....................                       ...=@@@@@@@@@@@@@@@`....                                                                           ");
    wmove(main_Win,33,1);
    wprintw(main_Win, "%s", "                                                            ...=@@@@@@@@@@@@@@..                                                                               ");
    wmove(main_Win,34,1);
    wprintw(main_Win, "%s", "                                                            ...=@@@@@@@@@@/`....                                                                               ");
    wmove(main_Win,35,1);
    wprintw(main_Win, "%s", "                                                            ...@@@@@@@O[....                                                                                   ");
    wmove(main_Win,36,1);
    wprintw(main_Win, "%s", "                                                            ..=@@@O[........                                                                            ");
    wmove(main_Win, 37, 2);
    wprintw(main_Win, "%s", "The ordinary people who stayed on Earth formed the Earth Federation, while the new humans who moved to the moons established the Planetary Alliance");
    wrefresh(main_Win);
    usleep(1200000);
    wmove(main_Win, 39, 2);
    wprintw(main_Win, "%s", "And the two forces began to develop their own armaments, and the strife began. ");
    wrefresh(main_Win);
    usleep(1200000);
    wmove(main_Win, 41, 2);
    wprintw(main_Win, "%s", "Across the twelve constellations, a war for the crystals starts, and the reckless war ignites the quiet sea of stars.");
    wrefresh(main_Win);
    usleep(1200000);
    wmove(main_Win, 45, 53);
    wprintw(main_Win, "%s","<-------- Press Space To Continue -------->");
    wrefresh(main_Win);
    while (true) {
        if (getch() == ' ') break;
    }
}



#include <iostream>
#include <vector>
#include <string>
#include <cstring>
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
    endwin();
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
        wmove(main_Win, 2, 38);
        wprintw(main_Win,"%s","######################################################################");
        wmove(main_Win, 3, 38);
        wprintw(main_Win,"%s","##########################,,tt,,iiii,,::,,tt##########################");
        wmove(main_Win, 4, 38);
        wprintw(main_Win,"%s","####################..tt::;;ttjjttttttiii;;ii;;;ii####################");
        wmove(main_Win, 5, 38);
        wprintw(main_Win,"%s","##################,,,,::;;iiiiiiffiittiiiitt,,ffjjjj##################");
        wmove(main_Win, 6, 38);
        wprintw(main_Win,"%s","##############,,;;;;;;tt;;;;iittjj,,iijjDDGGLLLLLLffffff##############");
        wmove(main_Win, 7, 38);
        wprintw(main_Win,"%s","############ii;;;;;;iittjjjjjjffffffffttttffjjLLGGff;;;;ff############");
        wmove(main_Win, 8, 38);
        wprintw(main_Win,"%s","##########::;;iiiijjjjffLLffffff;;iittttLLLLjjLLLLff,,;;ffff##########");
        wmove(main_Win, 9, 38);
        wprintw(main_Win,"%s","##########,,ttjjjjff..ttjjjjjj::ttiittGGGGiittGGjjttLLttttjj##########");
        wmove(main_Win, 10, 38);
        wprintw(main_Win,"%s","########iittjjttttiijjGGLLiiffiijjjjjjffLL;;;;....ff,,LLffffff########");
        wmove(main_Win, 11, 38);
        wprintw(main_Win,"%s","######KKjjjjffff;;jjffii,,jj,,;;jjffjj,,,,ffjjDDGG;;ii::ffttjj########");
        wmove(main_Win, 12, 38);
        wprintw(main_Win,"%s","######tt;;ffffjjii::::;....jj:;;;;;;;;LLLLGGGGDDGGDDGGffffGGttff######");
        wmove(main_Win, 13, 38);
        wprintw(main_Win,"%s","######iiiijjjjttLL::;;,,tt::jjttttttGGiiLLLLjjGGLLLLjjttjjttLLff######");
        wmove(main_Win, 14, 38);
        wprintw(main_Win,"%s","####iiiiff;;jjiiGGLL..ii;;iitt..;;LLtt::::jjDDDDGGDDffffGGjj;;LLDD####");
        wmove(main_Win, 15, 38);
        wprintw(main_Win,"%s","####ttffttLLttGGttGG;;jjfftt..,,ttffGG;;,,jjLLLLDDLLDDLLLLffttLLLL####");
        wmove(main_Win, 16, 38);
        wprintw(main_Win,"%s","####jjjjLL....ffGGGGGGffttiijjffLLLLGGffEEEEGGLLGGDDLLffGGLLffffGG####");
        wmove(main_Win, 17, 38);
        wprintw(main_Win,"%s","####jjjjiiDD;;;;ttiijjjjttjjffffffLLGGDDDD::DDGGiiLLDDGGLLLLLLLLff####");
        wmove(main_Win, 18, 38);
        wprintw(main_Win,"%s","####ttLLLLiiLLLLGGDDGG;;;;..jjffLLffLLjjjjDDLLGGLL;;ffffGGffGGLLLL####");
        wmove(main_Win, 19, 38);
        wprintw(main_Win,"%s","####ttLLGGGGffDDLLLLGGff,,;;ffffffLLLLGGffGGGGGGLLDD;;jjGGLLffffLL####");
        wmove(main_Win, 20, 38);
        wprintw(main_Win,"%s","####ttLLLLtttt,,,,tt::::::::,,ff::::ffGGDDDDffGGDDDDff::GGLLffffLL####");
        wmove(main_Win, 21, 38);
        wprintw(main_Win,"%s","####;;,,,,iiffGGKK,,,,LLffGGGG,,....::::LLDDLLffEELLffDDLLGGjjffGG####");
        wmove(main_Win, 22, 38);
        wprintw(main_Win,"%s","####::,,,,::::,,,,;;;;LLDDDDGGiiLLjjjj......iiLLDDttDDDD,,GGLLffKK####");
        wmove(main_Win, 23, 38);
        wprintw(main_Win,"%s","######,,..ffDDttttGGGGLL......DD..ttLLLLjj,,..;;;;jjLLff,,ttttff######");
        wmove(main_Win, 24, 38);
        wprintw(main_Win,"%s","######tt..,,ff,,;;,,LLLL,,::,,....;;;;LLffEEiiLL..::::tt;;ttGGGG######");
        wmove(main_Win, 25, 38);
        wprintw(main_Win,"%s","########::,,iitttttt;;jj;;::,,,,::;;ff,,iiiiDD;;jjii,,,,iiLLGG########");
        wmove(main_Win, 26, 38);
        wprintw(main_Win,"%s","########ii,,;;tt::tt..,,,,ii,,,,;;ttiijjjjjj,,ttLLLLEE;;ttffGG########");
        wmove(main_Win, 27, 38);
        wprintw(main_Win,"%s","##########tt::GG,,,,jj::ff::;;,,,,GG,,DD,,::,,ttGGii::ttffff##########");
        wmove(main_Win, 28, 38);
        wprintw(main_Win,"%s","############jjjjttttGGDD;;::::ii,,,,::;;iijj::;;iittiittjjKK##########");
        wmove(main_Win, 29, 38);
        wprintw(main_Win,"%s","############ff;;,,,,tt::::::,,::::::::,,::;;tt;;iiiiiittGG############");
        wmove(main_Win, 30, 38);
        wprintw(main_Win,"%s","################;;;;::,,::,,::,,::::::::::::,,,,;;LLjjGG##############");
        wmove(main_Win, 31, 38);
        wprintw(main_Win,"%s","##################ii;;;;,,;;::::::::,,,,,,,,;;;;iiff##################");
        wmove(main_Win, 32, 38);
        wprintw(main_Win,"%s","######################ii,,,,,,,,,,,,,,;;;;;;iittWW####################");
        wmove(main_Win, 33, 38);
        wprintw(main_Win,"%s","##########################;;iiii;;;;;;iiiijj##########################");
        wmove(main_Win, 34, 38);
        wprintw(main_Win,"%s","######################################################################");
        wrefresh(main_Win);
        wmove(main_Win, 37, 10);
        wprintw(main_Win, "%s", "With the rapid development of human space technology");
        wrefresh(main_Win);
        usleep(1200000);
        wmove(main_Win, 39, 10);
        wprintw(main_Win, "%s", "Hope crystals are being developed and used by more and more scientists as a core energy source");
        wrefresh(main_Win);
        usleep(1200000);
        wmove(main_Win, 41, 10);
        wprintw(main_Win, "%s", "Human society also began to gradually divide into two factions because of the competition for crystal resources");
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

    wclear(main_Win);
    box(main_Win, '.', '.');
    wrefresh(main_Win);
    wmove(main_Win,8,1);
    wprintw(main_Win, "%s", "                  ............]]O\\]...........                                                                                                               ");
    wmove(main_Win,9,1);
    wprintw(main_Win, "%s", "                .....,]/@@@@@@@@@@@@@@@@@@@]`...............                                                        ........................................ ");
    wmove(main_Win,10,1);
    wprintw(main_Win, "%s", "                ..[@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O\\]........                                                         ............]]]]OO@@@@@@@@@@@@@@@@@@@@`");
    wmove(main_Win,11,1);
    wprintw(main_Win, "%s", "                    ..,\\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@]`.................................... ....    ......]]]]]/O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^   ");
    wmove(main_Win,12,1);
    wprintw(main_Win, "%s", "                    ......,[O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/`..   ");
    wmove(main_Win,13,1);
    wprintw(main_Win, "%s", "                        ........[@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O[[.. ....... ");
    wmove(main_Win,14,1);
    wprintw(main_Win, "%s", "                   .    ............[\\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/[...........           ");
    wmove(main_Win,15,1);
    wprintw(main_Win, "%s", "    ...................,@@@@@@@@@@@@\\]`..,\\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O[[`.....                      ");
    wmove(main_Win,16,1);
    wprintw(main_Win, "%s", "    ........]/@@@OO]]]`=@@@@@@@@@@@@@@@@@@\\]..O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/[[`..............                       ");
    wmove(main_Win,17,1);
    wprintw(main_Win, "%s", ".....,]@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/`.........                                   ");
    wmove(main_Win,18,1);
    wprintw(main_Win, "%s", "./@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@[`.....                                           ");
    wmove(main_Win,19,1);
    wprintw(main_Win, "%s", ".......[\\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@[..                                                   ");
    wmove(main_Win,20,1);
    wprintw(main_Win, "%s", "    ..........,\\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/`......                                                   ");
    wmove(main_Win,21,1);
    wprintw(main_Win, "%s", "            ....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/[......                                                       ");
    wmove(main_Win,22,1);
    wprintw(main_Win, "%s", "            ...=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/`......                                                           ");
    wmove(main_Win,23,1);
    wprintw(main_Win, "%s", "            ...=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@`.                                                                   ");
    wmove(main_Win,24,1);
    wprintw(main_Win, "%s", "            ....,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/`..=@@@@@@@@@@@@@@@@@@@@@@@O...                                                                   ");
    wmove(main_Win,25,1);
    wprintw(main_Win, "%s", "                ...[@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@[[.....   .=@@@@@@@@@@@@@@@@@@@@@@^....                                                                   ");
    wmove(main_Win,26,1);
    wprintw(main_Win, "%s", "                ...........,@@@@@@@@@@@@@@@@@@@@/...........   .=@@@@@@@@@@@@@@@@@@@@@`.                                                                       ");
    wmove(main_Win,27,1);
    wprintw(main_Win, "%s", "                        ...,@@@@@@@@@@@@@@@@@@@`....           .=@@@@@@@@@@@@@@@@@@@@...                                                                       ");
    wmove(main_Win,28,1);
    wprintw(main_Win, "%s", "                        ..=@@@@@@@@@@@@@@@@@@/......           .O@@@@@@@@@@@@@@@@@@/....                                                                       ");
    wmove(main_Win,29,1);
    wprintw(main_Win, "%s", "                    ..../@@@@@@@@@@@@@@@@@@/....            ....O@@@@@@@@@@@@@@@@@`.                                                                           ");
    wmove(main_Win,30,1);
    wprintw(main_Win, "%s", "                    ..,@@@@@@@@@@@@@@@@@/[`.....            ....@@@@@@@@@@@@@@@@@^..                                                                           ");
    wmove(main_Win,31,1);
    wprintw(main_Win, "%s", "                ....,@@@@@@O/[[`............                ...=@@@@@@@@@@@@@@@@^...                                                                           ");
    wmove(main_Win,32,1);
    wprintw(main_Win, "%s", "                .....................                       ...=@@@@@@@@@@@@@@@`....                                                                           ");
    wmove(main_Win,33,1);
    wprintw(main_Win, "%s", "                                                            ...=@@@@@@@@@@@@@@..                                                                               ");
    wmove(main_Win,34,1);
    wprintw(main_Win, "%s", "                                                            ...=@@@@@@@@@@/`....                                                                               ");
    wmove(main_Win,35,1);
    wprintw(main_Win, "%s", "                                                            ...@@@@@@@O[....                                                                                   ");
    wmove(main_Win,36,1);
    wprintw(main_Win, "%s", "                                                            ..=@@@O[........                                                                            ");
    wmove(main_Win, 37, 2);
    wprintw(main_Win, "%s", "The ordinary people who stayed on Earth formed the Earth Federation, while the new humans who moved to the moons established the Planetary Alliance");
    wrefresh(main_Win);
    usleep(1200000);
    wmove(main_Win, 39, 2);
    wprintw(main_Win, "%s", "And the two forces began to develop their own armaments, and the strife began. ");
    wrefresh(main_Win);
    usleep(1200000);
    wmove(main_Win, 41, 2);
    wprintw(main_Win, "%s", "Across the twelve constellations, a war for the crystals starts, and the reckless war ignites the quiet sea of stars.");
    wrefresh(main_Win);
    usleep(1200000);
    wmove(main_Win, 45, 53);
    wprintw(main_Win, "%s","<-------- Press Space To Continue -------->");
    wrefresh(main_Win);
    while (true) {
        if (getch() == ' ') break;
    }
}


#include <iostream>
#include <vector>
#include <string>
#include <cstring>
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
    endwin();
    delwin(main_Win);   //删除窗口
}

void load_background::start_win(WINDOW *main_Win){

