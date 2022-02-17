#include<stdio.h>
#include<stdlib.h>
/**
*º¯ÊıÖ¸Õë
*/
int add(int a,int b) {
	return a + b;
}
int sub(int a,int b) {
	return a - b;
}

int main() {
	int a = 3, b = 5;
	int ret,i;
	
	int (*p)(int, int);
	
	int (*q)(int,int);

	int (*funarr[2])(int,int);
	funarr[0] = add;
	funarr[1] = sub;

	//q = sub;
	//ret = q(a,b);
	//printf("%d\n",ret);

	////ret = add(a,b);
	//p = add;
	//ret = p(a,b);
	//printf("%d",ret);

	for (i = 0; i < 2;i++) {
		ret = funarr[i](a, b);
		printf("%d\n",ret);
	}
	exit(0);
}