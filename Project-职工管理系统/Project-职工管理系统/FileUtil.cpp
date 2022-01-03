#include "FileUtil.h"

void FileUtil::write(Node *node) {
	ofstream ofs;
	// 以追加的方式打开文件
	ofs.open(FILE_NAME, ios::out | ios::app);
	// 新添加的职工信息写入文件
	Node *cur = node;
	while (cur->next != NULL) {
		Worker *p = cur->next->worker;
		ofs << p->id << " " << p->name << " " << p->departId << endl;
		cur = cur->next;
	}
	ofs.close();
}