#include <iostream>
#include <string>
#include <time.h>
#include <chrono>
#include <fstream>
#include <vector>
#include "Cells.h"
#include "Player.h"

using namespace std;




int User::getPlayersNum(){
    return playersNum;
}



void User::setPlayersNum(){
    fstream File;
    File.open("Ranks.txt");

    if(File.is_open()){
        string lines;
        int x = 0;
        while(getline(File, lines)){
            if(lines != ""){
                x++;
            }
        }

        playersNum = x;
        File.close();
    }else{
        cout << "File Err" << endl;
    }
}


void User::setName(string PlayernName){
    name = PlayernName;
}



void User::setTime(int PlayerTime){
        time = PlayerTime;
}



void User::setGridSize(int x, int y){
    GridSize = to_string(x) + "x" + to_string(y);
}



vector<User> User::getLines(vector<User> people){
    ifstream File("Ranks.txt");     

    if(File.is_open()){
        string garbage;
        string names;
        string times;
        string grid;
        string nBombs;

        for(int i=1; i<=playersNum+1; i++){


            if(getline(File, garbage, ' ')){
            }


            if(getline(File, names, ',')){
                people.at(i).name = names;
            }


            if(getline(File, times, 's')){
                people.at(i).time = stoi(times);
            }


            if(getline(File, garbage, ' ')){
            }


            if(getline(File, grid, ',')){
                people.at(i).GridSize = grid;
            }

            if(getline(File, nBombs, 'B')){
                people.at(i).boombs = stoi(nBombs);
            }

            if(getline(File, garbage)){
            }
        }
        File.close();
        return people;
    }else{
        cout << "File Err" << endl;
        return people;
    }
}


int User::getTime(){
    return time;
}


void User::printLeader(vector<User> list){
    ofstream File("Ranks.txt", ios::out | ios::trunc);
    int space = -1;

    if(File.is_open()){
        for(int i=0; i<=playersNum; i++){
            File << i+1 << "- ";
            File << list.at(i).name << ", ";
            File << list.at(i).time << "s, ";
            File << list.at(i).GridSize << ", ";
            File << list.at(i).boombs << " Bombs";

            space++;
            if(space < playersNum){
                File << "\n";
            }

        }

        File.close();
    }else{
        cout << "File Err" << endl;
    }
}



void User::printDetails(User test){
    cout << test.name << endl;
    cout << test.time << endl;
}


void User::setBoombs(int b){
    boombs = b;
}


int User::getBoombs(){
    return boombs;
}