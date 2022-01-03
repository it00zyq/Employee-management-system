#include "workerManager.h"

WorkerManager::WorkerManager() {
	this->count = 0;
	this->linkHead = new Node;
	this->linkHead->next = NULL;
	this->linkHead->worker = NULL;
	this->linkTail = this->linkHead;

	// 读出文件，初始化职工信息链表
	ifstream ifs;
	ifs.open(FILE_NAME, ios::in);
	if (ifs.is_open()) {
		int id;
		string name;
		int departId;
		Worker *p = NULL;
		while (ifs >> id && ifs >> name && ifs >> departId){
			switch (departId) {
			case 1:
				p = new Employee(id, name, departId);
				break;
			case 2:
				p = new Manager(id, name, departId);
				break;
			case 3:
				p = new Boss(id, name, departId);
				break;
			default:
				break;
			}
			Node *node = new Node;
			node->worker = p;
			node->next = NULL;
			this->linkTail->next = node;
			this->linkTail = this->linkTail->next;
			this->count ++;
		}
	}
	ifs.close();
}
WorkerManager::~WorkerManager() {
	Node *cur = this->linkHead;
	Node *p = NULL;
	while (cur != NULL) {
		p = cur;
		cur = cur->next;
		delete p;
		p = NULL;
	}
}

void WorkerManager::showMenu() {
	cout << "************************" << endl;
	cout << "******职工管理系统******" << endl;
	cout << "************************" << endl;
	cout << "*    1-添加职工信息    *" << endl;
	cout << "*    2-显示职工信息    *" << endl;
	cout << "*    3-删除职工信息    *" << endl;
	cout << "*    4-修改职工信息    *" << endl;
	cout << "*    5-搜索职工信息    *" << endl;
	cout << "*    6-排序职工信息    *" << endl;
	cout << "*    7-清空职工信息    *" << endl;
	cout << "*    0-退出职工系统    *" << endl;
	cout << "************************" << endl;
	cout << "*请输入您的选择 - ";
}

void WorkerManager::addWorker() {
	int n = 0;
	int id;
	string name;
	int departId;
	Node *newLink = new Node;
	newLink->worker = NULL;
	newLink->next = NULL;
	Node *cur = newLink;

	cout << "请输入添加职工个数：";
	cin >> n;
	while (n < 0 || n > MAX_ADD){
		cout << "请输入正确的新职工个数：" << endl;
		cin >> n;
	}

	for (int i = 1; i <= n; i++) {
		cout << "请输入第" << i << "个职工信息：" << endl;
		cout << "编号：";
		cin >> id;

		cout << "姓名：";
		cin >> name;

		cout << "请选择部门：" << endl;
		cout << "1-普通员工" << endl;
		cout << "2-部门经理" << endl;
		cout << "3-公司总裁" << endl;
		cin >> departId;
		while (departId < 1 || departId > 3) {
			cout << "请输入正确的部门编号：";
			cin >> departId;
		}

		Worker *p = NULL;
		switch (departId){
		case 1:
			p = new Employee(id, name, departId);
			break;
		case 2:
			p = new Manager(id, name, departId);
			break;
		case 3:
			p = new Boss(id, name, departId);
			break;
		default:
			break;
		}

		// 生成Node结点，将新的员工信息链接到链表上
		Node *temp = new Node;
		temp->worker = p;
		temp->next = NULL;
		cur->next = temp;
		cur = cur->next;
	}


	ofstream ofs;
	// 以追加的方式打开文件
	ofs.open(FILE_NAME, ios::out | ios::app);
	// 新添加的职工信息写入文件
	cur = newLink;
	while (cur ->next != NULL) {
		Worker *p = cur->next->worker;
		ofs << p->id << " " << p->name << " " << p->departId << endl;
		cur = cur->next;
	}
	ofs.close();

	// 新添加的职工信息链接到表尾
	Node *pp = newLink;
	newLink = newLink->next;
	this->linkTail->next = newLink;
	this->linkTail = cur;
	delete pp;
	// 更新职工人数
	this->count += n;
}

void WorkerManager::showWorker() {
	if (this->count == 0) {
		cout << "职工信息为空！" << endl;
		return;
	}
	cout << "职工人数为：" << this->count << endl;
	Node *cur = this->linkHead;
	while (cur->next != NULL){ 
		cur = cur->next;
		cur->worker->showInfo();
	}
}

void WorkerManager::deleteWorker() {
	int id;
	cout << "请输入删除职工的Id：";
	cin >> id;
	Node *cur = this->linkHead;
	while (cur->next != NULL){
		Worker *worker = cur->next->worker;
		if (worker->id == id) {
			Node *p = cur->next;
			cur->next = p->next;
			if (this->linkTail == p) {
				linkTail = cur;
			}
			delete p;
			p = NULL;

			ofstream ofs;
			// 打开文件，先清空再写
			ofs.open(FILE_NAME, ios::out);
			// 删除后的职工信息写入文件
			cur = this->linkHead;
			while (cur->next != NULL) {
				Worker *p = cur->next->worker;
				ofs << p->id << " " << p->name << " " << p->departId << endl;
				cur = cur->next;
			}
			ofs.close();

			this->count --;
			cout << "已成功删除!" << endl;
			return ;
		}
		cur = cur->next;
	}

	cout << "查无此人!" << endl;
}

void WorkerManager::modifyWorker() {
	int id;
	cout << "请输入修改职工的Id：";
	cin >> id;
	Node *cur = this->linkHead;
	while (cur->next != NULL) {
		Worker *worker = cur->next->worker;
		if (worker->id == id) {
			break;
		}
		cur = cur->next;
	}

	if (cur->next == NULL) {
		cout << "查无此人!" << endl;
	} else {
		Worker *worker = cur->next->worker;
		cout << "请输入职工新的信息：" << endl;
		cout << "编号：";
		cin >> worker->id;

		cout << "姓名：";
		cin >> worker->name;

		cout << "请选择部门：" << endl;
		cout << "1-普通员工" << endl;
		cout << "2-部门经理" << endl;
		cout << "3-公司总裁" << endl;
		cin >> worker->departId;
		while (worker->departId < 1 || worker->departId > 3) {
			cout << "请输入正确的部门编号：";
			cin >> worker->departId;
		}

		ofstream ofs;
		// 打开文件，先清空再写
		ofs.open(FILE_NAME, ios::out);
		// 修改后的职工信息写入文件
		cur = this->linkHead;
		while (cur->next != NULL) {
			Worker *p = cur->next->worker;
			ofs << p->id << " " << p->name << " " << p->departId << endl;
			cur = cur->next;
		}
		ofs.close();
	}
}

void WorkerManager::searchWorker() {
	int id;
	cout << "请输入查找职工的Id：";
	cin >> id;
	Node *cur = this->linkHead;
	Worker *worker = NULL;
	while (cur->next != NULL) {
		worker = cur->next->worker;
		if (worker->id == id) {
			break;
		}
		cur = cur->next;
	}

	if (cur->next != NULL) {
		worker->showInfo();
	} else {
		cout << "查无此人!" << endl;
	}
}

void WorkerManager::sortWorker() {
	if (this->count < 2) {
		return;
	}
	Node *head = this->linkHead;
	Node *cur, *pre, *tp, *tc;
	for (int i = 1; i < this->count; i++) {
		// 找到当前要进行排序的结点
		pre = this->linkHead;
		cur = pre->next;
		for (int j = 0; j < i; j ++) {
			pre = pre->next;
			cur = cur->next;
		}
		
		tp = this->linkHead;
		tc = tp->next;
		for (int j = 0; j < i; j++) {
			if (cur->worker->id < tc->worker->id) {
				// 目标结点从链表断开
				pre->next = cur->next;
				// 目标结点接入前边已经排好序的部分
				tp->next = cur;
				cur->next = tc;
				break;
			} else {
				tp = tp->next;
				tc = tc->next;
			}
		}
	}

	ofstream ofs;
	// 打开文件，先清空再写
	ofs.open(FILE_NAME, ios::out);
	// 排序后的职工信息写入文件
	cur = this->linkHead;
	while (cur->next != NULL) {
		Worker *p = cur->next->worker;
		ofs << p->id << " " << p->name << " " << p->departId << endl;
		cur = cur->next;
	}
	ofs.close();

	cout << "职工信息已按编号升序排序完成！" << endl;
}

void WorkerManager::clearWorker() {
	int confirm = 0;
	cout << "是否确定清除所有职工信息(0-否，1-是)：";
	cin >> confirm;
	while (confirm != 0 && confirm != 1){
		cout << "请输入(0-否，1-是)：";
		cin >> confirm;
	}
	if (confirm == 1) {
		// remove(char *filename),0 - 成功，-1 - 失败
		if (remove(FILE_NAME) == 0) {
			Node *cur = this->linkHead->next;
			Node *p = NULL;
			while (cur != NULL) {
				p = cur;
				cur = cur->next;
				delete p;
				p = NULL;
			}
			this->linkHead->next = NULL;
			this->linkTail = this->linkHead;
			this->count = 0;
			cout << "清除成功！" << endl;
		} else {
			cout << "清除失败！" << endl;
		}
	}
}