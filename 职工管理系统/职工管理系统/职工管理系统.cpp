#include "WorkerManager.h"
#include <iostream>
#include "Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
using namespace std;


int main()
{
	/*Worker * Worker = NULL;
	Worker = new Employee(1,"ְ��",1);
	Worker->showInfo();
	delete Worker;

	Worker = new Manager(2, "����", 1);
	Worker->showInfo();
	delete Worker;
	Worker = new Boss(3, "�ϰ�", 1);
	Worker->showInfo();
	delete Worker;*/

	WorkerManager wm;
	
	int choice = 0;

	

	
	while (true)
	{
		wm.showmenu();
		cout << "��������еĲ���" << endl;
		cin >> choice;
		switch (choice)
		{
			case 0: //�˳��������
				wm.exitsysteam();
				break;
			case 1://����ְ����Ϣ
				wm.Add_Emp();
				break;
			case 2://��ʾְ����Ϣ
				wm.show_Emp();
				break;
			case 3://ɾ����ְְ��
				wm.Del_Emp();
				break;
			case 4://�޸�ְ����Ϣ
				break;
			case 5://����ְ����Ϣ
				break;
			case 6://���ձ������
				break;
			case 7://��������ĵ�
				break;
			default:
				break;
		}
	}
	system("pause");
	return  0;
}