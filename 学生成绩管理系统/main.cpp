#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"Person.h"
#include"Student.h"
#include"Manage.h" 
using namespace std;
void Write(student stud[],int n) {
	ofstream myFile;
	myFile.open("score.txt",ios::out|ios::binary);
	if(!myFile) {
		cout<<"score.txt can't open!"<<endl;
		abort();
	}
	int count=n;
	myFile<<count<<endl<<endl;
	for(int i=0; i<=count; i++) 
	{
		myFile<<stud[i].class_0<<"\t"<<stud[i].num<<"\t"<<stud[i].name<<"\t"<<stud[i].c_program<<"\t\t"<<stud[i].english<<"\t\t"<<stud[i].math<<"\t"<<stud[i].average<<endl;
	}
	myFile.close();
}
int Read(student stud[]) { //从文件中读数据
	fstream myFile;
	myFile.open("score.txt",ios::in|ios::binary);
	if(!myFile) {
		cout<<"score.txt can't open!"<<endl;
		abort();
	}
	int count;
	myFile.seekg(0);
	myFile>>count;
	for(int i=0; i<=count; i++) 
	{
		myFile>>stud[i].class_0>>stud[i].num>>stud[i].name>>stud[i].c_program>>stud[i].english>>stud[i].math >>stud[i].average;
	}
	myFile.close();
	return count ;
}
int main() { /* 主函数 */
	for(;;) {
		switch(menu()) { /*选择判断 */
			case 1:
				Input(stud);/* 输入学生成绩 */
				break;
			case 2:
				Statistic(stud); /* 输出学生统计数据 */
				break;
			case 3:
				Lookup(stud); /* 查找学生成绩 */
				cout<<"\t\t\t";
				system("pause");
				break;
			case 4:
				Modify(stud); /* 修改学生成绩 */
				cout<<"\t\t\t";
				system("pause");
				break;
			case 5:
				Insert(stud);/* 增加学生成绩 */
				cout<<"\t\t\t";
				system("pause");
				break;
			case 6:
				Manage(stud); /* 按平均分对成绩记录项进行降序排序 */
				cout<<"\t\t\t";
				system("pause");
				break;
			case 7:
				Output(stud); /* 显示全部学生成绩 */
				cout<<"\t\t\t";
				system("pause");
				break;
			case 0:
				cout<<endl<<" =========================== 感谢您使用学生成绩管理系统==========================\n"<<endl; /* 结束程序  */
				cout<<"\t\t\t";
				system("pause");
				exit(0);
		}
	}
}

