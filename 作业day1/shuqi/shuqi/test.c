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
while(str2[i]!='\0')//当str2未结束
{
for(int j=0;j<len1;j++) 
if(str2[i]==str1[j])//遍历str1 如果有 与str2[i]相同的字符
{
for(int k=i;k<len2;k++)
str2[k]=str2[k+1];//从 这个重复的字符开始，用后一个字符依次覆盖前一个字符，
len2--;//len2的长度减一
break; 
}
if(j==len1)//如果遍历完一次 str1 ，i++，并且判断while
i++;//推进循环 while判断
}
printf("%s\n",str1);
printf("%s\n",str2);
} 