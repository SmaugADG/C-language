#include"sqlist.h"
//创建
sqlist* sqlist_create() {
	sqlist* list;
	list = malloc(sizeof(*list));
	if (list==NULL) {
		return NULL;
	}
	list->last = -1;
	return list;
}
void sqlist_create1(sqlist** sp) {
	*sp = malloc(sizeof(**sp));
	if (*sp==NULL) {
		return;
	}
	(*sp)->last = -1;
	return;
}
//销毁
int sqlist_destory(sqlist* sp) {
	free(sp);
	return 0;
}
//插入
int sqlist_insert(sqlist* sp, int i, datatype* dp) {
	int j;
	if (sp->last==DATASIZE-1) {
		//fprintf(stderr,"sqlist is fall\n");
		return -1;
	}
	if (i<0||i>sp->last + 1) {
		//fprintf(stderr,"i is illegal\n");
		return -2;
	}
	for (j = sp->last; i <= j;j--) {
		sp->data[j + 1] = sp->data[j];
	}
	sp->data[i] = *dp;
	sp->last++;
	//fprintf(stdout,"insert success!\n");
	return 0;
}
//循环插入
int sqlist_cycinsert(sqlist* sp, int i, int size,datatype* dp) {
	int ret;
	for (i = 0; i < size; i++) {
		ret = sqlist_insert(sp, 0, &dp[i]);
		if (ret == -1) {
			fprintf(stderr, "sqlist is full\n");
		}
		else if (ret == -2) {
			fprintf(stderr, "i is illegal\n");
		}
	}
	return 0;
}
//删除(按位置删除)
int sqlist_delete(sqlist* sp, const int i) {
	int j;
	if (i<0||i>sp->last) {
		return -1;
	}
	for (j = i; j <= sp->last;j++) {
		sp->data[j] = sp->data[j+1];
	}
	sp->last--;

	return 0;
}
//查找（按值查找）
int sqlist_find(sqlist* sp, datatype* dp) {
	int j;
	if (sqlist_isempty(sp)==-1) {
		return -1;
	}
	for (j = 0; j <= sp->last;j++) {
		if (*dp==sp->data[j]) {
			return j;
		}
	}
}
//判空
int sqlist_isempty(sqlist* sp) {
	if (sp->last==-1) {
		return 0;
	}
	return -1;
}
//置空
int sqlist_setempty(sqlist* sp) {
	sp->last = -1;
	return 0;
}
//获取元素个数
int sqlist_getnum(sqlist* sp) {
	return sp->last+1;
}
//合并
int sqlist_union(sqlist* sp1, sqlist* sp2) {
	int j;
	if (sp1->last==-1&&sp2->last==-1) {
		return -1;
	}
	for (j = 0; j <= sp2->last;j++) {
		if (sqlist_find(sp1,sp2->data[j])==-1) {
			sqlist_insert(sp1,0,&(sp2->data[j]));
		}
	}
	return 0;
}
//遍历
void sqlist_display(sqlist* sp) {
	int j;
	if (sp->last<0) {
		fprintf(stderr,"sqlist is null!\n");
		return;
	}
	for (j = 0; j <= sp->last;j++) {
		printf("%d  ",sp->data[j]);
	}
	printf("\n");
} 