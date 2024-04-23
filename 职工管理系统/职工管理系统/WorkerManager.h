#pragma once
#include <iostream>
using namespace std;
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
#include"fstream"
#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();

	void showmenu();
	void exitsysteam();

	int m_Empnum;
	Worker** m_EmpArray;

	void Add_Emp();
	void save();

	bool FileIsEmpty;
	int get_EmpNum();
	void init_Emp();
	void show_Emp();

	void Del_Emp();
	int  IsExist(int id);


};


