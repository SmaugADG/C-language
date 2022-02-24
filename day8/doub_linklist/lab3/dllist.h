#ifndef dllist_h__
#define dllist_h__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LLIST_FORWARD 1 //头插法
#define LLIST_BACKWORD 2 //尾插法

typedef void dllist_op(const void *);//回调函数
typedef int  dllinst_cmp(const void *,const void *);//回调函数

typedef struct dllist_node_st {
	struct dllist_node_st* prev;
	struct dllist_node_st* next;
	char data[1];//C99标准可以为0，之前的版本不能为0
}list_node;

typedef struct linklist_st{
	int size;
	struct dllist_node_st head;
	int (*insert)(struct linklist_st*, const void* data, int mod);//插入
	void* (*find)(struct linklist_st*, const void* key, dllinst_cmp*);//查找
	int (*delete)(struct linklist_st*, const void* key, dllinst_cmp*);//删除
	int (*fetch)(struct linklist_st*, const void* key, dllinst_cmp*, void* data);//获取元素
	void (*travel)(struct linklist_st*, dllist_op*);//遍历
	void (*destory)(struct linklist_st*);//销毁
}LLIST;

//创建链表
LLIST *dllist_create(int initsize);
#endif // !dllist_h__
