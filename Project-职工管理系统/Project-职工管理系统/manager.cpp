#include "manager.h"

Manager::Manager(int id, string name, int departId) {
	this->id = id;
	this->name = name;
	this->departId = departId;
}

// 显示员工信息
void Manager::showInfo() {
	cout << "编号：" << this->id << "\t姓名：" << this->name
		<< "\t部门名称：" << this->getDepartName() << "\t职责 ：发任务给普通员工" << endl;
}

// 获取员工部门名称
string Manager::getDepartName() {
	return "部门经理";
}