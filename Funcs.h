#include "Cells.h"
#include "Player.h"

using namespace std;

#ifndef FUNCS_H
#define FUNCS_H


// Rendering engine!
void printGrid(int s1, int s2, Cell Gridbomb[][100]);


void won(Cell GridSearch[][100], int W, int H);


void lost(Cell GridSearch[][100], int W, int H);





// Side functions!
bool is_digits(string str);

#endif


bool HighScore(User x, User y){
    return x.getTime() < y.getTime();
}