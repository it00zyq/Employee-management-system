#pragma once
#include "worker.h"


class Boss : public Worker {
public:
	Boss(int id, string name, int departId);
	// ��ʾ�ϰ���Ϣ
	virtual void showInfo();
	// ��ȡ�ϰ岿������
	virtual string getDepartName();
};