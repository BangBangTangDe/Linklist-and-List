#include<iostream>
#pragma warning (disable :4996)
using namespace std;
struct LinkNode {
	int val;
	LinkNode *next;
	LinkNode(int x) :val(x), next(NULL) {};
	LinkNode() :val(0), next(NULL) {};
};
LinkNode * creat()
{
	LinkNode *head = new LinkNode;
	LinkNode *p,*q = NULL;
	q = head;
	int x;
	while (1)
	{
		scanf("%d",&x);
		p = new LinkNode(x);
		q->next = p;
		q = p;
		char ch = getchar();
		if (ch == '\n')break;
		
	}
	return head;
}
void show(LinkNode * head)
{
	cout << "print" << endl;
	for (LinkNode *t = head->next; t != NULL; t = t->next)
		cout << t->val << " ";
}
LinkNode * Link_merge( LinkNode *p1,LinkNode *q1)
{

	LinkNode *head = new LinkNode ;
	LinkNode *t1 = NULL;
	LinkNode *t2 = NULL;
	LinkNode *p = p1->next;
	LinkNode *q = q1->next;
	t1 = head;
	while (p && q)
	{
		if (p->val <= q->val)
		{
			t2 = new LinkNode(p->val);
			t1->next = t2;
			t1 = t2;
			p = p->next;
		}
		else
		{
			t2 = new LinkNode(q->val);
			t1->next = t2;
			t1 = t2;
			q = q->next;
		} 
	}

	if (p)
	{
		t1->next = p;
	}
	if (q)
	{
		t1->next = q;
	}
	return head;
}
LinkNode * creat_pre()
{
	LinkNode *head=NULL;
	LinkNode *p = NULL;
	int x;

	if (head == NULL)
	{
		head = new LinkNode;
	}
	while(1)
	{
		cin >> x;
		
		p = new LinkNode(x);
		p->next = head->next;
		head->next = p;
		char ch = getchar();
		if (ch == '\n')break;
	}

	return head;
}
int main()
{

	LinkNode *pre = creat_pre();

	show(pre);
	cout << endl;
	LinkNode *p = creat();
	LinkNode *q = creat();
	show(p);
	show(q);
	LinkNode *ans = Link_merge(p, q);
	show(ans);
		




	system("pause");
	return 0;
}