#include <stdio.h>

//int fun(int *num)    //�ж�һ�����Ƿ�Ϊ����
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
//		printf("%d��������\n", num);
//	else
//		printf("%d������\n", num);
//	return 0;
//}

//int fun(int* year)   //�ж��Ƿ�Ϊ����
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
//		printf("%d������\n", year);
//	else
//		printf("%d��������\n", year);
//	return 0;
//}

//int binary_search(int arr[], int* key, int sz)  //������������Ķ��ֲ���
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
//		printf("û���ҵ�ֵ");
//	else
//		printf("�ҵ��ˣ��±�Ϊ%d\n", ret);
//	return 0;
//}

//int fun(int *i)   //дһ������ÿ�ε��ú�����num��һ
//{                   //������ʹ�� ����ַ���� ���ı亯���ⲿʵ�ε�ֵ
//	(*i)++;
//	return *i;
//}
//
//int main()
//{
//	int i = 0;
//	fun(&i);
//	printf("��%d�ε��ú���\n", i);
//	fun(&i);
//	printf("��%d�ε��ú���\n", i);
//	fun(&i);
//	printf("��%d�ε��ú���\n", i);
//	return 0;
//}

//void fun(int n)    //����1234   ���1 2 3 4
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

int Strlen(const char *str)  //���ַ�������
{
	if (*str == '\0')
		return 0;
	else return 1 + Strlen(str + 1);
}

int main()
{
	char *p="abcdef";
	int len = Strlen(p);
	printf("�ַ�������Ϊ%d\n", len);
	return 0;
}

