#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
class Manage:public student {
};
void Input(student stud[]) { //--------------- ����ѧ���ɼ�
	system("cls"); /* ����ǰ���� */
	int i=0;
	int flag;
	char sign;
	cout<<endl<<">>>>>>>> ������ѧ���ɼ� <<<<<<<<\n"<<endl;
	while(sign!='n'&&sign!='N') { /* �ж� */
		cout<<" �༶ :"; /* �������� */
		cin>>stud[i].class_0;
loop:
		cout<<" ѧ�� :";
		cin>>stud[i].num;
		int c=0;
		while(c<i) {
			c++;
			if(stud[i].num==stud[i-c].num) {
				cout<<" �������ѧ���Ѿ����� !���������� !"<<endl;
				goto loop;
			}
		}
		cout<<" ���� :";
		cin>>stud[i].name;
		do {
			flag=0;
			cout<<"C++ �ɼ� :";
			cin>>stud[i].c_program;
			if(stud[i].c_program>100 ||stud[i].c_program<1)
				cout<<" ������ 1-100 ֮������� !\n";
			else
				flag=1;
		} while(flag==0);
		do {
			flag=0;
			cout<<" Ӣ��ɼ� :";
			cin>>stud[i].english;
			if(stud[i].english>100 ||stud[i].english<1)
				cout<<" ������ 1-100 ֮������� !\n";
			else
				flag=1;
		} while(flag==0);
		do {
			flag=0;
			cout<<" ��ѧ�ɼ� :";
			cin>>stud[i].math;
			if(stud[i].math>100 ||stud[i].math<1)
				cout<<" ������ 1-100 ֮������� !\n";
			else
				flag=1;
		} while(flag==0);
		stud[i].average=(stud[i].c_program+stud[i].english+stud[i].math)/3;
		cout<<" ƽ����: "<<stud[i].average<<endl;
		cout<<" ����¼��ѧ���ɼ� ?(y/n)";
		cin>>sign; /* �����ж� */
		i++;
	}
	Write(stud,i);
}
void Statistic(student stud[]) { //--------------- ͳ��ѧ������
	system("cls"); /* ����ǰ���� */
	int n=Read(stud);
	cout<<endl<<">>>>>>>> ��ʾѧ���ɼ� <<<<<<<<\n"<<endl;
	cout<<" �� �� "<<"\t"<<" ѧ �� "<<"\t"<<" �� �� "<<"\t"<<"c++"<<"\t"<<" Ӣ ��"<<"\t"<<" ��ѧ "<<"\t"<<" ƽ���� "<<endl;
	for(int i=0; i<n; i++)
	cout<<stud[i].class_0<<"\t"<<stud[i].num<<"\t"<<stud[i].name<<"\t"<<stud[i].c_program<<"\t"<<stud[i].english<<"\t"<<stud[i].math<<"\t"<<stud[i].average<<endl;
	system("pause");
}
void Lookup(student stud[]) { //---------------����ѧ���ɼ�
	int p;
	cout<<"  ��ѡ�� 1.��ѧ�Ų��� 2.���������� "<<endl;
	cin>>p;
	if(p==1) {
		system("cls"); /* ����ǰ���� */
		int n=Read(stud);
		int s;
		int i=0;
		cout<<endl<<">>>>>>>> ����ѧ���ɼ� <<<<<<<<\n"<<endl;
		cout<<" ���������ѧ����ѧ�� :"<<endl;
		cin>>s;
		while((stud[i].num-s)!=0&&i<n) i++; /* �����ж�*/
		if(i==n) {
			cout<<" û�и�ѧ������Ϣ! "<<endl; /* ����ʧ����Ϣ */
		} else {
			cout<<"---------------------------"<<endl;
			cout<<" �༶  :"<<stud[i].class_0<<endl; /* �����ѧ����Ϣ */
			cout<<" ѧ�� :"<<stud[i].num<<endl;
			cout<<" ���� :"<<stud[i].name<<endl;
			cout<<" C++:"<<stud[i].c_program<<endl;
			cout<<" Ӣ�� :"<<stud[i].english<<endl;
			cout<<" ��ѧ :"<<stud[i].math<<endl;
			cout<<" ƽ���� :"<<stud[i].average<<endl;
		}
	}
	if(p==2) {
		system("cls"); /* ����ǰ���� */
		int m=Read(stud);
		char t;
		int i=0;
		cout<<endl<<">>>>>>>>����ѧ���ɼ�  <<<<<<<<\n"<<endl;
		cout<<"  ���������ѧ�������� :"<<endl;
		cin>>t;
		while(strcmp(stud[i].name-t,stud[i].name)==0&&i<m) i++; /* �����ж� */
		{
			cout<<"---------------------------"<<endl;
			cout<<" �༶ :"<<stud[i].class_0<<endl; /* �����ѧ����Ϣ */
			cout<<" ѧ�� :"<<stud[i].num<<endl;
			cout<<" ���� :"<<stud[i].name<<endl;
			cout<<" C++:"<<stud[i].c_program<<endl;
			cout<<" Ӣ��  :"<<stud[i].english<<endl;
			cout<<" ��ѧ:"<<stud[i].math<<endl;
			cout<<" ƽ���� :"<<stud[i].average<<endl;
		}
	}
}
void Modify(student stud[]) { //--------------- �޸�ѧ���ɼ�
	system("cls"); /* ����ǰ���� */
	int n=Read(stud);
	int s,a;
	float q;
	int i=0;
	cout<<endl<<">>>>>>>> �޸�ѧ���ɼ� <<<<<<<<\n"<<endl;
	cout<<" �����޸ĳɼ�ѧ����ѧ�� :"<<endl;
	cin>>s;
	while((stud[i].num-s)!=0&&i<n) i++; /* �����ж� */
	if(i==n) {
		cout<<" û�и�ѧ���ĳɼ� !"<<endl; /* ����ʧ����Ϣ */
	} else {
		cout<<"---------- ��ѧ������Ϣ ----------\n"<<endl; /* ��ʽͷ */
		cout<<" �� �� "<<"\t"<<" ѧ �� "<<"\t"<<" �� �� "<<"\t"<<"c++"<<"\t"<<" Ӣ ��"<<"\t"<<" ��ѧ "<<"\t"<<" ƽ���� "<<endl;
		cout<<"---------------------------------"<<endl;
		cout<<stud[i].class_0<<"\t"<<stud[i].num<<"\t"<<stud[i].name<<"\t"<<stud[i].c_program<<"\t\t"<<stud[i].english<<"\t"<<stud[i].math<<"\t"<<stud[i].average<<endl;
		cout<<"---------------------------------"<<endl;
		cout<<" ������Ҫ�޸ĵĿγ̺� "<<endl;
		cout<<"1.c���� 2.Ӣ�� 3.��ѧ "<<endl;
		cin>>a;
		cout<<" ����������� "<<endl;
		cin>>q;
		if(a==1) stud[i].c_program=q;
		if(a==2)stud[i].english=q;
		if(a==3)stud[i].math=q;
		stud[i].average=(stud[i].c_program+stud[i].english+stud[i].math)/3;
		cout<<"---------- ��ѧ������Ϣ  ----------\n"<<endl; /* ��ʽͷ */
		cout<<" �� �� "<<"\t"<<" ѧ �� "<<"\t"<<" �� ��"<<"\t"<<"c++"<<"\t"<<"  Ӣ�� "<<"\t"<<" ��ѧ "<<"\t"<<" ƽ���� "<<endl;
		cout<<"---------------------------------"<<endl;
		cout<<stud[i].class_0<<"\t"<<stud[i].num<<"\t"<<stud[i].name<<"\t"<<stud[i].c_program<<
		    "\t\t"<<stud[i].english<<"\t"<<stud[i].math<<"\t"<<stud[i].average<<endl;
		char c;
		cout<<" �Ƿ񱣴����� ?(y/n)"<<endl;
		cin>>c;
		if(c!='n'&&c!='N')
			Write(stud,n);
	}
}
void Insert(student stud[]) { //--------------- ����ѧ���ɼ�
	system("cls"); /* ����ǰ���� */
	int n=Read(stud);
	char s;
	cout<<endl<<"************ ����ѧ���ɼ� ***********\n"<<endl;
	while(s!='n'&&s!='N') {
		cout<<"  �༶ :"<<endl; /* �������� */
		cin>>stud[n].class_0;
		cout<<"  ѧ�� :";
		cin>>stud[n].num;
		cout<<"  ����  :";
		cin>>stud[n].name;
		cout<<"C++ �ɼ� :";
		cin>>stud[n].c_program;
		cout<<" Ӣ��ɼ� :";
		cin>>stud[n].english;
		cout<<" ��ѧ�ɼ�  :";
		cin>>stud[n].math;
		stud[n].average=(stud[n].c_program+stud[n].english+ stud[n].math)/3;
		cout<<" ƽ���� "<<stud[n].average;
		n++;
		cout<<" ����ɹ��� "<<endl; /* ���سɹ���Ϣ */
		cout<<" �Ƿ��������  (y/n)"<<endl;
		cin>>s;
	}
	Write(stud,n);
}
void Manage(student stud[]) { //--------------- ��ƽ���ֶ�ѧ���ɼ���¼����н�������
	system("cls"); /* ����ǰ���� */
	int i,j,k;
	float s;
	char t[20];
	cout<<endl<<"********** ���й���ɼ� **********\n"<<endl;
	int n=Read(stud);
	for(i=0; i<n-1; i++) /* ð�ݷ����� */
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
	cout<<"-------------------------------------"<<endl; /* ��ʽͷ */
	cout<<" �༶ "<<"\t "<<" ѧ�� "<<"\t "<<"  ���� "<<"\t"<<"C++"<<"\t"<<" Ӣ��"<<"\t"<<"  ��ѧ "<<"\t"<<" ƽ���� "<<"\t"<<" ���� "<<endl;
	for(i=0; i<n; i++) { /* ѭ������ */
		stud[i].order=i+1;
		cout<<stud[i].class_0<<"\t"<<stud[i].num<<"\t"<<stud[i].name<<"\t"<<stud[i].c_program<<
		    "\t\t"<<stud[i].english<<"\t"<<stud[i].math<<"\t"<<stud[i].average<<"\t "<<stud[i].order<<endl;
	}
	Write(stud,n);
}
void Output(student stud[]) { //--------------- ��ʾȫ��ѧ���ɼ�
	system("cls"); /* ����ǰ���� */
	int n=Read(stud);
	cout<<"***************** ��ʾ�༶ѧ���ɼ� * *****************\n"<<endl;
	if(!stud)
		cout<<" û�м�¼ ";
	else {
		cout<<"-------------------------------------------------------------------------"<<endl; /*��ʽͷ*/
		cout<<"  �༶ "<<"\t "<<" ѧ�� "<<"\t "<<" ���� "<<"\t"<<"c++"<<"\t"<<" Ӣ��"<<"\t"<<" ��ѧ "<<"\t"<<"ƽ����"<<endl;
		for(int i=0; i<n; i++) { /* ѭ������ */
			cout<<stud[i].class_0<<"\t\t"<<stud[i].num<<"\t\t"<<stud[i].name<<"\t\t"<<stud[i].c_program<<"\t\t"<<stud[i].english<<"\t\t" <<stud[i].math<<"\t\t"<<stud[i].average<<endl;
		}
		cout<<"-------------------------------------------------------------------------"<<endl;
	}
}
int menu() { /* �˵����� */
	char c;
	do {
		system("cls"); /* * ����ǰ���� */
		cout<<"*******************************************************\n"<<endl;
		cout<<" ----------------- ��ӭʹ��ѧ���ɼ�����ϵͳ  -------------\n"<<endl;
		cout<<" *************************************************"<<endl;
		cout<<" * ��1������ѧ���ɼ� *"<<endl;
		cout<<" * ��2����ʾѧ���ɼ� * "<<endl;
		cout<<" * ��3������ѧ���ɼ� * "<<endl;
		cout<<" * ��4���޸�ѧ���ɼ� * "<<endl;
		cout<<" * ��5������ѧ���ɼ� * "<<endl;
		cout<<" * ��6�����й���ɼ� * "<<endl;
		cout<<" * ��7����ʾ�༶ѧ���ɼ� * "<<endl;
		cout<<" * ��0���˳���ϵͳ* " <<endl;
		cout<<" *************************************************"<<endl;
		cout<<" ����ѡ�� (0-7):"<<endl;
		c=getchar(); /* ����ѡ�� */
	} while(c<'0'||c>'8');
	return(c-'0'); /* ����ѡ�� */
}
