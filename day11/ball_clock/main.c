#include<stdio.h>
#include<stdlib.h>
#include"sqstack.h"
#include"queue.h"

#define NR_BALL 27

static int  check(Queue* qu) {
	int i = (qu->head+1)%MAXSIZE;
	while (i!=qu->tail) {
		if (qu->data[i]>qu->data[(i+1)%MAXSIZE]) {
			return 0;
		}
		i = (i + 1) % MAXSIZE;
	}
	return 1;
}

int main() {
	int i,tmp,val,time=0;
	Queue* qu;
	sqstack* st_min, * st_fiv_emin, * st_hour;

	qu = queue_create();
	if (qu==NULL) {
		exit(-1);
	}
	st_min=st_create();
	if (st_min==NULL) {
		exit(-1);
	}
	st_fiv_emin =st_create();
	if (st_fiv_emin ==NULL) {
		exit(-1);
	}
	st_hour =st_create();
	if (st_hour ==NULL) {
		exit(-1);
	}

	for (i = 0; i < NR_BALL;i++) {
		queue_enqueue(qu,&i);
	}
	//queue_travel(qu);

	while (1) {
		queue_dequeue(qu,&tmp);
		time++;
		if (st_min->top!=3) {
			st_push(st_min,&tmp);
		}
		else {
			while (!st_isempty(st_min)) {
				st_pop(st_min,&val);
				queue_enqueue(qu,&val);
			}
			if (st_fiv_emin->top!=10) {
				st_push(st_fiv_emin,&tmp);
			}
			else {
				while (!st_isempty(st_fiv_emin)) {
					st_pop(st_fiv_emin,&val);
					queue_enqueue(qu,&val);
				}
				if (st_hour->top!=10) {
					st_push(st_hour,&tmp);
				}
				else {
					while (!st_isempty(st_hour)) {
						st_pop(st_hour,&val);
						queue_enqueue(qu,&val);
					}
					queue_enqueue(qu,&tmp);
					if (check(qu)) {
						break;
					}
				}
			}
		}
	}
	printf("time=%d\n",time);
	queue_travel(qu);
	queue_destory(qu);
	st_destory(st_min);
	st_destory(st_fiv_emin);
	st_destory(st_hour);

	exit(0);
}