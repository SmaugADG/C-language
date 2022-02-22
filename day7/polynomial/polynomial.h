#ifndef polynomial_h__
#define polynomial_h__
#include<stdio.h>
#include<stdlib.h>
typedef struct poly_node_st {
	int coef;
	int exp;
	struct poly_node_st* next;

}poly_st;
//创建链表，使用头节点
poly_st* poly_create(int arr[][2],int i);
//打印链表
void poly_show(poly_st*);
//合并
int poly_union(poly_st*,poly_st*);
//销毁
void pol_destory(poly_st*);
#endif // !polynomial_h__
