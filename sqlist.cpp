#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//����״̬
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 10000

typedef int Status;//Status��ʾ״̬
//typedef char ElemType;

//�����������Ա��˴�Ϊͼ���
typedef struct {
	char no[20];    //���
	char name[50];  //����
	float price;    //�۸�
}Book;
//�������Ա�
typedef struct {
	Book *elem;
	int length;//���Ա��ʵ�ʳ��ȣ���ͼ��ľ��������
}SqList;
//�ж����ṹ���Ƿ���ͬ
int equal(Book B1,Book B2)
{
	if((strcmp(B1.no,B2.no) == 0)&&(strcmp(B1.name,B2.name) == 0)&&(B1.price == B2.price))
		return TRUE;
	return FALSE;
}
//��ʼ�����Ա�
Status InitList(SqList *L)
{
	L->elem = (Book*)malloc(sizeof(Book)*MAXSIZE);
	if(!(*L).elem)
		exit(OVERFLOW);
	L->length = 0;
	return OK;
}
//�������Ա�
void DestroyList(SqList *L)
{
	if((*L).elem)
		free(L);
}
//������Ա�
void ClearList(SqList *L)
{
	(*L).length = 0;
}
//�����Ա�L�ĳ���
int GetLength(SqList *L)
{
	return (*L).length;
}
//�ж����Ա��Ƿ�Ϊ��
int IsEmpty(SqList *L)
{
	if((*L).length = 0)
		return 1;
	else
		return 0;
}
//����λ��i��ȡ��Ӧλ������Ԫ�ص�����
int GetElem(SqList L,int i,Book *p)
{
	if(i<1 || i>L.length)
		return ERROR;
	*p = L.elem[i - 1];
	return OK;
}
//����ֵ����
int LocateElem(SqList L,Book e)
{
	for(int i=0; i<L.length; i++) {
		if(equal(L.elem[i],e))
			return i + 1;
	}
	return 0;
}
//����
Status ListInsert(SqList &L,int i,Book e)
{
	if((i<1)||(i>L.length+1))
		return ERROR;
	if(L.length == MAXSIZE)
		return ERROR;
	for(int j=L.length-1;j>=i-1;j--)
		L.elem[j+1] = L.elem[j];
	L.elem[i-1] = e;
	++L.length;
	return OK;
}
//ɾ��
Status ListDelete(SqList &L,int i)
{
	if((i<1)||(i>L.length))
		return ERROR;
	for(int j=i;j<=L.length-1;j++)
		L.elem[j-1] = L.elem[j];
	--L.length;
	return OK;
}
//��ʾ���Ա�
void show(SqList L)
{
	for(int i=0;i<L.length;i++){
		printf("��%d������:%s\t%s\t%.1f\n",i+1,L.elem[i].no,L.elem[i].name,L.elem[i].price);
	}
}
int main(void)
{
	Book book1 = {"10001","���μ�",98.5};
	Book book2 = {"10002","��¥��",150};
	Book book3 = {"10003","�����й�־",55};
	Book book4 = {"10004","ˮ䰴�",90};
	SqList L;
	InitList(&L);
	ListInsert(L,1,book1);
	ListInsert(L,2,book2);
	ListInsert(L,3,book3);
	printf("%d\n",GetLength(&L));
	printf("%d\n",LocateElem(L,book4));
	show(L);
	getchar();
	return 0;
}