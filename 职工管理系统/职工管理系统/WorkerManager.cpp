#include "WorkerManager.h"


WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
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
		cout << "�ļ�Ϊ��!" << endl;
		this->m_Empnum = 0;
		this->FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;  //���Դ���
	this->m_Empnum = num;  //���³�Ա���� 

	this->m_EmpArray = new Worker * [this->m_Empnum];
	this->init_Emp();

	/*for (int i = 0; i < m_Empnum; i++)
	{
		cout << "ְ���ţ� " << this->m_EmpArray[i]->m_Id
			<< " ְ�������� " << this->m_EmpArray[i]->m_Name
			<< " ���ű�ţ� " << this->m_EmpArray[i]->m_DeptId << endl;
	}*/

	
}


void WorkerManager::showmenu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitsysteam()
{
	cout << "��ӭ�´�˭��" << endl;
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
	cout << "������ְ������" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//��ԭ�ռ�m_EmpArray���ݷŵ��¿ռ�
		int newSize = addNum + m_Empnum;
		Worker** newSpace = new Worker * [newSize];
		if (this->m_EmpArray != NULL)
		{
			for ( int i = 0;  i < this->m_Empnum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//����������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int Slelect;
			cout << "������Ա�����" << endl;
			cin >> id;
			cout << "������Ա������" << endl;
			cin >> name;
			cout << "������Ա����λ" << endl;
			cin >> Slelect;

			Worker* Worker = NULL;
			switch (Slelect)
			{
			case 1://��ͨԱ��
				Worker = new Employee(id, name, 1);
				break;
			case 2://��ͨԱ��
				Worker = new Manager(id, name, 2);
			case 3://��ͨԱ��
				Worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//����m_EmpArray

			newSpace[this->m_Empnum + i] = Worker;

		}

		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_Empnum = newSize;

		cout << "�ɹ����" << addNum << "����ְ����" << endl;

		this->save();
		this->FileIsEmpty = false;
		
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");

}
void WorkerManager::show_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;

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
		cout << "�ļ�������" << endl;
	}
	else
	{
		cout << "������ɾ����ְ�����" << endl;
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
			cout << "ɾ���ɹ�" << endl;

		}
		else
		{
			cout << "��������" << endl;

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