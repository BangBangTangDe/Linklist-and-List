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
//�ṹ�嶨��
typedef struct {  
	ElemType * elem;
	int length;
	int listsize;
}SqList;

//����ʵ��
//���Ա�ĳ�ʼ��
status IntiaList(SqList & L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}
//���Ա������
status DestroyList(SqList & L)
{
	if (!L.elem)
		return ERROR;
	else
		free(L.elem);
	return OK;
}
//���Ա�Ԫ�����
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
//�ж��Ƿ�Ϊ��
status ListEmpty(SqList L) 
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}
//�������Ա�ĳ���
int ListLength(SqList L)
{
	return L.length;
}
//�õ�����λ�õ�Ԫ��
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
//����˳���L�е�1����element��ȵ�Ԫ��
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
//����ǰ��Ԫ��
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
//��next_e�������Ա���cur_e�ĺ��
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
//����Ԫ��
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
//ɾ��Ԫ��
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
//�������е�Ԫ��
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
		printf("    ��ѡ����Ĳ���[0~12]:");

		while (op != 0)
		{
			cin >> op;
			switch (op) {
			case 1:
				if (IntiaList(L) == OK) printf("���Ա����ɹ���\n");
				else printf("���Ա���ʧ�ܣ�\n");
				break;
			case 2:
				if (DestroyList(L) == 1)
					cout << "���Ա�������" << endl;
				else
					cout << "���Ա�����ٳ���" << endl;
				printf("\n----DestroyList���ܴ�ʵ�֣�\n");
				break;
			case 3:
				if (ClearList(L) == 1)
					cout << "����ɹ�" << endl;
				else
					cout << "���ʧ��" << endl;
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
			case 0:
				printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
				break;
			}
		}

	}
	return 0;
}