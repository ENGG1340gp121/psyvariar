#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "save.h"
#include "Player.h"
using namespace std;
//Save.cpp is used to save the score of the player and read the score from the file
Save::Save(){

}

// operator to sort the vector
bool operator < (const Save::record& a, const Save::record& b){
    return a.score > b.score;
}
// input file name, read the file and return a vector of records
vector<Save::record> Save::read(string file){    
    vector<record> records;
    ifstream fin;
    // file written in format: username score
    fin.open(file);
    string line;
    while (getline(fin, line)){
        stringstream line_in(line);
        string username;
        int score;
        line_in >> username >> score;
        record r(username, score);
        records.push_back(r);
    }
    fin.close();
    sort(records.begin(), records.end());
    return records;
}

//input filename, username , and player's final score, insert the new score in the file 
void Save::insert_rank(string file, string username, int score){
    ofstream fout;
    fout.open(file, ios::app);
    username.erase(username.end()-1,username.end());
//    string output = username + " " + to_string(score);
    fout << username << " " << score << endl;
    fout.close();
}


