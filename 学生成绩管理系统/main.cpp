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
int Read(student stud[]) { //���ļ��ж�����
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
int main() { /* ������ */
	for(;;) {
		switch(menu()) { /*ѡ���ж� */
			case 1:
				Input(stud);/* ����ѧ���ɼ� */
				break;
			case 2:
				Statistic(stud); /* ���ѧ��ͳ������ */
				break;
			case 3:
				Lookup(stud); /* ����ѧ���ɼ� */
				cout<<"\t\t\t";
				system("pause");
				break;
			case 4:
				Modify(stud); /* �޸�ѧ���ɼ� */
				cout<<"\t\t\t";
				system("pause");
				break;
			case 5:
				Insert(stud);/* ����ѧ���ɼ� */
				cout<<"\t\t\t";
				system("pause");
				break;
			case 6:
				Manage(stud); /* ��ƽ���ֶԳɼ���¼����н������� */
				cout<<"\t\t\t";
				system("pause");
				break;
			case 7:
				Output(stud); /* ��ʾȫ��ѧ���ɼ� */
				cout<<"\t\t\t";
				system("pause");
				break;
			case 0:
				cout<<endl<<" =========================== ��л��ʹ��ѧ���ɼ�����ϵͳ==========================\n"<<endl; /* ��������  */
				cout<<"\t\t\t";
				system("pause");
				exit(0);
		}
	}
}

