#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]) {
	int i;
	printf("%d",argc);
	for (i = 0; i < argc;i++) {
		puts(argv[i]); //输出了当前程序的名称
	}

	return 0;
}