#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
*Title:A以10%单利投资100￥，B以5%的复利投资100￥
*编程：需要多久B能够赶上A的收益，且目前的收益为多少
*/
static void rates() {
	double fund = 100, rate_a = 0.1, rate_b = 0.05;
	double sum_a=0.0, sum_b=0.0 ,t=1.0;
	while (1) {
		sum_a = fund * rate_a * t;
		sum_b = fund * pow((1 + rate_b), t) - fund;
		t++;
		if (sum_a-sum_b>=-1e-7&&sum_a-sum_b<=1e-7) {
			break;
		}
	}
	printf("sum=%lf,T=%lf",sum_a,t);
}

/*
*Title:从终端输入数字，输出偶数的个数以及平均值，奇数的个数以及平均值
*/
void eo_num() {
	int arr[10] = { 0 };
	int num=0,i=0,j=0,sum_eve=0,count=0,sum_old=0;
	printf("Input number:\n");
	while (scanf("%d",&num)!=EOF) {
		arr[i] = num;
		i++;
	}
	num = sizeof(arr) / sizeof(int);
	for (j = 0; j <= num;j++) {
		if (arr[j] % 2 == 0) {
			sum_eve += arr[j];
			count++;
		}
		else {
			sum_old += arr[j];
		}
	}
	printf("even_num=%d,even_avg=%d\n",count,sum_eve/count);
	printf("old_num=%d,old_avg=%d\n",num-count,sum_old/(num-count));
}

/**
*Title：从终端输入若干字母，对其中的元音字母进行统计
*/

/*
*title：输出斐波那契额数列的前40项
*斐波那契:1,1,2,3,5,8,13...
*/
void fib() {
	int i = 1, j = 1, count = 0;
	while (count<40) {
		printf("%d ",i);

		count++;
	}
	
}

/**
*title:输出九九乘法表
*/
void mul_tab() {
	
	for (int i = 1; i <= 9;i++) {
		for (int j = i; j <= 9;j++) {
			printf("%d*%d=%d	",i,j,i*j);
		}
		printf("\n");
	}

}


/**
*title：百钱买百鸡，鸡翁一，值钱五，鸡母一，值钱三；三鸡雏，值钱一。百钱买百鸡，问鸡翁，鸡母，鸡雏各几何
*/

/**
*title:求出1000以内的水仙花数
*水仙花数：
*/

/**
*title:求出1000以内的质数
*/

/**
*title:输出下面的东西：
*ABCDEF
*BCDEF
*CDEF
*DEF
*EF
*F
*/
void print() {
	char arr[6] = { 'A','B','C','D','E','F' };
	int i , j;
	for (j = 0; j < 6;j++) {
		for (i = j; i < 6;i++) {
			printf("%c",arr[i]);
		}
		printf("\n");
	}

}

int main() {
	//rates();
	//eo_num();
	//print();
	//mul_tab();
	fib(40);
	exit(0);
}