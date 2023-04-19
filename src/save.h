#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"
using namespace std;

class Save{
    public: 
        string file;
        string username;
        Save();
        void create(string username);
        void rank(string username, int score);
        vector<record> read(string file);
        struct record{// this is a struct to store the username and score for the rank 
            string username;
            int score;
        };
       
}