#include "employee.h"

Employee::Employee(int id, string name, int departId) {
	this->id = id;
	this->name = name;
	this->departId = departId;
}

Employee::~Employee() {
	cout << "Employee����" << endl;
}

// ��ʾԱ����Ϣ
void Employee::showInfo() {
	cout << "��ţ�" << this->id << "\t������" << this->name
		<< "\t�������ƣ�" << this->getDepartName() << "\tְ�� ���ɻ�" << endl;
}

// ��ȡԱ����������
string Employee::getDepartName() {
	return "��ͨԱ��";
}