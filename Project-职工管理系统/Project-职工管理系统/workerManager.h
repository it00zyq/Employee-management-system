#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#define MAX_ADD 100
#define FILE_NAME "./worker.txt"
using namespace std;

struct Node {
	Worker *worker;
	Node *next;
};

class WorkerManager {
public:
	WorkerManager();
	~WorkerManager();

	// 显示菜单
	void showMenu();

	// 添加职工
	void addWorker();

	// 添加职工
	void showWorker();

	// 删除职工
	void deleteWorker();

	// 修改职工信息
	void modifyWorker();

	// 搜索职工信息
	void searchWorker();

	// 排序职工信息
	void sortWorker();

	// 清空职工信息
	void clearWorker();
	
	// 职工人数
	int count;

	// 职工链表表头指针
	Node *linkHead;

	// 职工链表表尾指针
	Node *linkTail;

};