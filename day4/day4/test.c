#include <stdio.h>

//void bubble_sort(int arr[], int sz)  //√∞≈›≈≈–Ú
//{
//	int buf = 0;
//	for (int i = 0; i < sz-1; i++)
//	{
//		int flag = 0;
//		for (int j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				flag = 1;
//				buf = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = buf;
//			}
//		}
//		if (flag == 0)
//		{
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 3, 5, 4, 1, 2, 7, 9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d\t", arr[i]);
//	}
//	return 0;
//}

//int main()  //360√Ê ‘Ã‚
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	//i = ++a && ++b && d++;
//	i = ++a || ++b || d++;
//	printf("i=%d\n a=%d\n b=%d\n d=%d\n", i, a, b, d);
//	return 0;
//}