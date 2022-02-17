#include<stdio.h>
#include<stdlib.h>
/**
*指针与二维数组
*/
int main() {
	int a[2][3] = {1,2,3,4,5,6};
	int i, j;
	int(*p)[3] = a;	//a和p可以互换使用，唯一区别就是p是变量，a是常量

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3;j++) {
			printf("%p-->%d\n",&p[i][j],p[i][j]);
		}
		printf("\n");
	}


	exit(0);
}