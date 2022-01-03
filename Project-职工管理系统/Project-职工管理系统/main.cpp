#include<iostream>
#include "workerManager.h"
using namespace std;

int main() {
	WorkerManager manager;
	int choice = 0;
	while (true) {
		system("pause");
		system("cls");
		manager.showMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			manager.addWorker();
			break;
		case 2:
			manager.showWorker();
			break;
		case 3:
			manager.deleteWorker();
			break;
		case 4:
			manager.modifyWorker();
			break;
		case 5:
			manager.searchWorker();
			break;
		case 6:
			manager.sortWorker();
			break;
		case 7:
			manager.clearWorker();
			break;
		case 0:
			cout << "���ѳɹ��˳�ϵͳ��" << endl;
			system("pause");
			return 0;
		default:
			cout << "����������������ȷ��ţ�" << endl;
			break;
		}
	}

	return 0;
}