#pragma once
#include "worker.h"


class Employee : public Worker {
public:
	Employee(int id, string name, int departId);
	~Employee();
	// ��ʾԱ����Ϣ
	virtual void showInfo();
	// ��ȡԱ����������
	virtual string getDepartName();
};