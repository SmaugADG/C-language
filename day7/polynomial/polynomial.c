#include"polynomial.h"
//创建链表，使用头节点
poly_st* poly_create(int arr[][2], int i) {
	int j;
	poly_st* sp,*newnode,*tmp;
	sp = malloc(sizeof(*sp));
	if (sp==NULL) {
		return NULL;
	}
	sp->next = NULL;
	tmp = sp;
	for (j = 0; j < i;j++) {
		newnode = malloc(sizeof(*newnode));
		if (newnode ==NULL) {
			return NULL;
		}
		newnode->coef = arr[j][0];
		newnode->exp = arr[j][1];
		newnode->next = NULL;

		tmp->next = newnode;
		tmp = newnode;
	}
	return sp;
}

//打印链表
void poly_show(poly_st* sp) {
	poly_st* tmp = sp->next;
	while (tmp) {
		if (tmp->next==NULL) {
			printf("(%d)x^%d", tmp->coef, tmp->exp);
		}
		else {
			printf("(%d)x^%d+", tmp->coef, tmp->exp);
		}
		tmp = tmp->next;
	}
	printf("\n");
	return;
}

//销毁
void pol_destory(poly_st *sp) {
	poly_st* tmp,*nextnode;
	for (tmp = sp->next; tmp;tmp=nextnode) {
		nextnode = tmp->next;
		free(tmp);
	}
	free(sp);
	tmp = NULL;
	nextnode = NULL;
	return;
}
//合并
int poly_union(poly_st* sp1, poly_st* sp2) {
	poly_st* node1, *node2,*tmp1;
	node1 = sp1->next;
	node2 = sp2->next;
	tmp1 = sp1;

	while (node1&&node2) {
		if (node1->exp < node2->exp) {
			tmp1->next = node1;
			tmp1 = node1;
			node1 = node1->next;
		}
		else if (node1->exp > node2->exp) {
			tmp1->next = node2;
			tmp1 = node2;
			node2 = node2->next;
		}
		else {//node1->coef==node2->coef
			node1->coef = (node1->coef)+(node2->coef);
			if (node1->coef) {
				tmp1->next = node1;
				tmp1 = node1;
			}
			node1 = node1->next;
			node2 = node2->next;
		}
	}
	if (node1) {
		tmp1->next = node1;
	}
	else {
		tmp1->next = node2;
	}
}