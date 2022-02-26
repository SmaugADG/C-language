#include<stdio.h>
#include<stdlib.h>
#include"sqstack.h"
//计算功能
static void compute(sqstack* snum,datatype* op) {
	datatype n1, n2,ret;
	st_pop(snum,&n2);//操作数
	st_pop(snum,&n1);//被操作数
	switch (*op) 
	{
	case '+':
		ret = n1 + n2;
		break;
	case '-':
		ret = n1 - n2;
		break;
	case '*':
		ret = n1 * n2;
		break;
	case '/':
		ret = n1 / n2;
		break;
	case '%':
		ret = n1 % n2;
		break;
	default:
		exit(1);
		break;
	}
	st_push(snum,&ret);
}

static void deal_brcket(sqstack* snum, sqstack* sop) {
	datatype old_op;
	
	st_top(sop,&old_op);
	while(old_op!='(') {
		st_pop(sop,&old_op);
		compute(snum,&old_op);
		st_top(sop,&old_op);
	}
	st_pop(sop, &old_op);
}
static int get_pri(int op) {
	switch (op)
	{
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		break;
	}
}
static void deal_op(sqstack* snum,sqstack* sop,int op) {
	datatype old_op;
	if (st_isempty(sop)||op=='(') {
		st_push(sop,&op);
		return;
	}
	st_top(sop,&old_op);
	if (get_pri(op)>get_pri(old_op)) {
		st_push(sop,&op);
		return;
	}
	while (get_pri(op)<=get_pri(old_op)) {
		st_pop(sop,&old_op);
		compute(snum,&old_op);
		if (st_isempty(sop)) {
			break;
		}
		st_top(sop,&old_op);
	}
	st_top(sop,op);
}

int main() {
	datatype old_op;
	int i=0,val=0;
	int flag = 0;
	sqstack* snum, * sop;
	char str[] = "(11+3)*2-5";
	snum = st_create();
	if (snum==NULL) {
		exit(-1);
	}
	sop = st_create();
	if (sop==NULL) {
		exit(-1);
	}

	while (str[i]!='\0') {
		if (str[i]>='0'&&str[i]<='9') {
			val = val * 10 + (str[i] - '0');//?
			flag = 1;
		}
		else {//操作符
			if (flag) {
				st_push(snum,&val);
				flag = 0;
				val = 0;
			}

			if (str[i]== ')' ) {
				deal_brcket(snum,sop);
			}
			else {//其他操作符
				deal_op(snum,sop,str[i]);
			}
		}
		i++;
	}
	if (flag) {
		st_push(snum,&val);
		while (!st_isempty(sop)) {
			st_pop(sop,&old_op);
			compute(snum,old_op);
			//未处理完。。。
		}
	}
	printf("%d",val);
	st_destory(snum);
	st_destory(sop);

	exit(0);
}