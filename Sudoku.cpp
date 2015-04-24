#include <iostream>
using namespace std;

#include "sudoku.h"

bool Sudoku::init()
{
    done = false;
    cout << "Please input the 9*9 sudoku matrix: " << endl;
    char c;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin>>c;  
            num[i][j] = c - '0';
        }
    }
}

void Sudoku::debug()
{
    cout<<"sudoku: "<<endl;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << num[i][j] << " ";
        }
        cout << endl;
    }
}

bool Sudoku::check(int x, int y, int value)
{
    int i;
    
    /* check the line is vaild or not */
    for (i = 0; i < 9; i++)
    {
        if (num[x][i] == value) 
            return false;
    }
 
    /* 判断所在列是否合法 */
    for (i = 0; i < 9; i++)
    {
        if (num[i][y] == value) 
            return false;
    }
 
    /* xx为所在的小九宫格左顶点竖坐标 */
    int xx = x / 3 * 3;
 
    /* yy为所在的小九宫格左顶点横坐标 */
    int yy = y / 3 * 3;
 
    /* 判断n所在的小九宫格是否合法 */
    for (int i = xx; i < xx + 3; i++)
    {
        for (int j = yy; j < yy + 3; j++)
        {
            if (num[i][j] == value) return false;
        }
    }
 
    /* 全部合法，返回正确 */
    return true;
}

/* 深搜构造数独 */
int Sudoku::calc(int n)
{
    /* 所有的都符合，退出递归 */
    if (n >= 9*9) // 最多81轮
    {
        done = true;
        return 0;
    }
    
    /* 当前格子不为空时跳过 */
    if (num[n/9][n%9] != 0)
    {
        return calc(n+1); // 跳过，继续求解下一个
    }
    else
    {
        /* 否则对当前格子进行枚举测试 */
        for (int i = 1; i <= 9; i++)
        {
            /* 满足条件时填入数字 */
            if (check(n/9, n%9, i) == true)
            {
                num[n/9][n%9] = i;
                
                /* 继续搜索 */
                calc(n+1);
                
                /* 返回时如果构造成功，则直接退出 */
                if (done == true) 
                    return 0;
                
                /* 如果构造不成功，还原当前位 */
                num[n/9][n%9] = 0;
            }
        }
        return -1;
    }
}
