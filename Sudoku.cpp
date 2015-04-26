#include <iostream>
#include "sudoku.h"
using namespace std;

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

void Sudoku::valid(int x, int y, MyList<int>& validList)
{
	for(int m=1; m<=9; m++)
	{
		bool flag = true;
		for(int j = 0; j<9; j++)
		{
			if(value[x][j] == m) 
			{
				flag = false;
				break;
			}
			if(value[j][y] == m) 
			{
				flag = false;
				break;
			}
			
			int xx,yy;
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

bool Sudoku::calc(int x, int y)
{
	while(value[x][y] != 0)
	{
		if(++y==9)
		{
			y=0;
			x++;
			
			if(x==9) 
				return true;
		}
	}
	
	if(value[x][y] != 0) 
		return false;
	
	MyList<int> validList;
	valid(x, y, validList); 
	
	if(validList.empty()) 
		return false;
		
	for(MyList<int>::Node* p=validList.front; p; p=p->next)
	{
		value[x][y] = p->value;
		if(calc(x,y)) 
			return true;
		
		value[x][y]=0;
	}
	return false;
}
