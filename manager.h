#pragma once
#include "worker.h"


class Manager : public Worker {
public:
	Manager(int id, string name, int departId);
	// ��ʾ������Ϣ
	virtual void showInfo();
	// ��ȡ����������
	virtual string getDepartName();
};