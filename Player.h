#include <vector>

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class User{

private:

    string name;
    int time;
    string GridSize;
    int boombs;
    int playersNum;



public:

    int getPlayersNum();


    void setPlayersNum();


    void setName(string PlayerName);


    void setTime(int PlayerTime);


    void setGridSize(int x, int y);


    vector<User> getLines(vector<User> people);


    int getTime();


    void printLeader(vector<User> list);


    void printDetails(User test);

    
    void setBoombs(int b);


    int getBoombs();


};

#endif