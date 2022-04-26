#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <cctype>
#include <vector>
#include <chrono>
#include <algorithm>
#include "Funcs.h"
#include "Cells.h"
#include "Player.h"


using namespace std;
using namespace chrono;



// ----------------------------------------------------------
int main(){
srand(time(NULL));

User player;

cout << "Enter name: " << endl;
string Player_Name;
getline(cin, Player_Name);

player.setName(Player_Name);
player.setPlayersNum();


cout << "Choose difficulty: \n1-Easy \n2-Medium \n3-Hard" << endl;
string choice;
getline(cin, choice);


int diff;
int boom;

if(choice == "easy" || choice == "Easy" || choice == "EASY" || choice == "1"){
    diff = 4;
    boom = 2;
}
else if(choice == "Medium" || choice == "medium" || choice == "MEDUIM" || choice == "2"){
    diff = 8;
    boom = 8;
}
else if(choice == "Hard" || choice == "hard" || choice == "HARD" || choice == "3"){
    diff = 12;
    boom = 16;
}

// intializing Variables!
int GridSizeW = diff;
int GridSizeH = diff;
int bombs = 8;
Cell square[100][100];
bool LeaderBoard = 0;


//Actual game :)

player.setGridSize(GridSizeW, GridSizeH);
player.setBoombs(boom);

Cell::spreadBombs(square, GridSizeW, GridSizeH, bombs);

int flags = 0;
int xPos;
int yPos;
string input;
string xStr;
string yStr;



auto start = high_resolution_clock::now();
while(true){
    printGrid(GridSizeW, GridSizeH, square);

    cout << "Choose an option from the menu bellow: \n 1- Open \n 2- Flag \n 3- UnFlag" << endl;
    getline(cin, input);



    if(input == "open" || input == "Open" || input == "OPEN" || input == "1" ){

        cout << "Enter X value:" << endl;
        getline(cin, xStr);
        cout << "Enter Y value:" << endl;
        getline(cin, yStr);


        if(is_digits(yStr) != 0 && is_digits(xStr) != 0 && xStr != "" && yStr != ""){
            xPos = stoi(xStr);
            yPos = stoi(yStr);
            square[yPos][xPos].revealSlot(xPos, yPos, square, GridSizeW, GridSizeH, 0, 0);

            if(square[xPos][yPos].AllRev(square, GridSizeW, GridSizeH) == 0 && square[xPos][yPos].FindBomd(square, xPos, yPos) == 0){
                cout << "         Bombs left: " << bombs - flags << endl;
            }

        }
        else{
            cout << "Invalid Entry! \nPlease Try Again!" << endl;
        }


        if(square[xPos][yPos].AllRev(square, GridSizeW, GridSizeH)){
            auto stop = high_resolution_clock::now();
            auto time = duration_cast<seconds>(stop - start);

            won(square, GridSizeW, GridSizeH);
            player.setTime(time.count());
            // cout << "Time: " << time.count() << endl;


            int loop = time.count()/60;
            int sec = time.count();
            int mins = 0;
            for(int i=0; i<loop; i++){
                sec = sec - 60;
                mins++;
            }
            cout << "Time: " << mins << "m" << sec << "s" << endl;



            LeaderBoard = 1;
            break;
        }


        if(square[xPos][yPos].isBomb(xPos, yPos, square) != 0 && square[yPos][xPos].flag == 0){
            auto stop = high_resolution_clock::now();
            auto time = duration_cast<seconds>(stop - start);


            lost(square, GridSizeW, GridSizeH);
            // cout << "Time: " << time.count() << endl;


            int loop = time.count()/60;
            int sec = time.count();
            int mins = 0;
            for(int i=0; i<loop; i++){
                sec = sec - 60;
                mins++;
            }
            cout << "Time: " << mins << "m" << sec << "s" << endl;

            break;
        } 
    }



    else if(input == "flag" || input == "Flag" || input == "FLAG" || input == "2" ){

        cout << "Enter X value:" << endl;
        getline(cin, xStr);
        cout << "Enter Y value:" << endl;
        getline(cin, yStr);

        if(is_digits(yStr) != 0 && is_digits(xStr) != 0 && xStr != "" && yStr != ""){

            xPos = stoi(xStr);
            yPos = stoi(yStr);
            
            if(square[yPos][xPos].flag == 0 && square[yPos][xPos].revealed == 0){
                flags++;
            }

            square[xPos][yPos].flagSlot(xPos, yPos, square, GridSizeW, GridSizeH, 0);


            cout << "         Bombs left: " << bombs - flags << endl;
        }
        else{
            cout << "Invalid Entry! \nPlease Try Again!" << endl;
        }
    }



    else if(input == "UnFlag" || input == "unflag" || input == "Unflag" || input == "UNFLAG" || input == "3" ){

        cout << "Enter X value:" << endl;
        getline(cin, xStr);
        cout << "Enter Y value:" << endl;
        getline(cin, yStr);

        if(is_digits(yStr) != 0 && is_digits(xStr) != 0 && xStr != "" && yStr != ""){

            xPos = stoi(xStr);
            yPos = stoi(yStr);

            if(square[yPos][xPos].flag == 1){
                flags--;
            }
            
            square[xPos][yPos].unFlagSlot(xPos, yPos, square, GridSizeW, GridSizeH);
            


            cout << "         Bombs left: " << bombs - flags << endl;
        }
        else{
            cout << "Invalid Entry! \nPlease Try Again!" << endl;
        }

    }
    else{
        cout << "Failed to choose an option. \nPlease choose a valid choice!" << endl;
    }
}


if (LeaderBoard){
int PNum = player.getPlayersNum() + 1;

    vector<User> list(PNum);
    list.at(0) = player;

    list = player.getLines(list);

    sort(list.begin(), list.end(), HighScore);

    player.printLeader(list);

    // player.printDetails(player);
}




}



