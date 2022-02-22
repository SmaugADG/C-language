#ifndef linklist_h__
#define linklist_h__
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;

typedef struct node_st{
	datatype data;
	struct node_st* next;

}linklist;
//创建列表
linklist* list_create();
//按位置插入
int list_insert_at(linklist*,int i,datatype*);
//循环插入
int list_cycinsert(linklist*,int i,int size,datatype*);
//按序插入
int list_order_insert(linklist*,datatype*);
//按位置删除
int list_delete_at(linklist*,int i,datatype*);
//清空链表
int list_delete(linklist*,datatype*);
//打印链表
void list_display(linklist*);
//销毁链表
void list_destory(linklist*);
//判空
int list_isempty(linklist*);



#endif // !_linklist_h__
