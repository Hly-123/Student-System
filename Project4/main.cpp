#include"Student.h"
using namespace std;

int main()
{
	int flag = 0;
	int Mnum = 0;
	bool main_judge = true;

	long id = 0;
	int age = 0;
	double begin_score = 0;
	char n[20] = { 0 };
	char addr[40] = { 0 };
	char colle[20] = { 0 };
	char s[10] = { 0 };

	cout << "请您输入总共需存放的学生个数" << endl;
	cin >> Mnum;
	Student STU_STACK(Mnum);
	while (main_judge)
	{
		cout << "请做出相应的操作选择，【1-入栈（存储学生信息），2-读栈（读取栈区学生信息），3-出栈（弹出栈区学生信息），4-显示栈区所有信息 ，0-停止输入】" << endl;
		cin >> flag;
		switch (flag)
		{
		case 1:
		{
			bool bpush = true;
			char judge = 0;
			while (bpush)
			{
				cout << "请您依次输入学号、姓名、性别、年龄、家庭地址、学院和入学成绩（以空格分隔）" << endl;
				try
				{
					cin >> id >> n >> s >> age >> addr >> colle >> begin_score;			
					if (age <= 0)
					{
						throw age;
					}
					if (begin_score <= 0)
					{
						throw begin_score;
					}
				}

				catch(int)
				{
					cout << "输入学生年龄有误！请重新输入年龄" << endl;
					cin >>age;
					if (begin_score <= 0)
					{
						cout << "输入学生入学成绩有误！请重新输入入学成绩（正数）" << endl;
						cin >> begin_score;
					}
				}
				catch (double)
				{
					cout << "输入学生入学成绩有误！请重新输入入学成绩（正数）" << endl;
					cin >> begin_score;
				}

				STU_STACK.push(id, n, s, age, addr, colle, begin_score);
				cout << "请问是否继续输入下一个学生的信息（y/n）" << endl;
				cin >> judge;
				if (judge == 'y')	bpush = true;
				else bpush = false;
			}
			break;
		}
		case 2:
		{
			STU_STACK.read();
			break;
		}
		case 3:
		{
			STU_STACK.pop();
			break;
		}
		case 4:
		{
			STU_STACK.show();
			break;
		}
		case 0:
		{
			main_judge = false;
			STU_STACK.del_p();
			/*
			Student* pp = STU_STACK.get_p();
			delete[] pp;
			*/
			break;
		}
		}
		cout << endl;
	}
	system("pause");
}