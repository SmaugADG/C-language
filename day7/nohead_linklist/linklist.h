#ifndef linklist_h__
#define linklist_h__
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define NAMESIZE 32


typedef struct score_st {
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
}score;
typedef struct node_st {
	struct score_st data;
	struct node_st* next;
}head_linklist;

typedef int datatype;
//插入
int list_insert(head_linklist**,score*);
//循环插入
int list_cycinsert(head_linklist*);
//打印链表
void list_show(head_linklist*);
//删除
int list_delete(head_linklist **);
//查找(id)
score* list_find(head_linklist*,int);
//销毁
void list_destory(head_linklist*);


#endif // !linklist_h__
