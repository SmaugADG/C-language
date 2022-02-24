#include"dllist.h"

#define NAMESIZE 32

typedef struct score_st {
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
}score_st;
//实现回调函数
//打印输出
static void print_s(const void* recode) {
	const struct score_st * r = recode;
	printf("%d %s %d %d\n",r->id,r->name,r->math,r->chinese);
}
//按ID比较
static int id_cmp(const void* key, const void* recode) {
	const int* k = key;
	const struct score_st* r = recode;
	return(*k - r->id);
}

int main() {
	int i,ret;
	LLIST* handler;
	score_st tmp ;

	handler = dllist_create(sizeof(score_st));
	if (!handler) {
		exit(1);
	}
	for (i = 0; i < 7;i++) {
		tmp.id = i;
		snprintf(tmp.name,NAMESIZE,"stu%d",i);
		tmp.math = rand() % 100;
		tmp.chinese = rand() % 100;

		ret=dllist_insert(handler,&tmp,LLIST_FORWARD);
		if (ret) {
			exit(1);
		}
	}
	dllist_travel(handler,print_s);
	printf("--------------------------\n");
	//查找
	scanf("%d",&i);
	score_st* data;
	data = dllist_find(handler,&i,id_cmp);
	if (!data) {
		printf("no such member!\n");
	}
	print_s(data);
	//data = NULL;
	printf("--------------------------\n");
	//删除
	ret = dllist_delete(handler,&i,id_cmp);
	if (ret==0) {
		printf("delete success\n");
	}
	dllist_travel(handler, print_s);
	printf("---------------------------\n");
	//获取元素
	scanf("%d",&i);
	ret = dllist_fetch(handler,&i,id_cmp,data);
	if (ret==0) {
		print_s(data);
	}
	else {
		printf("fetch fail\n");
	}
	dllist_destory(handler);
	exit(0);
}