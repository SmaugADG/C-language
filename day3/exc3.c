#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
*Title:从终端输入三个数，求方程的根
*/
void root() {
	float a, b, c;
	float x1, x2;
	printf("Input th num:\n");
	scanf("%f%f%f",&a,&b,&c);
	if ((b * b - 4 * a * c) <0) {
		fprintf(stderr,"function has no root\n");
		exit(1);
		//return;
	}
	float ret=sqrt(b*b-4*a*c);
	x1 = (-b + ret) / (2 * a);
	x2 = (-b - ret) / (2 * a);
	printf("%f   %f",x1,x2);

}
int main() {

	root();
	exit(0);
	//return 0;
}