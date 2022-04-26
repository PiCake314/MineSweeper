#ifndef CELLS_H
#define CELLS_H

class Cell{

public:

    bool bomb;
    int NumofBombs;
    bool revealed;
    bool flag;



    Cell();



    static void spreadBombs(Cell GridBomd[][100], int W, int H, int Bombs);



    void CountBombs(Cell GridCount[][100], int x, int y);



    bool isBomb(int x, int y, Cell GridCheck[][100]);



    bool AllRev(Cell GridCheck[][100], int x, int y);



    void revealSlot(int x, int y, Cell GridVeal[][100], int W, int H, bool lost, bool debug);



    void flagSlot(int x, int y, Cell GridFlag[][100], int W, int H, bool debug);



    void unFlagSlot(int x, int y, Cell GridFlag[][100], int W, int H);



    bool FindBomd(Cell Grid[][100], int x, int y);



};

#endif