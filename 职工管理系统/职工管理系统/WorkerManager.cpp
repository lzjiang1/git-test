#include "WorkerManager.h"


WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->FileIsEmpty = true;
		this->m_Empnum = 0;
		this->m_EmpArray = NULL;
		ifs.close();
		return;

	}

	char ch;
	ifs>> ch;

	if (ifs.eof())
	{
		cout << "文件为空!" << endl;
		this->m_Empnum = 0;
		this->FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	int num = this->get_EmpNum();
	cout << "职工个数为：" << num << endl;  //测试代码
	this->m_Empnum = num;  //更新成员属性 

	this->m_EmpArray = new Worker * [this->m_Empnum];
	this->init_Emp();

	/*for (int i = 0; i < m_Empnum; i++)
	{
		cout << "职工号： " << this->m_EmpArray[i]->m_Id
			<< " 职工姓名： " << this->m_EmpArray[i]->m_Name
			<< " 部门编号： " << this->m_EmpArray[i]->m_DeptId << endl;
	}*/

	
}


void WorkerManager::showmenu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitsysteam()
{
	cout << "欢迎下次谁用" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::save()
{
	ofstream  ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_Empnum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}
int  WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	
	int num = 0;

	while (ifs>>id&&ifs>>name&&ifs>>did)
	{
		num++;
	}

	ifs.close();
	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{

		Worker* Worker = NULL;
		if (did == 1)
		{
			Worker = new Employee(id, name, 1);
		}
		else if (did == 2)
		{
			Worker = new Manager(id, name, 2);
		}
		else
		{
			Worker = new Boss(id, name, 3);
		}

		this->m_EmpArray[index] = Worker;

		index++;
	}


}
void WorkerManager::Add_Emp()
{
	cout << "请输入职工数量" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//将原空间m_EmpArray内容放到新空间
		int newSize = addNum + m_Empnum;
		Worker** newSpace = new Worker * [newSize];
		if (this->m_EmpArray != NULL)
		{
			for ( int i = 0;  i < this->m_Empnum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int Slelect;
			cout << "请输入员工编号" << endl;
			cin >> id;
			cout << "请输入员工姓名" << endl;
			cin >> name;
			cout << "请输入员工岗位" << endl;
			cin >> Slelect;

			Worker* Worker = NULL;
			switch (Slelect)
			{
			case 1://普通员工
				Worker = new Employee(id, name, 1);
				break;
			case 2://普通员工
				Worker = new Manager(id, name, 2);
			case 3://普通员工
				Worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//更新m_EmpArray

			newSpace[this->m_Empnum + i] = Worker;

		}

		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_Empnum = newSize;

		cout << "成功添加" << addNum << "名新职工！" << endl;

		this->save();
		this->FileIsEmpty = false;
		
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");

}
void WorkerManager::show_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;

	}
	else
	{
		for (int i = 0; i < m_Empnum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Del_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在" << endl;
	}
	else
	{
		cout << "请输入删除的职工编号" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1)
		{
			for (int i = index; i < this->m_Empnum; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_Empnum--;
			this->save();
			cout << "删除成功" << endl;

		}
		else
		{
			cout << "输入有误" << endl;

		}
		system("pause");
		system("cls");
	}
}
int  WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_Empnum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
	}
}