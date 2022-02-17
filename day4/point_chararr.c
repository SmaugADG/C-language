#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char str[] = "hello,world!";
	char* p = str + 7;


	puts(str);
	puts(p);

	exit(0);
}