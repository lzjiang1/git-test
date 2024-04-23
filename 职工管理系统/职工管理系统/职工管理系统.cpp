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
	Worker = new Employee(1,"职工",1);
	Worker->showInfo();
	delete Worker;

	Worker = new Manager(2, "经理", 1);
	Worker->showInfo();
	delete Worker;
	Worker = new Boss(3, "老板", 1);
	Worker->showInfo();
	delete Worker;*/

	WorkerManager wm;
	
	int choice = 0;

	

	
	while (true)
	{
		wm.showmenu();
		cout << "请输入进行的操作" << endl;
		cin >> choice;
		switch (choice)
		{
			case 0: //退出管理程序
				wm.exitsysteam();
				break;
			case 1://增加职工信息
				wm.Add_Emp();
				break;
			case 2://显示职工信息
				wm.show_Emp();
				break;
			case 3://删除离职职工
				wm.Del_Emp();
				break;
			case 4://修改职工信息
				break;
			case 5://查找职工信息
				break;
			case 6://按照编号排序
				break;
			case 7://清空所有文档
				break;
			default:
				break;
		}
	}
	system("pause");
	return  0;
}