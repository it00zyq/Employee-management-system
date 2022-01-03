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

	// ��ʾ�˵�
	void showMenu();

	// ���ְ��
	void addWorker();

	// ���ְ��
	void showWorker();

	// ɾ��ְ��
	void deleteWorker();

	// �޸�ְ����Ϣ
	void modifyWorker();

	// ����ְ����Ϣ
	void searchWorker();

	// ����ְ����Ϣ
	void sortWorker();

	// ���ְ����Ϣ
	void clearWorker();
	
	// ְ������
	int count;

	// ְ�������ͷָ��
	Node *linkHead;

	// ְ�������βָ��
	Node *linkTail;

};