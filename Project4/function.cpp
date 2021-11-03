#include"Student.h"
using namespace std;

Student::Student()
{
	NULL;
}

Student::Student(int Mnum)
{
	this->Mnum = Mnum;
	p = new Student[Mnum];
	Cnum = 0;
	esp = Mnum;
	ebp = Mnum;
}
//析构函数
/*Student::~Student()
{
	NULL;
}*/
//delete[] p的变式方法
/*
Student*& Student::get_p()
{
	return p;
}
*/
void Student::del_p()
{
	delete[] p;
}

void Student::print()
{
	cout << "学号：" << p[esp].id
			<< "\t姓名：" << p[esp].name
			<< "\t性别：" << p[esp].sex
			<< "\t年龄：" << p[esp].age
			<< "\t家庭地址：" << p[esp].address
			<< "\t学院：" << p[esp].college
			<< "\t入学成绩：" << p[esp].begin_score << endl;
}

void Student::push(long id,char* n,char* s,int age,char* addr,char* colle,double begin_score)
{
	if(esp == 0)
	{
		cout << "存放学生信息的堆栈已达上限" << endl;
	}
	else
	{
		Cnum++;
		esp = Mnum - Cnum;
		ebp = esp + 1;
		this-> p[esp].id = id;
		strcpy_s(p[esp].name, n);
		strcpy_s(p[esp].address, addr);
		strcpy_s(p[esp].sex, s);
		strcpy_s(p[esp].college, colle); 
		this->p[esp].age = age;
		this->p[esp].begin_score = begin_score;
		cout << "将学生信息存放堆栈中操作成功！" << endl;
		print();
	}
	
}

void Student::pop()
{
	if (esp == Mnum)
	{
		cout << "堆栈中无存放学生信息！" << endl;
	}
	else
	{
		
		cout << "弹出的学生信息\n";
		print();
		Cnum--;
		esp = Mnum - Cnum;
		ebp = esp + 1;
	}
}

void Student::read()
{
	if (esp == Mnum)
	{
		cout << "堆栈中无存放学生信息！" << endl;
	}
	else
	{
		cout << "读取的学生信息\n";
		print();
	}
}

void Student::show()
{
	for (int i = esp; i < Mnum; i++)
	{
		cout << "学号：" << p[i].id
			<< "\t姓名：" << p[i].name
			<< "\t性别：" << p[i].sex
			<< "\t年龄：" << p[i].age
			<< "\t家庭地址：" << p[i].address
			<< "\t学院：" << p[i].college
			<< "\t入学成绩：" << p[i].begin_score 
			<< '\n' << endl;
	}
}