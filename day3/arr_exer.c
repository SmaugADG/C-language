#include<stdio.h>
#include<stdlib.h>
/*
*一维数组练习
*/
//斐波那契数列
void fib() {
	int fib[10] = {1,1};
	int i,j, temp;
	for (i = 2 ; i < 10;i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	
	//逆序存放
	i = 0, j = sizeof(fib) / sizeof(fib[0])-1;
	while (i < j) {
		temp = fib[i];
		fib[i] = fib[j];
		fib[j] = temp;
		i++;
		j--;
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", fib[i]);
	}
}

//冒泡排序
void bubble_sort() {
	int arr[10] = {4,5,2,7,1,9,0,6,4,3};
	int i, j, temp;
	for (i = 0; i < 9;i++) {
		for (j = 0; j < 9 - i;j++) {
			if (arr[j]<arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < 10;i++) {
		printf("%d	" ,arr[i]);
	}
}

//简单选择排序
void select_sort() {
	int arr[10] = { 4,5,2,7,1,9,0,6,4,3 };
	int i, j, k,tmp;
	for (i = 0; i < 9;i++) {
		k = i;
		for (j = i+1; j < 10;j++) {
			if (arr[j]<arr[k]) {
				k = j;
			}
		}
		if (i!=k) {
			tmp = arr[i];
			arr[i] = arr[k];
			arr[k] = tmp;
		}
	}

	for (i = 0; i < 10;i++) {
		printf("%d  ",arr[i]);
	}
}

//进制转换
void base_cover() {
	int i=0, num, base;
	int arr[32];
	printf("Input the converted num:\n");
	scanf("%d",&num);
	printf("Input the base:");
	scanf("%d",&base);

	do {
		arr[i]=num% base;
		num = num / base;
		i++;
	} while (num!=0);

	for (i--; i >= 0;i--) {
		printf("%x",arr[i]);
	}
	printf("\n");
}
//删除法求质数
void primer() {
	int arr[101] = {0};
	int j,i;

	for (i = 2; i < 101;i++) {
		if (arr[i]==0) {
			for (j = i * 2; j < 101;j+=i) {
				arr[j]=-1;
			}
		}
	}

	for (i = 2; i < 101;i++) {
		if (arr[i]==0) {
			printf("%d ",i);
		}
	}
}

int main() {
	//fib();
	//bubble_sort();
	//select_sort();
	//base_cover();
	primer();
	exit(0);
}