#include <iostream>
#include <string>
#include <time.h>
#include <chrono>
#include "Cells.h"

using namespace std;



Cell::Cell(){
    bomb = 0;
    revealed = 0;
    flag = 0;
    NumofBombs = 0;
}



void Cell::spreadBombs(Cell GridBomd[][100], int W, int H, int Bombs){
int x;
int y;
for(int i=0; i<Bombs; i++){
    while(true){
        x = rand()%W+1;
        y = rand()%H+1;

        if(GridBomd[y][x].bomb == 0){
            GridBomd[y][x].bomb = 1;
            break;
        }
        else{
            continue;
        }
    }
}
}



void Cell::CountBombs(Cell GridCount[][100], int x, int y){
    int MidX = x;
    int MidY = y;
    x--;
    y--;
    int z = x;


    for(int i=0; i<3; i++){
        x = z;
        for(int j=0; j<3; j++){
            if(GridCount[y][x].bomb == 1){
                GridCount[MidY][MidX].NumofBombs++;
            }
            x++;
        }
        y++;
    }
}



bool Cell::isBomb(int x, int y, Cell GridCheck[][100]){
    return GridCheck[y][x].bomb;
}


bool Cell::AllRev(Cell GridCheck[][100], int x, int y){
    for(int i=1; i<y+1; i++){
        for(int j=1; j<x+1; j++){
            if(GridCheck[i][j].isBomb(j, i, GridCheck) == 0){
                if(GridCheck[i][j].revealed == 0){
                    return 0;
                }
            }
        }
    }
    return 1;
}



void Cell::revealSlot(int x, int y, Cell GridVeal[][100], int W, int H, bool lost, bool debug){



    if(x < W+1 && x >= 1 && y < H+1 && y >= 1 && lost == 0){
        if(GridVeal[y][x].revealed == 0 && GridVeal[y][x].flag == 0){
            GridVeal[y][x].revealed = 1;
            CountBombs(GridVeal, x, y);

            if(GridVeal[y][x].NumofBombs == 0){
                for(int i=-1; i<2; i++){
                    for(int j=-1; j<2; j++){
                        revealSlot(x-j, y-i, GridVeal, W, H, 0, 1);
                    }
                }
            }
        }
        else if(GridVeal[y][x].flag == 1 && debug == 0){
            cout << "This is a flagged slot and canne be revealed. \nIf you wish to unFLag it, please choose the third option!" << endl;
        }
        else if(debug == 0){
            cout << "This slot has already been revealed. \nPlease Enter another values!" << endl;
        }
    }
    else if(debug == 0){
        cout << "Invalid Entry! \nPlease Try Again!" << endl;
    }


    // Losing Mechanisim!
    if(lost == 1){
        GridVeal[y][x].flag = 0;
        GridVeal[y][x].revealed = 1;
    }


}



void Cell::flagSlot(int x, int y, Cell GridFlag[][100], int W, int H, bool debug){
    if(x < W+1 && x >= 1 && y < H+1 && y >= 1){
        if(GridFlag[y][x].flag == 0 && GridFlag[y][x].revealed == 0){
            GridFlag[y][x].flag = 1;
        }
        else if(GridFlag[y][x].revealed == 1 && debug == 0){
            cout << "This is a revealed slot and can't be Flagged/unFlagged!" << endl;
        }
        else if(debug == 0){
            cout << "This slot has already been flagged. \nIf you wish to unFlag it, please choose the third option!" << endl;
        }
    }
    else{
        cout << "Invalid Entry! \nPlease Try Again!!" << endl;
    }
}



    void Cell::unFlagSlot(int x, int y, Cell GridFlag[][100], int W, int H){
    if(x < W+1 && x >= 1 && y < H+1 && y >= 1){
        if(GridFlag[y][x].flag == 1 && GridFlag[y][x].revealed == 0){
            GridFlag[y][x].flag = 0;
        }
        else if(GridFlag[y][x].revealed == 1){
            cout << "This is a revealed slot and can't be Flagged/unFlagged!" << endl;
        }
        else{
            cout << "This slot is not flagged. \nIf you wish to Flag it, please choose the second option!" << endl;
        }
    }
    else{
        cout << "Invalid Entry! \nPlease Try Again!!" << endl;
    }
}



    bool Cell::FindBomd(Cell Grid[][100], int x, int y){
        return Grid[y][x].bomb;
    }