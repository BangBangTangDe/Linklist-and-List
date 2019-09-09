#include<iostream>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
typedef int status;
typedef int ElemType;
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
using namespace std;
//结构体定义
typedef struct {  
	ElemType * elem;
	int length;
	int listsize;
}SqList;

//函数实现
//线性表的初始化
status IntiaList(SqList & L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}
//线性表的销毁
status DestroyList(SqList & L)
{
	if (!L.elem)
		return ERROR;
	else
		free(L.elem);
	return OK;
}
//线性表元素清除
status ClearList(SqList &L)
{
	if (!L.elem)
		exit(ERROR);
	ElemType *p = L.elem;
	for (int i = 0; i < L.length; i++)
	{
		*L.elem = NULL;
		L.elem++;
	}
	L.elem = p;
	return OK;
}
//判断是否为空
status ListEmpty(SqList L) 
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}
//返回线性表的长度
int ListLength(SqList L)
{
	return L.length;
}
//得到具体位置的元素
status GetElem(SqList L, int i, ElemType & e) {
	ElemType *p = L.elem;
	if (i > L.length || i < 1)
		return OVERFLOW;
	for (int j = 0; j < i-1; j++)
	{
		L.elem++;
	}
	e = *L.elem;
	L.elem = p;
	return OK;
}
//返回顺序表L中第1个与element相等的元素
status LocateElem(SqList L, ElemType e)
{
	ElemType *p = L.elem;
	for (int i = 1; i <= L.length; i++)
	{
		if (*L.elem == e)
		{
			L.elem = p; return i;
		}
		else
			L.elem++;
	}
	return 0;
}
//遍历前驱元素
status PriorElem(SqList L, ElemType cur, ElemType & pre_e)
{
	
	ElemType *p = L.elem;
	int back = LocateElem(L, cur);
	if (back <= 1 || back > L.length)
		return ERROR;
	for (int i = 1; i <= back; i++)
	{
		if (i == back - 1)
		{
			pre_e = *L.elem;
			L.elem = p;
			return OK;
		}
		else
			L.elem++;
	}

}
//用next_e返回线性表中cur_e的后继
status NextElem(SqList L, ElemType cur, ElemType & next_e) 
{
	ElemType*p = L.elem;
	int temp = LocateElem(L, cur);
	if (temp < 1 || temp >= L.length)
		return ERROR;
	for (int i = 1; i <= temp+1; i++)
	{
		if (i == temp + 1)
		{
			next_e = *L.elem;
			L.elem = p;
			return OK;
		}
		else
			L.elem++;
	}
}
//插入元素
status ListInsert(SqList & L, int i, ElemType e)
{

	int *q = &(L.elem[i - 1]);
	 ElemType *newbase, *p;
	if (i<1 || i>(L.length + 1))
	        return ERROR;
	 if (L.length >= L.listsize)
		   {
		        newbase = (ElemType*)realloc(L.elem, L.listsize + LISTINCREMENT * sizeof(ElemType));
		         if (newbase == NULL)
		           exit(OVERFLOW);
		        L.elem = newbase;
		       L.listsize += LISTINCREMENT;
		}
	     for (p = &(L.elem[L.length - 1]); p >= q; --p)
		 * (p + 1) = *p;
	 * q = e;
	     ++L.length;
	     return OK;

}
//删除元素
status ListDelete(SqList & L, int i, ElemType & e) 
{
	 if (i<1 || (i>L.length))
		return ERROR;
	 ElemType *p, *q;
	 p = &(L.elem[i - 1]);
     e = *p;
	 q = L.elem + L.length - 1;
	 for (p = p + 1; p <= q; ++p)
		 * (p - 1) = *p;
	    --L.length;
	     return OK;

}
//遍历所有的元素
status ListTrabverse(SqList L) {
	int i;
	printf("\n-----------all elements -----------------------\n");
	for (i = 0; i<L.length; i++) printf("%d ", L.elem[i]);
	printf("\n------------------ end ------------------------\n");
	return L.length;
}


int main()
{
	SqList L;
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
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~12]:");

		while (op != 0)
		{
			cin >> op;
			switch (op) {
			case 1:
				if (IntiaList(L) == OK) printf("线性表创建成功！\n");
				else printf("线性表创建失败！\n");
				break;
			case 2:
				if (DestroyList(L) == 1)
					cout << "线性表已销毁" << endl;
				else
					cout << "线性表的销毁出错" << endl;
				printf("\n----DestroyList功能待实现！\n");
				break;
			case 3:
				if (ClearList(L) == 1)
					cout << "清除成功" << endl;
				else
					cout << "清除失败" << endl;
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
			case 0:
				printf("欢迎下次再使用本系统！\n");
				break;
			}
		}

	}
	return 0;
}