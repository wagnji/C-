
#include <stdio.h>

int main()
{
	int i = 0;
	scanf("%d", &i);
	if ((i % 4 == 0) && (i % 100 != 0) || (i % 400 == 0))
	{
		printf("%d������", i);
	}
	else {
		printf("%d��������", i);
	}
	return 0;
}