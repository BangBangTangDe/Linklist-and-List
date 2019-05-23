#include<iostream>
typedef int ElemType;
typedef int Status;
using namespace std;

struct LinkNode {
	ElemType num;
	LinkNode*next;
};
//����ʵ��
//���Ա�ĳ�ʼ��
void IntiaList(LinkNode* &L) {
	L = new LinkNode;
	L->next = NULL;
}
//����Ĵ���
void CreatList(LinkNode* &L)
{
	int len; int i = 0;
	cout << "����������" << endl;
	cin >> len;
	LinkNode *p=NULL; LinkNode *q = L;
	while (i != len)
	{
		p = new LinkNode;
		i++;
		cout << "�����" << i << "���ڵ��ֵ";
		cin >> p->num;
		q->next = p;
		q=p;
	}
	q->next = NULL;
	
}
//���Ա������
 void DestroyList(LinkNode *& L)
{
	 LinkNode *p;
	 while (L)
	 {
		 p = L;
		 L = L->next;
		 delete p;
	 }
}
//���Ա�Ԫ�����
void ClearList(LinkNode *& L)
{
	while (L)
	{
		L->num = NULL;
		L = L->next;
	}
}
//�ж��Ƿ�Ϊ��
bool ListEmpty(LinkNode * L)
{
	if(L->next ==NULL)
		return true;
	else
		return false;
}
//�������Ա�ĳ���
Status ListLength(LinkNode * L)
{
	ElemType count = 0;
	while (L)
	{
		count++;
		L = L->next;
	}
	return count-1;
}
//�õ�����λ�õ�Ԫ��
Status GetElem(LinkNode * L, int i, ElemType & e) {
	int j = 0;
	if (i<0 || i>ListLength(L))
		return 0;
	while (j != i)
	{
		L = L->next;
		j++;
	}
	e = L->num;
	return 1;
}
//����˳���L�е�1����element��ȵ�Ԫ��
Status LocateElem(LinkNode * L, ElemType e)
{
	int j = 0;
	while (L)
	{
		j++;
		L = L->next;
		if (L == NULL)
			break;
		if (L->num == e)
			return j;
		
	}
	return 0;
}
//����ǰ��Ԫ��
Status PriorElem(LinkNode *L, ElemType cur, ElemType & pre_e)
{
	LinkNode *p = L;
	if (p->next->num==cur)
		return 0;
	while (p->next->num!=cur)
	{
		p= p->next;
		if (p ->next== NULL)
		{
			return 0;
		}
	}
	pre_e = p->num;
	return 1;
}
//��next_e�������Ա���cur_e�ĺ��
Status NextElem(LinkNode* L, ElemType cur, ElemType & next_e)
{
	while (L&&L->num != cur)
	{
		L = L->next;
	}
	if (L == NULL)
		return 0;
	else if (L->next == NULL)
		return 0;
	else
	{
		next_e = L->next->num;
		return 1;
	}
}
//����Ԫ��
Status ListInsert(LinkNode* & L, int i, ElemType e)
{
	int lenth = ListLength(L); int count = 0;
	LinkNode *p; LinkNode *q;
	if (i == 1)
	{
		p = L->next;
		q = new LinkNode;
		q->num = e;
		L->next = q;
		q->next = p;
		return 1;
	}
	else if (i == lenth + 1)
	{
		p = L;
		while (p)
		{
			if (p->next == NULL)
				break;
			p = p->next;
		}
		q = new LinkNode;
		q->num = e;
		p->next = q;
		q->next = NULL;
		return 1;
	}
	else if (i > 1 && i < lenth+1)
	{
		p = L;
		while (count != i - 1)
		{
			p = p->next;
			count++;
		}
		q = new LinkNode;
		q->num = e;
		q->next = p->next;
		p->next = q;
		return 1;
	}
	else
		return 0;
}
//ɾ��Ԫ��
Status ListDelete(LinkNode* & L, int i, ElemType & e)
{
	int len = ListLength(L); int count = 0;
	LinkNode *p; LinkNode *q;
	if (i<1 || i>len)
		return 0;
	if (i == 1)
	{
		p = L;
		q = L->next;
		e = q->num;
		p->next = q->next;
		delete q;
		return 1;
	}
	else if (i == len)
	{
		p = L;
		while (p)
		{
			if (p->next->next == NULL)
			{
				e = p->next->num;
				q = p->next;
				delete q;
				break;
			}
			p = p->next;
		}
		p->next = NULL;
		return 1;
	}
	else {
		p = L;
		while (count != i-1)
		{
			p = p->next;
			count++;
		}
		q = p->next;
		e = q->num;
		p->next = q->next;
		delete q;
		return 1;
	}

}
//�������е�Ԫ��
Status ListTrabverse(LinkNode * L) {
	printf("\n---------------all elements -----------------------\n");
	for (LinkNode *p = L->next; p; p = p->next)
		cout << p->num << " ";
	cout << endl;
	printf("\n------------------ end ------------------------\n");
	return 1;
}




int main()
{
	LinkNode * L=NULL;
	int op = 1;
	while (op) {
		system("cls");
		printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. IntiaList       7. LocateElem\n");
		printf("    	  2. DestroyList     8. PriorElem\n");
		printf("    	  3. ClearList       9. NextElem \n");
		printf("    	  4. ListEmpty     10. ListInsert\n");
		printf("    	  5. ListLength     11. ListDelete\n");
		printf("    	  6. GetElem       12. ListTrabverse\n");
		printf("    	  0. Exit        13.CreatList\n");
		printf("-------------------------------------------------\n");
		printf("    ��ѡ����Ĳ���[0~13]:");

		while (op != 0)
		{
			cin >> op;
			switch (op) {
			case 1:
				IntiaList(L);
				printf("���Ա����ɹ���\n");
				break;
			case 2:
				DestroyList(L);
				cout << "���Ա�������" << endl;
				printf("\n----DestroyList���ܴ�ʵ�֣�\n");
				break;
			case 3:
				ClearList(L);
				cout << "����ɹ�" << endl;
				printf("\n----ClearList���ܴ�ʵ�֣�\n");
				break;
			case 4:
				if (ListEmpty(L) == 1)
					cout << "���Ա��ǿյ�" << endl;
				else
					cout << "���Ա���" << endl;
				printf("\n----ListEmpty���ܴ�ʵ�֣�\n");
				break;
			case 5:
				cout << "���Ա�ĳ�����" << ListLength(L) << endl;
				printf("\n----ListLength���ܴ�ʵ�֣�\n");
				break;
			case 6:
				cout << "����λ��" << endl;
				int temp; int i;
				cin >> i;
				if (GetElem(L, i, temp) == 1)
					cout << "��" << i << "λ�õ�Ԫ����" << temp;
				else
					cout << "����" << endl;
				printf("\n----GetElem���ܴ�ʵ�֣�\n");
				break;
			case 7:
				int locate; ElemType e;
				cout << "�����ӦԪ�ص���ֵ" << endl;
				cin >> e;
				locate = LocateElem(L, e);
				if (locate == 0)
					cout << "Ԫ�ز�����" << endl;
				else
					cout << "Ԫ�ص�λ����" << locate;
				printf("\n----LocateElem���ܴ�ʵ�֣�\n");
				break;
			case 8:
				ElemType a; ElemType cur;
				cout << "�������ڵ���ֵ" << endl;
				cin >> cur;
				if (PriorElem(L, cur, a) == 1)
					cout << "ǰ����" << a;
				else
					cout << "����" << endl;
				printf("\n----PriorElem���ܴ�ʵ�֣�\n");
				break;
			case 9:
				ElemType b; ElemType cur1;
				cout << "�������ڵ���ֵ" << endl;
				cin >> cur1;
				if (NextElem(L, cur1, b) == 1)
					cout << "���=��" << b << endl;
				else
					cout << "error" << endl;
				printf("\n----NextElem���ܴ�ʵ�֣�\n");
				break;
			case 10:
				ElemType t; int i1;
				cout << "������Ҫ�������ֵ" << endl;
				cin >> t;
				cout << "��Ҫ�����λ��" << endl;
				cin >> i1;
				if (ListInsert(L, i1, t) == 1)
					cout << "����ɹ�" << endl;
				else
					cout << "����ʧ��" << endl;
				printf("\n----ListInsert���ܴ�ʵ�֣�\n");
				break;
			case 11:

				ElemType t0; int i0;
				cout << "������Ҫɾ����λ��" << endl;
				cin >> i0;
				if (ListDelete(L, i0, t0) == 1)
				{
					cout << "ɾ���ɹ�" << endl; cout << "ɾ����Ԫ����" << t0;
				}
				else
					cout << "ɾ��ʧ��" << endl;
				printf("\n----ListDelete���ܴ�ʵ�֣�\n");
				break;
			case 12:
				if (!ListTrabverse(L)) printf("���Ա��ǿձ�\n");
				break;
			case 13:
				CreatList(L);
				cout<<"����������"<<endl;
				break;
			case 0:
				printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
				break;
			}
		}

	}
	return 0;

	return 0;
}