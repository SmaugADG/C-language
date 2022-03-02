#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DESC_SIZE 256
#define KEY_SIZE 256
#define BUFSIZE 512
#define FILENAME "trie/dir.txt"
struct node_st {
	struct node_st* ch[26];
	char desc[DESC_SIZE];
};
struct node_st* tree=NULL;

struct node_st* newnode(void) {
	int i;
	struct node_st* node;
	node = malloc(sizeof(*node));
	if (node==NULL) {
		return NULL;
	}
	node->desc[0] = '\0';
	for (i = 0; i < 26;i++) {
		node->ch[i] = NULL;
	}


	return node;
}

int get_word(FILE* fp, char* key, char* desc) {
	int i,j;
	char buf[BUFSIZE];
	char* retp;
	//while (1) {
		retp=fgets(buf,BUFSIZE,fp);
		if (retp==NULL) {
			return -1;
		}
		
	//}
	for (i = 0; i < KEY_SIZE-1&&buf[i]!=':';i++) {
		key[i] = buf[i];
	}
	key[i] = '\0';
	i++;
	for (j = 0; j < DESC_SIZE - 1 && buf[i] != '\0';j++,i++) {
		desc[j] = buf[i];
	}
	desc[j]='\0';
	return 0;
}

int insert(struct node_st** root,char*key,char* desc) {
	if (*root==NULL) {
		*root=newnode();
		if (*root==NULL) {
			return -1;
		}
	}
	if (*key=='\0') {
		strcpy((*root)->desc,desc);
		return 0;
	}

	return insert((*root)->ch + *key -'a',key+1,desc);
}
char* find(struct node_st* root,char* key) {
	if (root==NULL) {
		return NULL;
	}
	if (*key=='\0') {
		return root->desc;
	}
	return find(root->ch[*key-'a'], key + 1);
}

int main() {
	FILE* fp;
	char desc[DESC_SIZE] = { '\0' }, key[KEY_SIZE] = {'\0'};
	char* datap;
	fp = fopen(FILENAME, "r");
	if (fp == NULL) {
		fprintf(stderr, "fopen(): error\n");
		exit(1);
	}
	while(1) {
		int ret;
		ret=get_word(fp,key,desc);
		if (ret==-1) {
			break;
		}
		insert(&tree,key,desc);
	}

	datap=find(tree,"donkey");
	if (datap==NULL) {
		printf("no such member");
	}
	else {
		puts(datap);
	}


	fclose(fp);
	exit(0);
}