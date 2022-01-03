#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker {
public:
	int id;
	string name;
	int departId;

	// 显示员工信息
	virtual void showInfo() = 0;
	// 获取员工部门名称
	virtual string getDepartName() = 0;
};