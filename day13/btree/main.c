#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define NAMESIZE 32
struct score_st {
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
};
struct node_st {
	struct node_st* lchild,*rchild;
	struct score_st data;
};
struct node_st* tree = NULL;
/**
*辅助函数
*/
//打印成员
static void print_s(const struct score_st* data) {
	printf("%d %s %d %d\n", data->id, data->name, data->math, data->chinese);
}
//画树（打印显示）
static void draw_(struct node_st* root, int level) {
	int i;
	if (root == NULL) {
		return;
	}
	draw_(root->rchild, level + 1);
	for (i = 0; i < level; i++) {//{1,3,2,7,6,5,9,8,4 };
		printf("|----");
		
	}
	printf("%d %s %d %d \n", (root)->data.id,(root)->data.name,(root)->data.math,(root)->data.chinese);
	//printf("%d\n", (root)->data.id);
	draw_(root->lchild, level + 1);
}
static void draw(struct node_st* root) {
	draw_(root, 0);
	printf("=================================================\n");
	//getchar();
}
//获得左右子树的差
static int get_num(struct node_st* root) {
	if (root==NULL) {
		return 0;
	}
	return get_num(root->lchild ) + 1 + get_num(root->rchild);
}
//寻找左子树叶节点
static struct node_st* find_min(struct node_st*root) {
	if (root->lchild==NULL) {
		return root;
	}
	return find_min(root->lchild);
}
//寻找右子树叶节点
static struct node_st* find_max(struct node_st* root) {
	if (root->rchild==NULL) {
		return root;
	}
	find_max(root->rchild);
}
//左旋
static void turn_left(struct node_st** root) {
	struct node_st* cur = *root;
	*root = cur->rchild;
	cur->rchild = NULL;

	find_min(*root)->lchild = cur;

	//draw(tree);
	
}
//右旋
static void turn_right(struct node_st** root) {
	struct node_st* cur = *root;
	*root = cur->lchild;
	cur->lchild = NULL;
	find_max(*root)->rchild = cur;

	//draw(tree);

}
/**
*功能函数
*/
//插入
static int insert(struct node_st** root,struct score_st*data) {
	struct node_st* node;

	if ((*root)==NULL) {
		node=malloc(sizeof(struct node_st));
		if (node==NULL) {
			return -1;
		}
		node->data = *data;
		node->lchild = NULL;
		node->rchild = NULL;
		(*root) = node;
		return 0;
	}
	
	if (data->id<=(*root)->data.id) {
		return insert(&(*root)->lchild,data);
	}
	else {
		return insert(&(*root)->rchild,data);
	}
}

//查找
static struct score_st* find(struct node_st* root,const int id) {
	if (root==NULL) {
		return NULL;
	}
	if (id == root->data.id) {
		return &root->data;
	}
	if (id<root->data.id) {
		return find(root->lchild,id);
	}
	else {
		return find(root->rchild,id);
	}
}


//平衡二叉树
static void balance(struct node_st** root) {
	if (*root==NULL) {
		return;
	}
	int sub=0;
	while (1) {
		sub = get_num((*root)->lchild) 
			- get_num((*root)->rchild);
		if (sub>=-1&&sub<=1) {
			break;
		}
		if (sub<-1) {
			turn_left(root);
		}
		else {
			turn_right(root);
		}
	}
	balance(&(*root)->lchild);
	balance(&(*root)->rchild);
}
//删除
static void delete(struct node_st** root,int id) {
	struct node_st** node = root;
	struct node_st* cur = NULL;
	while (*node!=NULL&&(*node)->data.id!=id) {
		if (id<(*node)->data.id) {
			node = &(*node)->lchild;
		}
		else {
			node = &(*node)->rchild;
		}
	}
	if (*node==NULL) {
		return;
	}
	cur = *node;
	if (cur->lchild==NULL) {
		*node = cur->rchild;
	}
	else {
		*node = cur->lchild;
		find_max(cur->lchild)->rchild = cur->rchild;
		free(cur);
	}
}

int main() {
	int arr[] = { 1,2,3,7,6,5,9,8,4 };
	int i,k;
	
	struct score_st tmp,*data;
	//创建
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]);i++) {
		tmp.id = arr[i];
		snprintf(tmp.name, NAMESIZE, "std%d", i);
		tmp.math = rand() % 100;
		tmp.chinese = rand() % 100;
		insert(&tree,&tmp);
	}
	//打印显示
	draw(tree);

	//平衡二叉树
	balance(&tree);
	draw(tree);

	//删除
	k = 5;
	delete(&tree,k);
	draw(tree);
	/*balance(&tree);
	draw(tree);*/

	//查找
	/*scanf("%d",&k);
	data = find(tree, k);
	
	if (&data == NULL) {
		fprintf(stderr,"no such member\n");
	}
	else {
		print_s(data);
	}*/
	
	exit(0);
}