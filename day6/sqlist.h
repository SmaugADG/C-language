#ifndef sqlist_h__
#define sqlist_h__
#include<stdio.h>
#include<stdlib.h>

#define DATASIZE 1024

typedef int datatype;

typedef struct node_st{
	datatype data[DATASIZE];
	int last;
}sqlist;

//创建
sqlist *sqlist_create();
void sqlist_create1(sqlist **);
//销毁
int sqlist_destory(sqlist*);
//插入
int sqlist_insert(sqlist* ,int i,datatype*);
//循环插入
int sqlist_cycinsert(sqlist*,int i, int size,datatype*);
//删除(按位置)
int sqlist_delete(sqlist* ,const int i);
//查找（按值查找）
int sqlist_find(sqlist*,datatype*);
//判空
int sqlist_isempty(sqlist*);
//置空
int sqlist_setempty(sqlist*);
//获取元素个数
int sqlist_getnum(sqlist*);
//合并
int sqlist_union(sqlist*,sqlist*);
//遍历
void sqlist_display(sqlist*);

#endif
