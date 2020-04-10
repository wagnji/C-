#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
class Manage:public student {
};
void Input(student stud[]) { //--------------- 输入学生成绩
	system("cls"); /* 运行前清屏 */
	int i=0;
	int flag;
	char sign;
	cout<<endl<<">>>>>>>> 请输入学生成绩 <<<<<<<<\n"<<endl;
	while(sign!='n'&&sign!='N') { /* 判断 */
		cout<<" 班级 :"; /* 交互输入 */
		cin>>stud[i].class_0;
loop:
		cout<<" 学号 :";
		cin>>stud[i].num;
		int c=0;
		while(c<i) {
			c++;
			if(stud[i].num==stud[i-c].num) {
				cout<<" 你输入的学号已经存在 !请重新输入 !"<<endl;
				goto loop;
			}
		}
		cout<<" 姓名 :";
		cin>>stud[i].name;
		do {
			flag=0;
			cout<<"C++ 成绩 :";
			cin>>stud[i].c_program;
			if(stud[i].c_program>100 ||stud[i].c_program<1)
				cout<<" 请输入 1-100 之间的数字 !\n";
			else
				flag=1;
		} while(flag==0);
		do {
			flag=0;
			cout<<" 英语成绩 :";
			cin>>stud[i].english;
			if(stud[i].english>100 ||stud[i].english<1)
				cout<<" 请输入 1-100 之间的数字 !\n";
			else
				flag=1;
		} while(flag==0);
		do {
			flag=0;
			cout<<" 数学成绩 :";
			cin>>stud[i].math;
			if(stud[i].math>100 ||stud[i].math<1)
				cout<<" 请输入 1-100 之间的数字 !\n";
			else
				flag=1;
		} while(flag==0);
		stud[i].average=(stud[i].c_program+stud[i].english+stud[i].math)/3;
		cout<<" 平均分: "<<stud[i].average<<endl;
		cout<<" 继续录入学生成绩 ?(y/n)";
		cin>>sign; /* 输入判断 */
		i++;
	}
	Write(stud,i);
}
void Statistic(student stud[]) { //--------------- 统计学生数据
	system("cls"); /* 运行前清屏 */
	int n=Read(stud);
	cout<<endl<<">>>>>>>> 显示学生成绩 <<<<<<<<\n"<<endl;
	cout<<" 班 级 "<<"\t"<<" 学 号 "<<"\t"<<" 姓 名 "<<"\t"<<"c++"<<"\t"<<" 英 语"<<"\t"<<" 数学 "<<"\t"<<" 平均分 "<<endl;
	for(int i=0; i<n; i++)
	cout<<stud[i].class_0<<"\t"<<stud[i].num<<"\t"<<stud[i].name<<"\t"<<stud[i].c_program<<"\t"<<stud[i].english<<"\t"<<stud[i].math<<"\t"<<stud[i].average<<endl;
	system("pause");
}
void Lookup(student stud[]) { //---------------查找学生成绩
	int p;
	cout<<"  请选择 1.按学号查找 2.按姓名查找 "<<endl;
	cin>>p;
	if(p==1) {
		system("cls"); /* 运行前清屏 */
		int n=Read(stud);
		int s;
		int i=0;
		cout<<endl<<">>>>>>>> 查找学生成绩 <<<<<<<<\n"<<endl;
		cout<<" 请输入查找学生的学号 :"<<endl;
		cin>>s;
		while((stud[i].num-s)!=0&&i<n) i++; /* 查找判断*/
		if(i==n) {
			cout<<" 没有该学生的信息! "<<endl; /* 输入失败信息 */
		} else {
			cout<<"---------------------------"<<endl;
			cout<<" 班级  :"<<stud[i].class_0<<endl; /* 输出该学生信息 */
			cout<<" 学号 :"<<stud[i].num<<endl;
			cout<<" 姓名 :"<<stud[i].name<<endl;
			cout<<" C++:"<<stud[i].c_program<<endl;
			cout<<" 英语 :"<<stud[i].english<<endl;
			cout<<" 数学 :"<<stud[i].math<<endl;
			cout<<" 平均分 :"<<stud[i].average<<endl;
		}
	}
	if(p==2) {
		system("cls"); /* 运行前清屏 */
		int m=Read(stud);
		char t;
		int i=0;
		cout<<endl<<">>>>>>>>查找学生成绩  <<<<<<<<\n"<<endl;
		cout<<"  请输入查找学生的姓名 :"<<endl;
		cin>>t;
		while(strcmp(stud[i].name-t,stud[i].name)==0&&i<m) i++; /* 查找判断 */
		{
			cout<<"---------------------------"<<endl;
			cout<<" 班级 :"<<stud[i].class_0<<endl; /* 输出该学生信息 */
			cout<<" 学号 :"<<stud[i].num<<endl;
			cout<<" 姓名 :"<<stud[i].name<<endl;
			cout<<" C++:"<<stud[i].c_program<<endl;
			cout<<" 英语  :"<<stud[i].english<<endl;
			cout<<" 数学:"<<stud[i].math<<endl;
			cout<<" 平均分 :"<<stud[i].average<<endl;
		}
	}
}
void Modify(student stud[]) { //--------------- 修改学生成绩
	system("cls"); /* 运行前清屏 */
	int n=Read(stud);
	int s,a;
	float q;
	int i=0;
	cout<<endl<<">>>>>>>> 修改学生成绩 <<<<<<<<\n"<<endl;
	cout<<" 输入修改成绩学生的学号 :"<<endl;
	cin>>s;
	while((stud[i].num-s)!=0&&i<n) i++; /* 查找判断 */
	if(i==n) {
		cout<<" 没有该学生的成绩 !"<<endl; /* 输入失败信息 */
	} else {
		cout<<"---------- 该学生的信息 ----------\n"<<endl; /* 格式头 */
		cout<<" 班 级 "<<"\t"<<" 学 号 "<<"\t"<<" 姓 名 "<<"\t"<<"c++"<<"\t"<<" 英 语"<<"\t"<<" 数学 "<<"\t"<<" 平均分 "<<endl;
		cout<<"---------------------------------"<<endl;
		cout<<stud[i].class_0<<"\t"<<stud[i].num<<"\t"<<stud[i].name<<"\t"<<stud[i].c_program<<"\t\t"<<stud[i].english<<"\t"<<stud[i].math<<"\t"<<stud[i].average<<endl;
		cout<<"---------------------------------"<<endl;
		cout<<" 请输入要修改的课程号 "<<endl;
		cout<<"1.c语言 2.英语 3.数学 "<<endl;
		cin>>a;
		cout<<" 重新输入分数 "<<endl;
		cin>>q;
		if(a==1) stud[i].c_program=q;
		if(a==2)stud[i].english=q;
		if(a==3)stud[i].math=q;
		stud[i].average=(stud[i].c_program+stud[i].english+stud[i].math)/3;
		cout<<"---------- 该学生的信息  ----------\n"<<endl; /* 格式头 */
		cout<<" 班 级 "<<"\t"<<" 学 号 "<<"\t"<<" 姓 名"<<"\t"<<"c++"<<"\t"<<"  英语 "<<"\t"<<" 数学 "<<"\t"<<" 平均分 "<<endl;
		cout<<"---------------------------------"<<endl;
		cout<<stud[i].class_0<<"\t"<<stud[i].num<<"\t"<<stud[i].name<<"\t"<<stud[i].c_program<<
		    "\t\t"<<stud[i].english<<"\t"<<stud[i].math<<"\t"<<stud[i].average<<endl;
		char c;
		cout<<" 是否保存数据 ?(y/n)"<<endl;
		cin>>c;
		if(c!='n'&&c!='N')
			Write(stud,n);
	}
}
void Insert(student stud[]) { //--------------- 增加学生成绩
	system("cls"); /* 运行前清屏 */
	int n=Read(stud);
	char s;
	cout<<endl<<"************ 插入学生成绩 ***********\n"<<endl;
	while(s!='n'&&s!='N') {
		cout<<"  班级 :"<<endl; /* 交互输入 */
		cin>>stud[n].class_0;
		cout<<"  学号 :";
		cin>>stud[n].num;
		cout<<"  姓名  :";
		cin>>stud[n].name;
		cout<<"C++ 成绩 :";
		cin>>stud[n].c_program;
		cout<<" 英语成绩 :";
		cin>>stud[n].english;
		cout<<" 数学成绩  :";
		cin>>stud[n].math;
		stud[n].average=(stud[n].c_program+stud[n].english+ stud[n].math)/3;
		cout<<" 平均分 "<<stud[n].average;
		n++;
		cout<<" 插入成功！ "<<endl; /* 返回成功信息 */
		cout<<" 是否继续输入  (y/n)"<<endl;
		cin>>s;
	}
	Write(stud,n);
}
void Manage(student stud[]) { //--------------- 按平均分对学生成绩记录项进行降序排序
	system("cls"); /* 运行前清屏 */
	int i,j,k;
	float s;
	char t[20];
	cout<<endl<<"********** 排列管理成绩 **********\n"<<endl;
	int n=Read(stud);
	for(i=0; i<n-1; i++) /* 冒泡法排序 */
		for(j=0; j<n-1-i; j++)
			if(stud[j].average<stud[j+1].average) {
				strcpy(t,stud[j+1].class_0);
				strcpy(stud[j+1].class_0,stud[j].class_0);
				strcpy(stud[j].class_0,t);
				k=stud[j+1].num;
				stud[j+1].num=stud[j].num;
				stud[j].num=k;
				strcpy(t,stud[j+1].name);
				strcpy(stud[j+1].name,stud[j].name);
				strcpy(stud[j].name,t);
				s=stud[j+1].c_program;
				stud[j+1].c_program=stud[j].c_program;
				stud[j].c_program=s;
				s=stud[j+1].english;
				stud[j+1].english=stud[j].english;
				stud[j].english=s;
				s=stud[j+1].math;
				stud[j+1].math=stud[j].math;
				s=stud[j+1].average;
				stud[j+1].average=stud[j].average;
				stud[j].average=s;
			}
	cout<<"-------------------------------------"<<endl; /* 格式头 */
	cout<<" 班级 "<<"\t "<<" 学号 "<<"\t "<<"  姓名 "<<"\t"<<"C++"<<"\t"<<" 英语"<<"\t"<<"  数学 "<<"\t"<<" 平均分 "<<"\t"<<" 名次 "<<endl;
	for(i=0; i<n; i++) { /* 循环输入 */
		stud[i].order=i+1;
		cout<<stud[i].class_0<<"\t"<<stud[i].num<<"\t"<<stud[i].name<<"\t"<<stud[i].c_program<<
		    "\t\t"<<stud[i].english<<"\t"<<stud[i].math<<"\t"<<stud[i].average<<"\t "<<stud[i].order<<endl;
	}
	Write(stud,n);
}
void Output(student stud[]) { //--------------- 显示全部学生成绩
	system("cls"); /* 运行前清屏 */
	int n=Read(stud);
	cout<<"***************** 显示班级学生成绩 * *****************\n"<<endl;
	if(!stud)
		cout<<" 没有记录 ";
	else {
		cout<<"-------------------------------------------------------------------------"<<endl; /*格式头*/
		cout<<"  班级 "<<"\t "<<" 学号 "<<"\t "<<" 姓名 "<<"\t"<<"c++"<<"\t"<<" 英语"<<"\t"<<" 数学 "<<"\t"<<"平均分"<<endl;
		for(int i=0; i<n; i++) { /* 循环输入 */
			cout<<stud[i].class_0<<"\t\t"<<stud[i].num<<"\t\t"<<stud[i].name<<"\t\t"<<stud[i].c_program<<"\t\t"<<stud[i].english<<"\t\t" <<stud[i].math<<"\t\t"<<stud[i].average<<endl;
		}
		cout<<"-------------------------------------------------------------------------"<<endl;
	}
}
int menu() { /* 菜单函数 */
	char c;
	do {
		system("cls"); /* * 运行前清屏 */
		cout<<"*******************************************************\n"<<endl;
		cout<<" ----------------- 欢迎使用学生成绩管理系统  -------------\n"<<endl;
		cout<<" *************************************************"<<endl;
		cout<<" * 【1】输入学生成绩 *"<<endl;
		cout<<" * 【2】显示学生成绩 * "<<endl;
		cout<<" * 【3】查找学生成绩 * "<<endl;
		cout<<" * 【4】修改学生成绩 * "<<endl;
		cout<<" * 【5】插入学生成绩 * "<<endl;
		cout<<" * 【6】排列管理成绩 * "<<endl;
		cout<<" * 【7】显示班级学生成绩 * "<<endl;
		cout<<" * 【0】退出本系统* " <<endl;
		cout<<" *************************************************"<<endl;
		cout<<" 请你选择 (0-7):"<<endl;
		c=getchar(); /* 读入选择 */
	} while(c<'0'||c>'8');
	return(c-'0'); /* 返回选择 */
}
