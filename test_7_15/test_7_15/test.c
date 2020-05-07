#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= 7; i++) {
		for (j = 7-i; j > 0; j--) {
			printf(" ");
		}
		for (j = 1; j <=(2*i)-1 ; j ++) {
			printf("*");
		}
		printf("\n");
	}
	for (i = 1; i <= 6; i++) {
		for (j = 7-i; j < 7; j++) {
			printf(" ");
		}
		for (j = 13 - (2 * i); j > 0; j-- ) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

int main()
{
	int i = 0;
	for (i = 0; i <= 999; i++) {
		if (pow((i / 100), 3) + pow(((i % 100)/10),3) + pow((i % 10), 3) == i) {
			printf("%d\n", i);
		}
	}
	return 0;
}

int main()
{
	int a = 0;
	int i = 0;
	int k = 0;
	int s = 0;
	scanf("%d", &a);
	for (i = 0; i < 5; i++) {
		for (k = 0; k <= i; k++) {
			s += a * (pow(10, k));
		}
	}
	printf("%d", s);
	return 0;
	
}

