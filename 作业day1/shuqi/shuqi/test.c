#include "test.h"

void main()
{
char str2[10];
char str1[10];
scanf("%s",str1);
scanf("%s",str2);
int i=0;
int len1 = strlen(str1);
int len2 = strlen(str2);
while(str2[i]!='\0')//��str2δ����
{
for(int j=0;j<len1;j++) 
if(str2[i]==str1[j])//����str1 ����� ��str2[i]��ͬ���ַ�
{
for(int k=i;k<len2;k++)
str2[k]=str2[k+1];//�� ����ظ����ַ���ʼ���ú�һ���ַ����θ���ǰһ���ַ���
len2--;//len2�ĳ��ȼ�һ
break; 
}
if(j==len1)//���������һ�� str1 ��i++�������ж�while
i++;//�ƽ�ѭ�� while�ж�
}
printf("%s\n",str1);
printf("%s\n",str2);
} 