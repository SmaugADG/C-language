#include <stdio.h>
#include <stdlib.h>

#if 0
// static的继承性 一次定义后，地址不会改变
void fun(){
	static int x = 0;
	x++;
	printf("%p->%d\n",&x,x);
}

int main(){
	fun();
	fun();
	fun();
	return 0;
}

#endif

