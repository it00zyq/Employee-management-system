#include "employee.h"

Employee::Employee(int id, string name, int departId) {
	this->id = id;
	this->name = name;
	this->departId = departId;
}

Employee::~Employee() {
	cout << "Employee析构" << endl;
}

// 显示员工信息
void Employee::showInfo() {
	cout << "编号：" << this->id << "\t姓名：" << this->name
		<< "\t部门名称：" << this->getDepartName() << "\t职责 ：干活" << endl;
}

// 获取员工部门名称
string Employee::getDepartName() {
	return "普通员工";
}