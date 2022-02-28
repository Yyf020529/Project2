#include <iostream>
using namespace std;
class LNode		//单链表的结点类
{
public:
	int data;
	LNode* next;
	LNode()
	{
		next = NULL;
	}

};

class LinkList		//单链表类
{
public:
	LNode* head;	//头指针
	LinkList();		//构造函数
	void createList(int);		//创建单链表
	void unionList(LinkList, LinkList);		//求并集
	void interSection(LinkList, LinkList);		//求交集
	bool isPresent(int);		//查找某元素是否存在
	void insertFoot(int);		//尾插法
	void printList();		//打印
	void cha(LinkList L1, LinkList L2);
};


//构造函数
LinkList::LinkList()
{
	head = new LNode;
}

//创建单链表
void LinkList::createList(int l)
{
	int value;
	head->next = NULL;
	for (int i = 0; i < l; i++) {
		LNode* p;
		p = new LNode;
		p->next = NULL;
		cin >> value;
		p->data = value;
		insertFoot(p->data);	//尾插法

	}
	cout << "创建完成!" << endl;

}



//单链表的尾插法
void LinkList::insertFoot(int n)
{
	LNode* p, * current;
	p = new LNode;
	p->data = n;
	p->next = NULL;
	current = head;
	while (current->next) {
		current = current->next;
	}
	current->next = p;

}

//查找某元素是否存在于当前单链表
bool LinkList::isPresent(int n)
{
	LNode* current;
	current = head->next;
	while (current != NULL) {
		if (current->data == n) 
		{
			return 1;//存在
		}
		current = current->next;//指向下一个指针域
	}
	return 0;
}

//求并集
void LinkList::unionList(LinkList L1, LinkList L2)
{
	LNode* p, * q;
	p = L1.head->next;
	while (p != NULL) //将单链表A的所有元素复制到新的单链表中
	{			
		insertFoot(p->data);	//尾插法
		p = p->next;

	}

	q = L2.head->next;
	while (q != NULL) {
		if (isPresent(q->data) == 0) 
		{
			insertFoot(q->data);		//尾插法

		}
		q = q->next;

	}

}
//求差集
void LinkList::cha(LinkList L1, LinkList L2)
{

}
//求交集
void LinkList::interSection(LinkList L1, LinkList L2)
{
	LNode* q;
	q = L2.head->next;
	while (q != NULL) {
		if (L1.isPresent(q->data) == 1) //若存在一个不重复的元素
		{
			insertFoot(q->data);		//尾插法
		}
		q = q->next;

	}

}

//打印单链表
void LinkList::printList()
{
	LNode* p;
	p = head->next;
	while (p->next != NULL) {
		cout << p->data << "->";
		p = p->next;

	}
	cout << p->data << endl;
}

void main()
{
	int l1, l2;
	LinkList LA;		//创建一个名叫LA的单链表对象
	LinkList LB;		//创建一个名叫LB的单链表对象
	LinkList LC;		//存放并集
	LinkList LD;		//存放交集
	cout << "请输入单链表A的长度：";
	cin >> l1;
	LA.createList(l1);
	cout << "请输入单链表B的长度：";
	cin >> l2;
	LB.createList(l2);
	LA.printList();
	LB.printList();
	cout << "并集为：" << endl;
	LC.unionList(LA, LB);
	LC.printList();

	cout << "交集为：" << endl;
	LD.interSection(LA, LB);
	if (LD.head->next) {
		LD.printList();
	}
	else {
		cout << "没有交集！" << endl;
	}

}

