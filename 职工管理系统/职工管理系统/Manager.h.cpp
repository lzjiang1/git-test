
#include"Manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

void Manager::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->m_DeptId
		<< "\t岗位职责： 完成老板下发的任务，将任务交给员工" << endl;
}


string Manager::getDeptName()
{
	return string("经理");
}