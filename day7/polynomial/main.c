#include"polynomial.h"
/**
*实现两个多项式合并的功能
*/
int main() {
	int a[][2] = { {5,0},{2,1},{8,8},{3,16} };//a=5+2x^1+8x^8+3x^16
	int b[][2] = { {6,1},{16,6},{-8,8} };//b=6x^1+a6x^6-8x^8
	poly_st* sp1, * sp2;
	sp1 = poly_create(a,4);
	sp2 = poly_create(b,3);
	poly_show(sp1);
	poly_show(sp2);

	poly_union(sp1,sp2);
	poly_show(sp1);

	pol_destory(sp1);
	//pol_destory(sp2);
	sp1 = NULL;
	sp2 = NULL;
	exit(0);
}
