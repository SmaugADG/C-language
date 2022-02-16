#include<stdio.h>
#include<stdlib.h>

#define CON 3
#define ROW 2
#define K	2

//互换二维数组的行列
void cov_doubarr() {
	int douarr[ROW][CON] = { {1,2,3},{4,5,6} },tmp[CON][ROW];
	int i, j;
	for (i = 0; i < ROW;i++) {
		for (j = 0; j < CON;j++) {
			tmp[j][i] = douarr[i][j];
			
		}
		
	}
	for (i = 0; i < CON;i++) {
		for (j = 0; j < ROW;j++) {
			printf("%d  ",tmp[i][j]);
		}
		printf("\n");
	}
}

//求最大值及其所在行
void max_num() {
	int douarr[ROW][CON] = { {1,2,3},{4,5,6} };
	int i, j;
	int max[ROW][CON] = {0}, row = 0, con = 0;
	for (i = 0; i < ROW;i++) {
		for (j = 0; j < CON;j++) {
			if (douarr[i][j]>max[i][j]) {
				max[i][j] = douarr[i][j];
				row = i;
				con = j;
			}
		}
	}
	printf("%d ",max[row][con]);
}
//求各行与各列的和
void sum() {
	int douarr[ROW + 1][CON + 1] = { {1,2,3},{4,5,6} };
	int i, j;
	for (i = 0; i < ROW;i++) {
		for (j = 0; j < CON;j++) {
			//douarr[ROW+1][CON + 1] += douarr[i][j];
			douarr[i][CON] += douarr[i][j];
			douarr[ROW][j] +=  douarr[i][j];
		}
	}
	for (i = 0; i < ROW + 1;i++) {
		for (j = 0; j < CON + 1;j++) {
			printf("%d ",douarr[i][j]);
		}
		printf("\n");
	}
}

//矩阵乘积
void mul() {
	int arr1[ROW][CON] = {1,2,3,4,5,6};
	int arr2[CON][K] = {1,2,3,4,5,6};
	int ret[ROW][K] = {0};
	int i, j, k;
	
	for (i = 0; i < ROW;i++) {
		for (j = 0; j < K;j++) {
			for (k = 0; k < CON;k++) {
				ret[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}


	for (i = 0; i < ROW;i++) {
		for (j = 0; j < K;j++) {
			printf("%d  ",ret[i][j]);
		}
		printf("\n");
	}
}

int main() {
	//cov_doubarr();
	//max_num();
	//sum();
	mul();
	exit(0);
}