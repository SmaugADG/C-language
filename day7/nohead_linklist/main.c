#include"linklist.h"
int main() {
	int i,ret;
	head_linklist* list=NULL;
	printf("----------insert---------\n");
	ret = list_cycinsert(&list);
	if (ret!=0) {
		fprintf(stderr,"insert err!");
	}
	list_show(list);
	printf("----------delete---------\n");
	//Ê×²¿É¾³ý
	ret = list_delete(&list);
	if (ret!=0) {
		fprintf(stderr,"delete err!");
	}
	list_show(list);
	printf("----------fund-----------\n");
	scanf("%d",&i);
	score* score = NULL;
	score = list_find(list,i);
	if (!score) {
		fprintf(stderr,"no such member!");
	}
	else {
		printf("id=%d\tname=%s\tmath=%d\tchinese=%d\n",
			score->id, score->name, score->math, score->chinese);
	}

	list_destory(list);
	
	list = NULL;
	exit(0);
}