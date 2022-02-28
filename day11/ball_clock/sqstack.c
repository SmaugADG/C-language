#include"sqstack.h"


//创建
sqstack* st_create(void) {
	sqstack* sp;
	sp = malloc(sizeof(*sp));
	if (sp==NULL) {
		return NULL;
	}
	sp->top = -1;
	return sp;
}
//判空
int st_isempty(sqstack* sp) { 
	return (sp->top==-1);
}
//入栈
int st_push(sqstack* sp, type* dp) {
	if (sp->top==SIZE) {
		return -1;
	}
	sp->top++;
	sp->data[sp->top] = *dp;
//	sp->data[++sp->top] = *dp;
	return 0;
}
//出栈
int st_pop(sqstack* sp, type* dp) {
	if (st_isempty(sp)) {
		return -1;
	}
	*dp = sp->data[sp->top];
	sp->top--;
	return 0;
}
//取栈顶
int st_top(sqstack* sp, type* dp) { 
	if(st_isempty(sp)) {
		return -1;
	}
	*dp = sp->data[sp->top];

	return sp;
}
//遍历
void st_travel(sqstack* sp) {
	if (st_isempty(sp)) {
		return;
	}
	int i;
	for (i = 0; i <= sp->top; i++) {
		printf("%d  ", sp->data[i]);
	}
	printf("\n");
}
//销毁
void st_destory(sqstack* sp) {
	free(sp);
}
