#ifndef joseph_ring_h__
#define joseph_ring_h__
#include<stdio.h>
#include<stdlib.h>

#define JOP_NUM 8

typedef struct josephring {
	int data;
	struct josephring* next;
}jospher_st;
//创建
jospher_st* josp_creat(int);
//显示链表
void josp_show(jospher_st*);
//按规则删除
int josp_delete(jospher_st**,int);
//销毁链表
void josp_destory(jospher_st*);

#endif // !joseph_ring_h__
