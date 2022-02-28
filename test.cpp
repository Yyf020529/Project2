#include <iostream>
using namespace std;
class LNode		//������Ľ����
{
public:
	int data;
	LNode* next;
	LNode()
	{
		next = NULL;
	}

};

class LinkList		//��������
{
public:
	LNode* head;	//ͷָ��
	LinkList();		//���캯��
	void createList(int);		//����������
	void unionList(LinkList, LinkList);		//�󲢼�
	void interSection(LinkList, LinkList);		//�󽻼�
	bool isPresent(int);		//����ĳԪ���Ƿ����
	void insertFoot(int);		//β�巨
	void printList();		//��ӡ
	void cha(LinkList L1, LinkList L2);
};


//���캯��
LinkList::LinkList()
{
	head = new LNode;
}

//����������
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
		insertFoot(p->data);	//β�巨

	}
	cout << "�������!" << endl;

}



//�������β�巨
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

//����ĳԪ���Ƿ�����ڵ�ǰ������
bool LinkList::isPresent(int n)
{
	LNode* current;
	current = head->next;
	while (current != NULL) {
		if (current->data == n) 
		{
			return 1;//����
		}
		current = current->next;//ָ����һ��ָ����
	}
	return 0;
}

//�󲢼�
void LinkList::unionList(LinkList L1, LinkList L2)
{
	LNode* p, * q;
	p = L1.head->next;
	while (p != NULL) //��������A������Ԫ�ظ��Ƶ��µĵ�������
	{			
		insertFoot(p->data);	//β�巨
		p = p->next;

	}

	q = L2.head->next;
	while (q != NULL) {
		if (isPresent(q->data) == 0) 
		{
			insertFoot(q->data);		//β�巨

		}
		q = q->next;

	}

}
//��
void LinkList::cha(LinkList L1, LinkList L2)
{

}
//�󽻼�
void LinkList::interSection(LinkList L1, LinkList L2)
{
	LNode* q;
	q = L2.head->next;
	while (q != NULL) {
		if (L1.isPresent(q->data) == 1) //������һ�����ظ���Ԫ��
		{
			insertFoot(q->data);		//β�巨
		}
		q = q->next;

	}

}

//��ӡ������
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
	LinkList LA;		//����һ������LA�ĵ��������
	LinkList LB;		//����һ������LB�ĵ��������
	LinkList LC;		//��Ų���
	LinkList LD;		//��Ž���
	cout << "�����뵥����A�ĳ��ȣ�";
	cin >> l1;
	LA.createList(l1);
	cout << "�����뵥����B�ĳ��ȣ�";
	cin >> l2;
	LB.createList(l2);
	LA.printList();
	LB.printList();
	cout << "����Ϊ��" << endl;
	LC.unionList(LA, LB);
	LC.printList();

	cout << "����Ϊ��" << endl;
	LD.interSection(LA, LB);
	if (LD.head->next) {
		LD.printList();
	}
	else {
		cout << "û�н�����" << endl;
	}

}

