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
static void print_s(const struct score_st* data) {
	printf("%d %s %d %d\n", data->id, data->name, data->math, data->chinese);
}

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


static void draw_(struct node_st* root, int level) {
	int i;
	if (root==NULL) {
		return;
	}
	for (i = 0; i < level;i++) {
		printf("|----");
	}
	draw_(root->rchild,level+1);
	printf("%d \n",(root)->data.id);
	draw_(root->lchild,level+1);
}
static void draw(struct node_st* root) {
	draw_(root,0);
}

int main() {
	int arr[] = {1,3,2,7,6,5,9,8,4 };
	int i,k;
	struct node_st* tree = NULL;
	struct score_st tmp,*data;
	
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]);i++) {
		tmp.id = arr[i];
		snprintf(tmp.name, NAMESIZE, "std%d", i);
		tmp.math = rand() % 100;
		tmp.chinese = rand() % 100;
		insert(&tree,&tmp);
	}
	draw(tree);
	scanf("%d",&k);
	data = find(tree, k);
	
	if (&data == NULL) {
		fprintf(stderr,"no such member\n");
	}
	else {
		print_s(data);
	}
	
	exit(0);
}