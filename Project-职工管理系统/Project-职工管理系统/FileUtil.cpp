#include "FileUtil.h"

void FileUtil::write(Node *node) {
	ofstream ofs;
	// ��׷�ӵķ�ʽ���ļ�
	ofs.open(FILE_NAME, ios::out | ios::app);
	// ����ӵ�ְ����Ϣд���ļ�
	Node *cur = node;
	while (cur->next != NULL) {
		Worker *p = cur->next->worker;
		ofs << p->id << " " << p->name << " " << p->departId << endl;
		cur = cur->next;
	}
	ofs.close();
}