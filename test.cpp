#include <iostream>
#include "sudoku.h"
using namespace std;

int main()
{
	Sudoku sdk;
	
	// initialize
	sdk.init();
	cout<<"The initial matrix: "<<endl;
	sdk.debug();
	
	// sudoku calculate
	sdk.calc();
	
	// print the result
	cout<<"The result:"<<endl;
	sdk.debug();
	return 0;
}
