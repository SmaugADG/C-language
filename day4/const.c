#include<stdio.h>
#include<stdlib.h>

int main() {
	const float pi = 3.14;

//	pi = 3.1415;     //error！不能修改
	
	float* p = &pi;
	*p = 3.1415;   //这里可以

	exit(0);
}