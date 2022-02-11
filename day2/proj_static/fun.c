#include <stdio.h>
#include <stdlib.h>
#include "fun.h"

static int i=10;
/*
 *修改成static后只能在当前文件调用，不能被外部函数调用
 *
 * */
static void func(void){
	
	printf("[%s]i=%d\n",__FUNCTION__,i);

}

void call_fun(void){
	func();
}
