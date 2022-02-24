#include"dllist.h"
//��������
//����
int dllist_insert(LLIST*, const void* data, int mod);
//����(������)
void* dllist_find(LLIST*, const void* key, dllinst_cmp*);
//ɾ��
int dllist_delete(LLIST*, const void* key, dllinst_cmp*);
//��ȡԪ��
int dllist_fetch(LLIST*, const void* key, dllinst_cmp*, void* data);
//����
void dllist_travel(LLIST*, dllist_op*);
//����
void dllist_destory(LLIST*);
//�����ڲ����Һ���
static list_node* find_(LLIST* llp, const void* key, dllinst_cmp* cmp) {
	list_node* cur;
	for (cur = llp->head.next; cur != &llp->head; cur = cur->next) {
		if (cmp(key, cur->data) == 0) {
			break;
		}
	}
	return cur;
}

//��������
LLIST* dllist_create(int initsize) {
	LLIST* newnode;
	newnode = malloc(initsize);
	if (newnode==NULL) {
		return NULL;
	}
	newnode->head.next = &newnode->head;
	newnode->head.prev = &newnode->head;
	newnode->size = initsize;
	newnode->insert = dllist_insert;
	newnode->delete = dllist_delete;
	newnode->destory = dllist_destory;
	newnode->fetch = dllist_fetch;
	newnode->find = dllist_find;
	newnode->travel = dllist_travel;
	return newnode;
}
//����
int dllist_insert(LLIST* llp, const void* data, int mod) {
	struct dllist_node_st* newnode;
	newnode = malloc(sizeof(*newnode)+llp->size-4);//���node��Ϊdata[0]���Ͳ���-4
	if (newnode == NULL) {
		return -1;
	}

	memcpy(newnode->data,data,llp->size);
	if (mod == LLIST_FORWARD) {
		newnode->prev = &llp->head;
		newnode->next = llp->head.next;
	}
	else if (mod==LLIST_BACKWORD) {
		newnode->prev = llp->head.prev;
		newnode->next = &llp->head;
	}
	else {
		return -3;
	}
	newnode->prev->next = newnode;
	newnode->next->prev = newnode;

	return 0;
}
//����
void *dllist_find(LLIST* llp, const void* key, dllinst_cmp* cmp) {
	struct dllist_node_st* node;
	node = find_(llp,key,cmp);
	if (node==&llp->head) {
		return NULL;
	}
	return node->data;

}
//����
void dllist_travel(LLIST* llp,dllist_op* op) {
	list_node* cur, * tmp ;
	for (cur = llp->head.next; cur != &llp->head;cur=cur->next) {
		op(cur->data);
	}
}

//ɾ��
int dllist_delete(LLIST* llp, const void* key, dllinst_cmp* op) {
	struct dllist_node_st* node;
	node = find_(llp,key,op);
	if (node==&llp->head) {
		return -1;
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;//���󣡷ô��ͻδ���
	free(node);
	node = NULL;
	return 0;
}
//��ȡԪ��
int dllist_fetch(LLIST* llp, const void* key, dllinst_cmp* op, void* data) {
	list_node* node;
	node = find_(llp, key, op);
	if (node==&llp->head) {
		return -1;
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;
	if (data!=NULL) {
		memcpy(data,node->data,llp->size);
	}
	free(node);
	node = NULL;
	return 0;
}
//����
void dllist_destory(LLIST* llp) {
	list_node* tmp,*cur;
	if (!llp) {
		return;
	}
	for (tmp = llp->head.next; tmp!=&llp->head;tmp=cur) {
		cur = tmp->next;
		free(tmp);
	}

	free(llp);
	tmp = NULL;
	cur = NULL;
}


