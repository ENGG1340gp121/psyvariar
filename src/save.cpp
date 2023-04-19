#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "save.h"
#include "Player.h"
using namespace std;

Save::Save(){
}

bool operator<(const record& a, const record& b) const{// operator to sort the vector
        return a.score < b.score;
    }

vector<record> Save::read(string file){ //read the file and store the data in a vector, return the sorted vector
    vector<record> records;
    ifstream fin;
    fin.open(file);// file written in format: username score
    string line;
    while (getline(fin, line)){
        stringstream line_in(line);
        string username;
        int score;
        line_in >> username >> score;
        record r;
        r.username = username;
        r.score = score;
        records.push_back(r);
    }
    sort(records.begin(), records.end());
    fin.close();
    return records;
}

void Save::insert_rank(string file,string username, int score){// insert the new score in the file 
    ofstream fout;
    fout.open(file, ios::out|ios::app);
    fout << username << " " << score << endl;
    fout.close();
}

