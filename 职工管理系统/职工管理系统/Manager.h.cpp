
#include"Manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->m_DeptId
		<< "\t��λְ�� ����ϰ��·������񣬽����񽻸�Ա��" << endl;
}


string Manager::getDeptName()
{
	return string("����");
}