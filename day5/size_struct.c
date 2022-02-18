#include<stdio.h>
#include<stdlib.h>
/**
*对齐策略:addr%sizeof(int),
*变量的当前地址对其变量类型取余,
*如果余数为0就存入,
*如果余数不为0,addr++,然后再取余,直到余数为0
*/
struct simp_st {
	int i;
	char ch;
	float f;
	char ch1;
};
int main() {
	struct simp_st simp;
	printf("%d\n",sizeof(simp));
	exit(0);
}