#include"lnstack.h"

static int always_match(const void* p1,const void* p2) {
	return 0;
}

STACK* stack_create(int initsize) {
	return dllist_create(initsize);
}

int stack_push(STACK* sp, void* data) {
	return dllist_insert(sp,data,LLIST_FORWARD);
}
int stack_pop(STACK* sp, void* data) {
	return dllist_fetch(sp,(void *)0,always_match,data);
}
void stack_destory(STACK* sp) {
	dllist_destory(sp);
}
