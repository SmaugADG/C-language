#include<stdio.h>
#include<stdlib.h>

int main() {
	int a[] = {5,1,7,2,8,3};
	int y;
	int* p = &a[1];

	y = (*--p)++;
	printf("y=%d\n",y);
	
	
	exit(0);

}