#include "boss.h"

Boss::Boss(int id, string name, int departId) {
	this->id = id;
	this->name = name;
	this->departId = departId;
}

// ��ʾԱ����Ϣ
void Boss::showInfo() {
	cout << "��ţ�" << this->id << "\t������" << this->name
		<< "\t�������ƣ�" << this->getDepartName() << "\tְ�� �������������" << endl;
}

// ��ȡԱ����������
string Boss::getDepartName() {
	return "��˾�ܲ�";
}