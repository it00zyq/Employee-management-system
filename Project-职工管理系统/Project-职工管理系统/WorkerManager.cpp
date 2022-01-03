#include "workerManager.h"

WorkerManager::WorkerManager() {
	this->count = 0;
	this->linkHead = new Node;
	this->linkHead->next = NULL;
	this->linkHead->worker = NULL;
	this->linkTail = this->linkHead;

	// �����ļ�����ʼ��ְ����Ϣ����
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
	cout << "******ְ������ϵͳ******" << endl;
	cout << "************************" << endl;
	cout << "*    1-���ְ����Ϣ    *" << endl;
	cout << "*    2-��ʾְ����Ϣ    *" << endl;
	cout << "*    3-ɾ��ְ����Ϣ    *" << endl;
	cout << "*    4-�޸�ְ����Ϣ    *" << endl;
	cout << "*    5-����ְ����Ϣ    *" << endl;
	cout << "*    6-����ְ����Ϣ    *" << endl;
	cout << "*    7-���ְ����Ϣ    *" << endl;
	cout << "*    0-�˳�ְ��ϵͳ    *" << endl;
	cout << "************************" << endl;
	cout << "*����������ѡ�� - ";
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

	cout << "���������ְ��������";
	cin >> n;
	while (n < 0 || n > MAX_ADD){
		cout << "��������ȷ����ְ��������" << endl;
		cin >> n;
	}

	for (int i = 1; i <= n; i++) {
		cout << "�������" << i << "��ְ����Ϣ��" << endl;
		cout << "��ţ�";
		cin >> id;

		cout << "������";
		cin >> name;

		cout << "��ѡ���ţ�" << endl;
		cout << "1-��ͨԱ��" << endl;
		cout << "2-���ž���" << endl;
		cout << "3-��˾�ܲ�" << endl;
		cin >> departId;
		while (departId < 1 || departId > 3) {
			cout << "��������ȷ�Ĳ��ű�ţ�";
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

		// ����Node��㣬���µ�Ա����Ϣ���ӵ�������
		Node *temp = new Node;
		temp->worker = p;
		temp->next = NULL;
		cur->next = temp;
		cur = cur->next;
	}


	ofstream ofs;
	// ��׷�ӵķ�ʽ���ļ�
	ofs.open(FILE_NAME, ios::out | ios::app);
	// ����ӵ�ְ����Ϣд���ļ�
	cur = newLink;
	while (cur ->next != NULL) {
		Worker *p = cur->next->worker;
		ofs << p->id << " " << p->name << " " << p->departId << endl;
		cur = cur->next;
	}
	ofs.close();

	// ����ӵ�ְ����Ϣ���ӵ���β
	Node *pp = newLink;
	newLink = newLink->next;
	this->linkTail->next = newLink;
	this->linkTail = cur;
	delete pp;
	// ����ְ������
	this->count += n;
}

void WorkerManager::showWorker() {
	if (this->count == 0) {
		cout << "ְ����ϢΪ�գ�" << endl;
		return;
	}
	cout << "ְ������Ϊ��" << this->count << endl;
	Node *cur = this->linkHead;
	while (cur->next != NULL){ 
		cur = cur->next;
		cur->worker->showInfo();
	}
}

void WorkerManager::deleteWorker() {
	int id;
	cout << "������ɾ��ְ����Id��";
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
			// ���ļ����������д
			ofs.open(FILE_NAME, ios::out);
			// ɾ�����ְ����Ϣд���ļ�
			cur = this->linkHead;
			while (cur->next != NULL) {
				Worker *p = cur->next->worker;
				ofs << p->id << " " << p->name << " " << p->departId << endl;
				cur = cur->next;
			}
			ofs.close();

			this->count --;
			cout << "�ѳɹ�ɾ��!" << endl;
			return ;
		}
		cur = cur->next;
	}

	cout << "���޴���!" << endl;
}

void WorkerManager::modifyWorker() {
	int id;
	cout << "�������޸�ְ����Id��";
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
		cout << "���޴���!" << endl;
	} else {
		Worker *worker = cur->next->worker;
		cout << "������ְ���µ���Ϣ��" << endl;
		cout << "��ţ�";
		cin >> worker->id;

		cout << "������";
		cin >> worker->name;

		cout << "��ѡ���ţ�" << endl;
		cout << "1-��ͨԱ��" << endl;
		cout << "2-���ž���" << endl;
		cout << "3-��˾�ܲ�" << endl;
		cin >> worker->departId;
		while (worker->departId < 1 || worker->departId > 3) {
			cout << "��������ȷ�Ĳ��ű�ţ�";
			cin >> worker->departId;
		}

		ofstream ofs;
		// ���ļ����������д
		ofs.open(FILE_NAME, ios::out);
		// �޸ĺ��ְ����Ϣд���ļ�
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
	cout << "���������ְ����Id��";
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
		cout << "���޴���!" << endl;
	}
}

void WorkerManager::sortWorker() {
	if (this->count < 2) {
		return;
	}
	Node *head = this->linkHead;
	Node *cur, *pre, *tp, *tc;
	for (int i = 1; i < this->count; i++) {
		// �ҵ���ǰҪ��������Ľ��
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
				// Ŀ���������Ͽ�
				pre->next = cur->next;
				// Ŀ�������ǰ���Ѿ��ź���Ĳ���
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
	// ���ļ����������д
	ofs.open(FILE_NAME, ios::out);
	// ������ְ����Ϣд���ļ�
	cur = this->linkHead;
	while (cur->next != NULL) {
		Worker *p = cur->next->worker;
		ofs << p->id << " " << p->name << " " << p->departId << endl;
		cur = cur->next;
	}
	ofs.close();

	cout << "ְ����Ϣ�Ѱ��������������ɣ�" << endl;
}

void WorkerManager::clearWorker() {
	int confirm = 0;
	cout << "�Ƿ�ȷ���������ְ����Ϣ(0-��1-��)��";
	cin >> confirm;
	while (confirm != 0 && confirm != 1){
		cout << "������(0-��1-��)��";
		cin >> confirm;
	}
	if (confirm == 1) {
		// remove(char *filename),0 - �ɹ���-1 - ʧ��
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
			cout << "����ɹ���" << endl;
		} else {
			cout << "���ʧ�ܣ�" << endl;
		}
	}
}