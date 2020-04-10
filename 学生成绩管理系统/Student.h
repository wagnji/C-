#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
class student:public Person { //构建学生类，继承person类
	public:
		friend void Manage(student stud[]) ;
		friend void Input(student stud[]) ;
		friend void Statistic(student stud[]);
		friend void Lookup(student stud[]) ;
		friend void Modify(student stud[]) ;
		friend void Output(student stud[]) ;
		friend void Insert(student stud[]) ;
		friend void Write(student stud[],int n);
		friend int Read(student stud[]);
	private:
		int num;
		char name[8];
		char class_0[20];
		float c_program;
		float english;
		float math;
		float average;
		int order;
} stud[100];
