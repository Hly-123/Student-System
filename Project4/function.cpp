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
//��������
/*Student::~Student()
{
	NULL;
}*/
//delete[] p�ı�ʽ����
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
	cout << "ѧ�ţ�" << p[esp].id
			<< "\t������" << p[esp].name
			<< "\t�Ա�" << p[esp].sex
			<< "\t���䣺" << p[esp].age
			<< "\t��ͥ��ַ��" << p[esp].address
			<< "\tѧԺ��" << p[esp].college
			<< "\t��ѧ�ɼ���" << p[esp].begin_score << endl;
}

void Student::push(long id,char* n,char* s,int age,char* addr,char* colle,double begin_score)
{
	if(esp == 0)
	{
		cout << "���ѧ����Ϣ�Ķ�ջ�Ѵ�����" << endl;
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
		cout << "��ѧ����Ϣ��Ŷ�ջ�в����ɹ���" << endl;
		print();
	}
	
}

void Student::pop()
{
	if (esp == Mnum)
	{
		cout << "��ջ���޴��ѧ����Ϣ��" << endl;
	}
	else
	{
		
		cout << "������ѧ����Ϣ\n";
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
		cout << "��ջ���޴��ѧ����Ϣ��" << endl;
	}
	else
	{
		cout << "��ȡ��ѧ����Ϣ\n";
		print();
	}
}

void Student::show()
{
	for (int i = esp; i < Mnum; i++)
	{
		cout << "ѧ�ţ�" << p[i].id
			<< "\t������" << p[i].name
			<< "\t�Ա�" << p[i].sex
			<< "\t���䣺" << p[i].age
			<< "\t��ͥ��ַ��" << p[i].address
			<< "\tѧԺ��" << p[i].college
			<< "\t��ѧ�ɼ���" << p[i].begin_score 
			<< '\n' << endl;
	}
}