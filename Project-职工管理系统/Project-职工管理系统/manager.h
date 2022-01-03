#pragma once
#include "worker.h"


class Manager : public Worker {
public:
	Manager(int id, string name, int departId);
	// 显示经理信息
	virtual void showInfo();
	// 获取经理部门名称
	virtual string getDepartName();
};