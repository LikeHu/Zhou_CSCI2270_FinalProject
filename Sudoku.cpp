#include <iostream>
#include "sudoku.h"
using namespace std;

/*
Function prototype:
void Sudoku::init

Function description:
This function is to initial the Sudoku matrix
*/
void Sudoku::init()
{
	cout<<"Please input the initial 9*9 sudoku matrix: "<<endl;
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			cin>>value[i][j];
		}
	}
}
/*
Function prototype:
void Sudoku::valid(int x, int y, MyList<int>& validList)

Function description:
This function is to check the number in the Sudoku is vaild or not
*/
void Sudoku::valid(int x, int y, MyList<int>& validList)
{
	for(int m=1; m<=9; m++)
	{
		bool flag = true;
		for(int j = 0; j<9; j++)
		{
			if(value[x][j] == m) //every line can appear one time
			{
				flag = false;
				break;
			}
			if(value[j][y] == m) //every row can appear one time
			{
				flag = false;
				break;
			}
			
			int xx,yy;	//every 3*3 grid can appear one time.
			xx = (x/3)*3 + j/3;
			yy = (y/3)*3 + j%3;
			if(value[xx][yy] == m)
			{
				flag = false;
				break;
			}
		}
		
		if(flag) 
			validList.push_back(m);
	}
}
/*
Function prototype:
void Sudoku::debug

Function description:
Can use to debug, find the error, also can show the answer of the Sudoku.
*/
			
void Sudoku::debug()
{
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			cout<<value[i][j]<<" ";
		}
		cout<<endl;
	}
}

/*
Function prototype:
bool Sudoku::calc(int x, int y)

Function description:
This is the calucation function, use the recursion to try every possible number
*/

bool Sudoku::calc(int x, int y)
{
	while(value[x][y] != 0)
	{
		if(++y==9)
		{
			y=0;
			x++;
			
			if(x==9) // To the lower right corner and ended the game. 
				return true;
		}
	}
	
	if(value[x][y] != 0)  //ignore the number existed.
		return false;
	
	MyList<int> validList;
	valid(x, y, validList); //put all possible number in the grid to this list.
	
	if(validList.empty()) 
		return false;
		
	//Traversal this list,try every number.
	for(MyList<int>::Node* p=validList.front; p; p=p->next)
	{
		value[x][y] = p->value;
		if(calc(x,y)) 	//recursion
			return true;
		
		value[x][y]=0;
	}
	return false;
}
