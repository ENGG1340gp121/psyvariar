#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
// window size 98*24 is suitable 
void set_windows(){
    system("mode con cols=98 lines=60");
}

void print_pattern(string file){
    ifstream fin;
    fin.open(file);
    string line;
    if (fin.fail()){
        cout << "Title file missing";
    }
    while (getline(fin, line)){
        cout << line ;
    }
    fin.close();
}

void title(string file){
    cout << "\033[40m"; 
    cout << "\033[1m";
    cout << "\033[31m";
    cout << "\033[7m";
    cout << "\033[6m";
    print_pattern(file);
}

int main(){
    set_windows();
    title("title.txt");
    return 0;
}