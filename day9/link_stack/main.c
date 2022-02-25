#include<math.h>
#include"lnstack.h"
#define NAMESIZE 32

struct score_st {
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
};
static void print_s(const void* recode) {
	const struct score_st* score = recode;
	printf("%d %s %d %d\n",score->id,score->name,score->math,score->chinese);
}

int main() {
	int i,ret;
	struct score_st score;
	STACK* st;
	st=stack_create(sizeof(struct score_st));
	if (!st) {
		exit(1);
	}
	
	for (i = 0; i < 5;i++) {
		score.id = i;
		snprintf(score.name,NAMESIZE,"stu%d",i);
		score.math = rand() % 100;
		score.chinese = rand() % 100;

		if (stack_push(st, &score)) {
			exit(1);
		}
	}
	while (1) {
		ret = stack_pop(st,&score);
		if (ret==-1) {
			break;
		}
		print_s(&score);
	}
	

	stack_destory(st);

	exit(0);
}