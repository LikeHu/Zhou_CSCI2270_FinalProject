#ifndef __SUDOKU_H__
#define __SUDOKU_H__
#include "mylist.h"

class Sudoku
{
public:
    Sudoku(){}
    //check(x,y) vaild or not.
    void valid(int x, int y, MyList<int>& validList);
    
    // reset the initial
    void init();
    
    // print the map
    void debug();
    
    // solve the Sudoku 
    bool calc(int x=0, int y=0);
    
public:
    int value[9][9];
};

#endif
