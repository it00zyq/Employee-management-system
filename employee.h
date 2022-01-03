#pragma once
#include "worker.h"


class Employee : public Worker {
public:
	Employee(int id, string name, int departId);
	~Employee();
	// 显示员工信息
	virtual void showInfo();
	// 获取员工部门名称
	virtual string getDepartName();
};