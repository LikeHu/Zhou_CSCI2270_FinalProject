#ifndef __SUDOKU_H__
#define __SUDOKU_H__

class Sudoku
{
public:
    Sudoku():done(false){}
    
    // reset the initial
    bool init();
    
    // print the map
    void debug();
    
    // solve the Sudoku 
    int calc(int n = 0);
    
private:
    // check the value(x,y) wheather satisfied 
    bool check(int x, int y, int value);
    
public:
    bool done;
    int num[9][9];
};

#endif
