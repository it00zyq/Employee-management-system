#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker {
public:
	int id;
	string name;
	int departId;

	// ��ʾԱ����Ϣ
	virtual void showInfo() = 0;
	// ��ȡԱ����������
	virtual string getDepartName() = 0;
};