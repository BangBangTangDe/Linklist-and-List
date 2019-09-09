#include<iostream>
typedef int ElemType;
typedef int Status;
using namespace std;

struct LinkNode {
	ElemType num;
	LinkNode*next;
};
//函数实现
//线性表的初始化
void IntiaList(LinkNode* &L) {
	L = new LinkNode;
	L->next = NULL;
}
//链表的创建
void CreatList(LinkNode* &L)
{
	int len; int i = 0;
	cout << "输入链表长度" << endl;
	cin >> len;
	LinkNode *p=NULL; LinkNode *q = L;
	while (i != len)
	{
		p = new LinkNode;
		i++;
		cout << "输入第" << i << "个节点的值";
		cin >> p->num;
		q->next = p;
		q=p;
	}
	q->next = NULL;
	
}
//线性表的销毁
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
//线性表元素清除
void ClearList(LinkNode *& L)
{
	while (L)
	{
		L->num = NULL;
		L = L->next;
	}
}
//判断是否为空
bool ListEmpty(LinkNode * L)
{
	if(L->next ==NULL)
		return true;
	else
		return false;
}
//返回线性表的长度
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
//得到具体位置的元素
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
//返回顺序表L中第1个与element相等的元素
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
//遍历前驱元素
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
//用next_e返回线性表中cur_e的后继
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
//插入元素
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
//删除元素
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
//遍历所有的元素
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
		printf("    请选择你的操作[0~13]:");

		while (op != 0)
		{
			cin >> op;
			switch (op) {
			case 1:
				IntiaList(L);
				printf("线性表创建成功！\n");
				break;
			case 2:
				DestroyList(L);
				cout << "线性表已销毁" << endl;
				printf("\n----DestroyList功能待实现！\n");
				break;
			case 3:
				ClearList(L);
				cout << "清除成功" << endl;
				printf("\n----ClearList功能待实现！\n");
				break;
			case 4:
				if (ListEmpty(L) == 1)
					cout << "线性表是空的" << endl;
				else
					cout << "线性表不空" << endl;
				printf("\n----ListEmpty功能待实现！\n");
				break;
			case 5:
				cout << "线性表的长度是" << ListLength(L) << endl;
				printf("\n----ListLength功能待实现！\n");
				break;
			case 6:
				cout << "输入位置" << endl;
				int temp; int i;
				cin >> i;
				if (GetElem(L, i, temp) == 1)
					cout << "在" << i << "位置的元素是" << temp;
				else
					cout << "错误" << endl;
				printf("\n----GetElem功能待实现！\n");
				break;
			case 7:
				int locate; ElemType e;
				cout << "输入对应元素的数值" << endl;
				cin >> e;
				locate = LocateElem(L, e);
				if (locate == 0)
					cout << "元素不存在" << endl;
				else
					cout << "元素的位置是" << locate;
				printf("\n----LocateElem功能待实现！\n");
				break;
			case 8:
				ElemType a; ElemType cur;
				cout << "输入现在的数值" << endl;
				cin >> cur;
				if (PriorElem(L, cur, a) == 1)
					cout << "前驱是" << a;
				else
					cout << "错误" << endl;
				printf("\n----PriorElem功能待实现！\n");
				break;
			case 9:
				ElemType b; ElemType cur1;
				cout << "输入现在的数值" << endl;
				cin >> cur1;
				if (NextElem(L, cur1, b) == 1)
					cout << "后继=》" << b << endl;
				else
					cout << "error" << endl;
				printf("\n----NextElem功能待实现！\n");
				break;
			case 10:
				ElemType t; int i1;
				cout << "输入你要插入的数值" << endl;
				cin >> t;
				cout << "你要插入的位置" << endl;
				cin >> i1;
				if (ListInsert(L, i1, t) == 1)
					cout << "插入成功" << endl;
				else
					cout << "插入失败" << endl;
				printf("\n----ListInsert功能待实现！\n");
				break;
			case 11:

				ElemType t0; int i0;
				cout << "输入你要删除的位置" << endl;
				cin >> i0;
				if (ListDelete(L, i0, t0) == 1)
				{
					cout << "删除成功" << endl; cout << "删除的元素是" << t0;
				}
				else
					cout << "删除失败" << endl;
				printf("\n----ListDelete功能待实现！\n");
				break;
			case 12:
				if (!ListTrabverse(L)) printf("线性表是空表！\n");
				break;
			case 13:
				CreatList(L);
				cout<<"链表创建结束"<<endl;
				break;
			case 0:
				printf("欢迎下次再使用本系统！\n");
				break;
			}
		}

	}
	return 0;

	return 0;
}