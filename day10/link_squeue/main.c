#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"queue.h"
#define NAMESIZE 32
struct score_st {
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
};

int main() {
	int i,ret;
	Queue* queue;
	struct score_st score;
	//创建
	queue = queue_create(sizeof(struct score_st));
	if (queue==NULL) {
		exit(1);
	}
	//数据入队
	for (i = 0; i < 5;i++) {
		score.id = i;
		snprintf(score.name,NAMESIZE,"stu%d",i);
		score.math = rand() % 100;
		score.chinese = rand() % 100;

		ret = queue_enqueue(queue,&score);
		if (ret!=0) {
			exit(1);
		}
	}
	//数据出对并打印
	for (i = 0; i < 5;i++) {
		ret = queue_dequeue(queue,&score);
		if (ret!=0) {
			exit(1);
		}
		printf("%d %s %d %d\n",
			score.id,score.name,score.math,score.chinese);
	}

	//销毁
	queue_destory(queue);
	exit(0);
}