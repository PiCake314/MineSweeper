#include <iostream>
#include <string>
#include <time.h>
#include <chrono>
#include "Cells.h"

using namespace std;



// Rendering engine!

void printGrid(int s1, int s2, Cell Gridbomb[][100]){
    char state = (char)219;
    int Ycounter = 1;

    //  X Axis Numbers
    cout << "\n" << "     ";
    
    for(int Xcounter = 0; Xcounter < s1; Xcounter++){
        if(Xcounter+1 > 9){
            cout << "   " << Xcounter+1 << "     ";
        }
        if(Xcounter+1 < 10){
            cout << "    " << Xcounter+1 << "     ";
        }
    }

    cout << "\n";

    /* Print Grid */
    for(int Vert = 1; Vert < s2+1; Vert++){
        cout << "     ";

        for(int l = 0; l < s1; l++){
            cout << " -------  ";
        }

        cout << "\n" << "     ";

        //Actaul printing happens here :)
        for(int j = 0; j < 3; j++){
            if (j == 0){
                for(int k = 0; k < s1;  k++){
                    cout << "|    " << "   | ";
                }
                if(Ycounter > 9){
                    cout << "\n" << "  " << Ycounter << " ";          //Y Axis Numbers
                    Ycounter++;
                }
                if(Ycounter < 10){
                    cout << "\n" << "   " << Ycounter << " ";          //Y Axis Numbers
                    Ycounter++;
                }
            }

            else if (j == 1){
                for(int Horz=1; Horz<s1+1;  Horz++){
                    if(Gridbomb[Vert][Horz].revealed == 1){
                        if(Gridbomb[Vert][Horz].bomb == 1){
                            state = '*';
                            cout << "|   " << state << "   | ";         // Printing Bombs
                            state = (char)219;
                        }
                        else if(Gridbomb[Vert][Horz].NumofBombs == 0){
                            cout << "|    " << "   | ";
                        }
                        else {
                            cout << "|   " << Gridbomb[Vert][Horz].NumofBombs << "   | ";
                        }
                    }
                    else if(Gridbomb[Vert][Horz].flag == 1){
                            state = 'F';
                            cout << "|   " << state << "   | ";         //Flags
                            state = (char)219;
                        }
                        else{
                                cout << "|   " << state << "   | ";         //Question marks in the Middle                        
                            }
                    
                }
                cout << "\n" << "     ";
            }
            else if (j == 2){
                for(int k=0; k<s1;  k++){
                    cout << "|    " << "   | ";
                }
                cout << "\n" << "     ";
            }
        }


        for(int i = 0; i < s1; i++){
            cout << " -------  ";
        }

        cout << "\n";
    }
}



void won(Cell GridSearch[][100], int W, int H){
    for(int i=1; i<H+1; i++){
        for(int j=1; j<W+1; j++){
            if(GridSearch[i][j].bomb == 1){
                GridSearch[i][j].flagSlot(j, i, GridSearch, W+1, H+1, 1);
            }
        }
    }
    printGrid(W, H, GridSearch);
    cout << "YOU WIN! :)" << endl;
}



void lost(Cell GridSearch[][100], int W, int H){
    for(int i=1; i<H+1; i++){
        for(int j=1; j<W+1; j++){
            if(GridSearch[i][j].bomb == 1){
                GridSearch[i][j].revealSlot(j, i, GridSearch, W+1, H+1, 1, 1);
            }
        }
    }
    printGrid(W, H, GridSearch);
    cout << "YOU LOST! :(" << endl;
}





// Side functions!

bool is_digits(string str){
    for(int i=0; i<str.length(); i++){
        if(isdigit(str.at(i)) == 0){
            return 0;
        }
    }
    return 1;
}
