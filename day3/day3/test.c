#include <stdio.h>

//int fun(int *num)    //判断一个数是否为素数
//{
//	for (int i = 2; i < *num; i++)
//	{
//		if (*num % i == 0)
//			return 1;
//	}
//}
//
//int main()
//{
//	int num;
//	scanf_s("%d", &num);
//	int ret = fun(&num);
//	if (ret == 1)
//		printf("%d不是素数\n", num);
//	else
//		printf("%d是素数\n", num);
//	return 0;
//}

//int fun(int* year)   //判断是否为闰年
//{
//	if (*year % 4 == 0 && *year % 100 != 0 || *year % 400 == 0)
//		return 1;
//}
//
//int main()
//{
//	int year;
//	scanf_s("%d", &year);
//	int ret = fun(& year);
//	if (ret == 1)
//		printf("%d是闰年\n", year);
//	else
//		printf("%d不是闰年\n", year);
//	return 0;
//}

//int binary_search(int arr[], int* key, int sz)  //整形有序数组的二分查找
//{
//	int left = 0;
//	int right = sz - 1;
//	int mid = 0;
//	while (left <= right)
//	{
//		mid = left + (right - left) / 2;
//		if (arr[mid] == *key)
//			return mid;
//		else if (arr[mid] > * key)
//			right = mid - 1;
//		else
//			left = mid + 1;
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int key;
//	scanf_s("%d", &key);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = binary_search(arr, &key, sz);
//	if (-1 == ret)
//		printf("没有找到值");
//	else
//		printf("找到了，下标为%d\n", ret);
//	return 0;
//}

//int fun(int *i)   //写一个函数每次调用函数，num加一
//{                   //考点是使用 传地址调用 来改变函数外部实参的值
//	(*i)++;
//	return *i;
//}
//
//int main()
//{
//	int i = 0;
//	fun(&i);
//	printf("第%d次调用函数\n", i);
//	fun(&i);
//	printf("第%d次调用函数\n", i);
//	fun(&i);
//	printf("第%d次调用函数\n", i);
//	return 0;
//}

//void fun(int n)    //输入1234   输出1 2 3 4
//{
//	if (n > 9)
//	{
//		fun(n / 10);
//	}
//	printf("%d\t", n % 10);
//}
//
//int main()
//{
//	int num;
//	scanf_s("%d", &num);
//	fun(num);
//	return 0;
//}

int Strlen(const char *str)  //求字符串长度
{
	if (*str == '\0')
		return 0;
	else return 1 + Strlen(str + 1);
}

int main()
{
	char *p="abcdef";
	int len = Strlen(p);
	printf("字符串长度为%d\n", len);
	return 0;
}

