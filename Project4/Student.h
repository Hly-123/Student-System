#pragma once
#include<iostream>
using namespace std;

class Student
{
private:
	long id;
	char name[20];
	char sex[10];
	int age;
	char address[40];
	char college[20];
	double begin_score;
	Student* p;
	int esp;
	int ebp;
	int Mnum;
	int Cnum;
public:
	Student();
	Student(int Mnum);
	//~Student();
	//Student*& get_p();
	void del_p();
	void push(long id, char* n, char* s, int age, char* addr, char* colle, double begin_score);
	void pop();
	void read();
	void print();
	void show();
};
