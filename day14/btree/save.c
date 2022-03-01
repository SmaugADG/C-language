#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define NAMESIZE 32
#define FNAME "btree/save/save.txt"
struct node_st {
	struct node_st* lchild,*rchild;
	char data;
};
struct node_st* tree = NULL;
/**
*辅助函数
*/

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
	printf("%c\n", root->data);
	draw_(root->lchild, level + 1);
}
static void draw(struct node_st* root) {
	draw_(root, 0);
	printf("=================================================\n");
}

//保存到广义表
static  int  save_(struct node_st* root, FILE* fp) {
	fputc('(', fp);
	if (root == NULL) {
		fputc(')', fp);
		return 0;
	}
	fputc(root->data, fp);
	save_(root->lchild, fp);
	save_(root->rchild, fp);

	fputc(')\n', fp);
	return 0;
}

/**
*功能函数
*/
//插入
 int insert(struct node_st** root,int data) {
	struct node_st* node;

	if ((*root)==NULL) {
		node=malloc(sizeof(struct node_st));
		if (node==NULL) {
			return -1;
		}
		node->data = data;
		node->lchild = NULL;
		node->rchild = NULL;
		(*root) = node;
		return 0;
	}
	
	if (data<=(*root)->data) {
		return insert(&(*root)->lchild,data);
	}
	else {
		return insert(&(*root)->rchild,data);
	}
}


 //保存到广义表
 void save(struct node_st* root,const char* path) {
	 FILE* fp;
	 fp=fopen(path,"w");
	 if (fp == NULL) {
		 return;
	 }
	 save_(tree,fp);//不要递归save函数，会频繁执行fopen

 }

//销毁
void destory(struct node_st* root) {
	struct node_st* cur;
	if (root==NULL) {
		return;
	}
	destory(root->lchild);
	destory(root->rchild);
	free(root);
}

int main() {
	char arr[] = "ksfvdcglh";
	int i,k;
	//创建
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]);i++) {
		insert(&tree,arr[i]);
	}
	//打印显示
	draw(tree);

	//保存到广义表
	save(tree,FNAME);
	//销毁
	destory(tree);
	tree = NULL;
	exit(0);
}