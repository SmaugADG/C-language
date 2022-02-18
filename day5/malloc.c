#include<stdio.h>
#include<stdlib.h>

int main() {
	int* p = NULL;
	p = malloc(sizeof(int));
	if (p==NULL) {
		exit(1);
	}
	*p = 10;
	printf("%p-->%d\n",p,*p);
	free(p);
	p = NULL;//及时置空
	/**p = 13;
	printf("%p-->%d\n",p,*p);*/ //p不置空会变成野指针，再次赋值会产生严重错误
	exit(0);
}