// d森林问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
using namespace std;

struct TREE
{
	int length, dist;
	TREE *son, *next, *father;
}tree[1000] = {0};
stringstream ge[1000];
int d;

void buildtree(int root)
{
	int dest, wei;
	TREE *cur = 0;
	while(ge[root] >> dest >> wei)
	{
		if (root == 0 || &tree[dest] != tree[root].father)
		{
			if (cur == 0)
				tree[root].son = cur = &tree[dest];
			else
			{
				cur -> next = &tree[dest];
				cur = cur -> next;
			}
			tree[dest].father = &tree[root];
			tree[dest].length = wei;
			buildtree(dest);
		}
	}
}

int del(TREE *root)
{
	TREE *cur = root -> son;
	int delsum = 0;
	while (cur != 0)
	{
		delsum += del(cur);
		if (cur -> dist + cur -> length > root -> dist) root -> dist = cur -> dist + cur -> length;
		cur = cur -> next;
	}
	if (root -> dist > d)
	{
		root -> dist = 0;
		root -> length = 0;
		return delsum + 1;
	}
	else
		return delsum;
}

int main(){
	int n;

	cin >> n;
	for (int ver = 0, k, dest, wei; ver < n; ver ++)
	{
		cin >> k;
		for (int route = 0; route < k; route ++)
		{
			cin >> dest >> wei;
			ge[ver] << dest - 1 << " " << wei << " ";
			ge[dest - 1] << ver << " " << wei << " ";
		}
	}
	cin >> d;

	buildtree(0);

	cout << del(&tree[0]) << endl;

	return 0;
}



