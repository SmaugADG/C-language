#include <stdio.h>
#include <stdlib.h>
#include "fun.h"
static int i=100;
int main(){
	printf("[%s]i=%d\n",__FUNCTION__,i);
//	func();
	call_fun();	
	return 0;
}
