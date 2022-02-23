#include"joseph_ring.h"
//创建
jospher_st* josp_creat(int n) {
	int i=1;
	jospher_st* jp,*newnode,*tmp;
	jp = malloc(sizeof(*jp));
	if (jp == NULL) {
		return NULL;
	}
	jp->data = i;
	jp->next = jp;
	i++;
	tmp = jp;
	for (; i <= n;i++) {
		newnode = malloc(sizeof(*newnode));
		if (newnode==NULL) {
			return NULL;
		}
		newnode->data = i;
		newnode->next = jp;
		tmp->next = newnode;
		tmp = newnode;
	}
	tmp = NULL;
	newnode = NULL;
	return jp;
}
//显示链表
void josp_show(jospher_st* jsp) {
	if (!jsp) {
		return;
	}
	jospher_st* tmp = jsp->next;
	printf("%d  ",jsp->data);
	while (tmp!=jsp) {
		printf("%d  ",tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
	tmp = NULL;
	return;
}
//按规则删除
int josp_delete(jospher_st** jsp, int n) {
	if (n>JOP_NUM) {
		return -1;
	}
	jospher_st* tmp,*cur;
	int i;
	for (cur = *jsp; cur!=cur->next; cur = cur->next) {
		for (i = 1; i < n-1;i++) {
			cur = cur->next;
		}
		tmp = cur->next;
		cur->next = tmp->next;
		printf("move->:%d\n",tmp->data);
		free(tmp);
		tmp = NULL;
	}
	*jsp = cur;
	cur = NULL;
	return 0;
}

//销毁链表
void josp_destory(jospher_st* jsp) {
	if (!jsp) {
		return;
	}
	jospher_st* tmp = jsp->next;
	while (jsp) {
		jsp->next = tmp->next;
		free(tmp);
		tmp = jsp->next;
	}
	tmp = NULL;
	return;
}