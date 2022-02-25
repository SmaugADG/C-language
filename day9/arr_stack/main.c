#include"sqstack.h"
int main() {
	int i, ret;
	datatype arr[5] = {3,1,5,7,8};
	sqstack* stack = st_create();
	if (stack == NULL) {
		exit(1);
	}
	for (i = 0; i < 5;i++) {
		st_push(stack,&arr[i]);
	}
	st_travel(stack);
	printf("----------------------\n");
	st_top(stack,&ret);
	if (ret) {
		printf("%d\n", ret);
	}
	printf("----------------------\n");
	for (i = 0; i < 5;i++) {
		st_pop(stack,&ret);
		printf("%d ",ret);
	}
	printf("\n");
	printf("----------------------\n");

	st_destory(stack);
	exit(0);
}