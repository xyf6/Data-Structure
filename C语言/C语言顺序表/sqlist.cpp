#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//定义状态
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 10000

typedef int Status;//Status表示状态
//typedef char ElemType;

//定义具体的线性表，此处为图书表。
typedef struct {
	char no[20];    //书号
	char name[50];  //书名
	float price;    //价格
}Book;
//定义线性表
typedef struct {
	Book *elem;
	int length;//线性表的实际长度，即图书的具体个数。
}SqList;
//判断两结构体是否相同
int equal(Book B1,Book B2)
{
	if((strcmp(B1.no,B2.no) == 0)&&(strcmp(B1.name,B2.name) == 0)&&(B1.price == B2.price))
		return TRUE;
	return FALSE;
}
//初始化线性表
Status InitList(SqList *L)
{
	L->elem = (Book*)malloc(sizeof(Book)*MAXSIZE);
	if(!(*L).elem)
		exit(OVERFLOW);
	L->length = 0;
	return OK;
}
//销毁线性表
void DestroyList(SqList *L)
{
	if((*L).elem)
		free(L);
}
//清空线性表
void ClearList(SqList *L)
{
	(*L).length = 0;
}
//求线性表L的长度
int GetLength(SqList *L)
{
	return (*L).length;
}
//判断线性表是否为空
int IsEmpty(SqList *L)
{
	if((*L).length = 0)
		return 1;
	else
		return 0;
}
//根据位置i获取相应位置数据元素的内容
int GetElem(SqList L,int i,Book *p)
{
	if(i<1 || i>L.length)
		return ERROR;
	*p = L.elem[i - 1];
	return OK;
}
//根据值查找
int LocateElem(SqList L,Book e)
{
	for(int i=0; i<L.length; i++) {
		if(equal(L.elem[i],e))
			return i + 1;
	}
	return 0;
}
//插入
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
//删除
Status ListDelete(SqList &L,int i)
{
	if((i<1)||(i>L.length))
		return ERROR;
	for(int j=i;j<=L.length-1;j++)
		L.elem[j-1] = L.elem[j];
	--L.length;
	return OK;
}
//显示线性表
void show(SqList L)
{
	for(int i=0;i<L.length;i++){
		printf("第%d本书是:%s\t%s\t%.1f\n",i+1,L.elem[i].no,L.elem[i].name,L.elem[i].price);
	}
}
int main(void)
{
	Book book1 = {"10001","西游记",98.5};
	Book book2 = {"10002","红楼梦",150};
	Book book3 = {"10003","东周列国志",55};
	Book book4 = {"10004","水浒传",90};
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
