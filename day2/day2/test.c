#include <stdio.h>
#include <string.h>
#include <Windows.h>

//int main()   //判断是否为奇数
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	if (1 == n % 2)
//	{
//		printf("是奇数");
//	}
//	else
//	{
//		printf("不是奇数");
//	}
//	return 0;
//}

//int main()   //输出1到100中的奇数
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (1 == i % 2)
//		{
//			printf("%d\t", i);
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int i = 0;
//	while(i<10)
//	{
//		i++;
//		if (i == 5)
//			continue;
//		printf("%d\t", i);
//	}
//	return 0;
//}

//int main()    //输出所有字符
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//		putchar(ch);
//	return 0;
//}

//int main()    //只输出0到9的字符
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch>'9')
//			continue;
//		putchar(ch);
//	}
//	return 0;
//

//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (i == 5)
//			//break;
//			continue;
//		printf("%d\n", i);
//	}
//	return 0;
//}

//int main()   //n的阶乘
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	int sum = 1;
//	for (int i = 1; i < n + 1; i++)
//	{
//		sum *= i;
//	}
//	printf("%d", sum);
//	return 0;
//}

//int main()      //1的阶乘加到n的阶乘
//{
//	int Sn = 0;
//	int n;
//	scanf_s("%d", &n);
//	for (int i = 1; i < n + 1; i++)
//	{
//		int s = 1;
//		for (int j = 1; j <= i; j++)
//		{
//			s *= j;
//		}
//		Sn += s;
//	}
//	printf("%d", Sn);
//	return 0;
//}

//int main()
//{
//	char arr1[] = "Welcome to bit...";
//	char arr2[] = "*****************";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	printf("%s\n", arr2);
//	for (left = 0, right = strlen(arr1) - 1;
//		left <= right;
//		left++, right--)
//	{
//		Sleep(1000);
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//    }		
//	printf("%s\n", arr2);
//	return 0;
//}

