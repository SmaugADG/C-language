#include<stdio.h>
#include<stdlib.h>

#define M 3
#define N 4
//void print_arr(int (*p)[N],int m,int n) {	//方式1
void print_arr(int p[][N],int m,int n) {
	int i, j;
	for (i = 0; i < m;i++) {
		for (j = 0; j < n;j++) {
			//printf("%d ",*(*(p+i)+j)); //方式1
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}
}

int main() {

	int a[M][N] = {1,2,3,4,5,6,7,8,9,10,11,12};
	print_arr(a,M,N);
	return 0;
}

/**
* 传递不同参数需要的数据接收格式
*int a[M][N]={}
*int *p=*a;
*int (*q)[N]=a;
*
*-->a[i][j]	*(a+i)+j	a[i]+j	p[i]	*p		q[i][j]		*q		q			p+3		q+2
*-->int		int*		int*	int		int		int			int*	int(*)[N]	int*	int(*)[N]
*/