#ifndef sqstack_h__
#define sqstack_h__
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 5

typedef int datatype;

typedef struct node_st{
	datatype data[MAXSIZE];
	int top;
}sqstack;
//创建
sqstack* st_create(void);
//判空
int st_isempty(sqstack*);
//入栈
int st_push(sqstack*,datatype*);
//出栈
int st_pop(sqstack*,datatype*);
//取栈顶
int st_top(sqstack*,datatype*);
//遍历
void st_travel(sqstack*);
//销毁
void st_destory(sqstack*);

#endif // !sqstack_h__
