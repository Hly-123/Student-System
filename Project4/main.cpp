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

	cout << "���������ܹ����ŵ�ѧ������" << endl;
	cin >> Mnum;
	Student STU_STACK(Mnum);
	while (main_judge)
	{
		cout << "��������Ӧ�Ĳ���ѡ�񣬡�1-��ջ���洢ѧ����Ϣ����2-��ջ����ȡջ��ѧ����Ϣ����3-��ջ������ջ��ѧ����Ϣ����4-��ʾջ��������Ϣ ��0-ֹͣ���롿" << endl;
		cin >> flag;
		switch (flag)
		{
		case 1:
		{
			bool bpush = true;
			char judge = 0;
			while (bpush)
			{
				cout << "������������ѧ�š��������Ա����䡢��ͥ��ַ��ѧԺ����ѧ�ɼ����Կո�ָ���" << endl;
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
					cout << "����ѧ������������������������" << endl;
					cin >>age;
					if (begin_score <= 0)
					{
						cout << "����ѧ����ѧ�ɼ�����������������ѧ�ɼ���������" << endl;
						cin >> begin_score;
					}
				}
				catch (double)
				{
					cout << "����ѧ����ѧ�ɼ�����������������ѧ�ɼ���������" << endl;
					cin >> begin_score;
				}

				STU_STACK.push(id, n, s, age, addr, colle, begin_score);
				cout << "�����Ƿ����������һ��ѧ������Ϣ��y/n��" << endl;
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