
#include"Boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->m_DeptId
		<< "\t��λְ�� �������·���Ա��" << endl;
}


string Boss::getDeptName()
{
	return string("�ϰ�");
}