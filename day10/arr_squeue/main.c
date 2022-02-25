#include"queue.h"



int main() {
	int i,ret;
	datatype* dp=NULL;
	Queue* queue;
	queue = queue_create();
	datatype arr[5] = {1,2,3,4,5};
	for (i = 0; i < 5;i++) {
		ret = queue_enqueue(queue, &arr[i]);
		if (ret!=0) {
			fprintf(stderr,"queue is full");
		}
	}

	queue_travel(queue);
	printf("--------------------------------\n");

	for (i = 0; i < 5;i++) {
		ret = queue_dequeue(queue,&arr[0]);
		if (!ret) {
			printf("%d ",arr[0]);
		}
	}
	printf("\n--------------------------------\n");

	queue_clear(queue);
	queue_travel(queue);
	printf("--------------------------------\n");
	queue_destory(queue);
	queue = NULL;
	exit(0);
}