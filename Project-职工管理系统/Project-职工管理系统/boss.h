#pragma once
#include "worker.h"


class Boss : public Worker {
public:
	Boss(int id, string name, int departId);
	// 显示老板信息
	virtual void showInfo();
	// 获取老板部门名称
	virtual string getDepartName();
};