#include "manager.h"

Manager::Manager(int id, string name, int departId) {
	this->id = id;
	this->name = name;
	this->departId = departId;
}

// ��ʾԱ����Ϣ
void Manager::showInfo() {
	cout << "��ţ�" << this->id << "\t������" << this->name
		<< "\t�������ƣ�" << this->getDepartName() << "\tְ�� �����������ͨԱ��" << endl;
}

// ��ȡԱ����������
string Manager::getDepartName() {
	return "���ž���";
}