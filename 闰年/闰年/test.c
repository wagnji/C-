
#include <stdio.h>

int main()
{
	int i = 0;
	scanf("%d", &i);
	if ((i % 4 == 0) && (i % 100 != 0) || (i % 400 == 0))
	{
		printf("%d是闰年", i);
	}
	else {
		printf("%d不是闰年", i);
	}
	return 0;
}