#include <stdio.h>

#define PI 3.14
#define MAX1(a,b) (a>b?a:b)
#define MAX2(a,b) \
		({typeof(a) A=a,B=b;(A)>(B)?(A):(B);})
int main(){
	int i=13,j=9;
	printf("%d\n",MAX2(i,j));
//	printf("%d\n",PI);
	return 0;
}
