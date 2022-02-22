#include"linklist.h"
//创建列表
linklist* list_create() {
	linklist* lp;
	lp = malloc(sizeof(*lp));
	if(lp==NULL){
		return NULL;
	}
	lp->next = NULL;
	return lp;
}
//按位置插入
int list_insert_at(linklist* lp, int i, datatype* dp) {
	int j=0;
	linklist* node = lp,*newnode=NULL;
	if(i<0){
		return -1;
	}
	while (j<i&&node->next!=NULL) {
		node = node->next;
		j++;
	}
	if (node) {
		newnode = malloc(sizeof(*newnode));
		if (newnode == NULL) {
			return -2;
		}
		newnode->data = *dp;
		newnode->next = node->next;
		node->next = newnode;
		return 0;
	}
	else {
		return -3;
	}
}
//循环插入
int list_cycinsert(linklist *lp, int i, int size, datatype *dp) {
	int j,ret ;
	linklist* node=lp;
	if (size < 0 || i < 0) {
		return -1;
	}
	for (j = 0; j < size;j++) {
//		ret=list_insert_at(node, i, &dp[j]);
		ret = list_order_insert(node,&dp[j]);
		if (ret<0) {
			return -1;
		}
	}
	return 0;
}

//按序插入
int list_order_insert(linklist* lp, datatype* dp) {
	linklist *node=lp, *newnode;
	while (node->next && node->next->data < *dp) {
		node = node->next;
	}
	newnode = malloc(sizeof(*newnode));
	if (newnode==NULL) {
		return -1;
	}
	newnode->data = *dp;
	newnode->next = node->next;
	node->next = newnode;

	return 0;
}
//按位置删除
int list_delete_at(linklist* lp, int i, datatype* dp) {
	int j = 0;
	linklist* node=lp,*oldnode;
	if (i<0) {
		return -1;
	}
	while (node&&j<i) {
		node = node->next;
		j++;
	}
	oldnode = node->next;
	node->next = oldnode->next;
	*dp = oldnode->data;
	free(oldnode);
	oldnode = NULL;
	return *dp;
}
//删除链表中的值
int list_delete(linklist* lp, datatype* dp) {
	linklist* node = lp,*oldnode;
	while (node->next && node->next->data!=*dp) {
		node = node->next;
	}
	if (node->next==NULL) {
		return -1;
	}
	oldnode = node->next;
	node->next = oldnode->next;
	free(oldnode);
	oldnode = NULL;
	return 0;
}
//打印链表
void list_display(linklist* lp) {
	if (list_isempty(lp)) {
		return;
	}
	linklist* node = lp->next;
	while (node!=NULL) {
		printf("%d  ",node->data);
		node = node->next;
	}
	printf("\n");
	return;
}
//销毁链表
void list_destory(linklist* lp) {
	linklist *node , *nextnode;
	for (node = lp->next; node != NULL; node = nextnode) {
		nextnode =node->next;
		free(node);
	}
	free(lp);
	nextnode = NULL;
	return;
}
//判空
int list_isempty(linklist* lp) {
	if (lp->next==NULL) {
		return 1;
	}
	return 0;
}