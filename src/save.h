#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"
using namespace std;

class Save{
    public:
        struct record{
	        string username;
            int score;
            record(string _username, int _score){
                username = _username;
                score = _score;
            }
        };
        string file;
        string username;
        vector<record> read(string file);
        Save();
        void insert_rank(string file, string username, int score);
};
