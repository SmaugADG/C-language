#ifndef queue_h__
#define queue_h__
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 6
typedef int datatype;
typedef struct node_st{
	datatype data[MAXSIZE];
	int head, tail;
}Queue;

//创建
Queue* queue_create();
//判空
int queue_isempty(Queue*);
//入队
int queue_enqueue(Queue*,datatype*);
//出队
int queue_dequeue(Queue*,datatype*);
//遍历
void queue_travel(Queue*);
//清空
void queue_clear(Queue*);
//销毁
void queue_destory(Queue*);

#endif // !queue_h__
