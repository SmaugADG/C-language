#ifndef lnstack_h__
#define lnstack_h__
#include<stdio.h>
#include<stdlib.h>
#include"dllist.h"
typedef LLIST STACK;
STACK* stack_create(int);//创建
int stack_push(STACK*,void* data);//入栈
int stack_pop(STACK*,void* data);//出栈
void stack_destory(STACK*);//销毁
#endif // !lnstack_h__

