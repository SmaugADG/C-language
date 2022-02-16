#include<stdio.h>
#include<stdlib.h>
/**
*´Ó1¼Óµ½100
*/

int main() {
	int i=1,j=100,sum=0;
	/*while (i<j) {
		sum += i + j;
		i++;
		j--;
	}*/


loop:
	sum += i;
	i++;
	if (i <= j) {
		goto loop;
	}
	printf("%d",sum);
	exit(0);
}