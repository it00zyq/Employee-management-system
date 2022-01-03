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
			cout << "您已成功退出系统！" << endl;
			system("pause");
			return 0;
		default:
			cout << "输入有误，请输入正确编号！" << endl;
			break;
		}
	}

	return 0;
}