#include"linklist.h"
//插入(头插法)
int list_insert(head_linklist** hlp, score* sp) {
	head_linklist* node;
	node = malloc(sizeof(*node));
	if (node==NULL) {
		return -1;
	}
	node->data = *sp;
	node->next = *hlp;
	*hlp = node;

	return 0;
}
//循环插入
int list_cycinsert(head_linklist** hlp) {
	int i,ret;
	score sp;
	for (i = 0; i < 5;i++) {
		sp.id = i;
		snprintf(sp.name,NAMESIZE,"std%d",i);
		sp.math = rand() % 100;
		sp.chinese = rand() % 100;

		ret=list_insert(hlp,&sp);
	}
	return ret;
}
//打印链表
void list_show(head_linklist* hlp) {
	head_linklist* node = hlp;
	while (node) {
		printf("id=%d\tname=%s\tmath=%d\tchinese=%d\n",
			node->data.id,node->data.name,node->data.math,node->data.chinese);
		node = node->next;
	}
}
//删除
int list_delete(head_linklist** hlp) {
	head_linklist* node ;
	if (hlp == NULL) {
		return -1;
	}
	node = *hlp;
	*hlp = (*hlp)->next;
	free(node);
	return 0;
}

//查找(id)
score* list_find(head_linklist* hlp,int id) {
	head_linklist* node = hlp;
	score* score = NULL;
	while (node) {
		if (node->data.id==id) {
			score = &(node->data);
			return score;
		}
		else {
			node = node->next;
			return NULL;
		}
	}
	

}
//销毁
void list_destory(head_linklist* hlp) {
	head_linklist* node = hlp;
	for (; node;node=hlp->next) {
		free(node);
	}
	return;
}