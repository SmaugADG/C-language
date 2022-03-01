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

typedef struct {
	int size;
	struct dllist_node_st head;
}LLIST;

//创建链表
LLIST *dllist_create(int initsize);
//插入
int dllist_insert(LLIST*,const void* data,int mod);
//查找(按条件)
void *dllist_find(LLIST*,const void *key, dllinst_cmp*);
//删除
int dllist_delete(LLIST*,const void *key,dllinst_cmp*);
//获取元素
int dllist_fetch(LLIST*,const void* key,dllinst_cmp*,void* data);
//遍历
void dllist_travel(LLIST*,dllist_op*);
//销毁
void dllist_destory(LLIST*);

#endif // !dllist_h__
