#include "stdio.h"
#include "stdlib.h"

int fun(int n)
{
	if(n==0||n==1)
		return 1;
	return n*fun(n-1);
}


int main()
{
  int n;
  scanf_s("%d",&n);
  printf("nµÄ½×³ËÊÇ%d",fun(n));
  return 0;
}