// 装载问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n,c1,c2,w[15];

int cw,bestw,r,x[15],bestx[15];

void backtrack(int i)

{
    if(i > n) 
	{
        if(cw > bestw) 
			bestw = cw;
        return;
    }
     else 
	 {
            r -= w[i];
     if(cw + w[i] <= c1) //搜索左子树
    {
        cw += w[i];
        backtrack(i + 1);
        cw -= w[i];
    }
    if(cw + r > bestw) //搜索右子树
        backtrack(i + 1);
    r += w[i];
     }
}

 

int main()
{
    while(cin >> c1 >> c2 >> n && n)
    {
        cw = 0;
        bestw = 0;r = 0;
        for(int i = 1;i <= n;i ++)
        {
            cin >> w[i];
            r += w[i];
        }
        backtrack(1);
        if(r - bestw <= c2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}

