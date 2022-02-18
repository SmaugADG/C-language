#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
//共用体
//
/**
*title:将以各32位无符号数的高十六位和低十六位相加
*/
union test_un {
	struct {
		uint16_t i;
		uint16_t j;
	}x;
	uint32_t y;
}a;


int main() {
	//方法一：使用位运算
	//uint32_t i = 0x11223344; //uint32_t定义一个32位无符号数
	//printf("%x",(i>>16)+i&0xffff);

	//方法二：使用共用体
	a.y = 0x11223344;
	printf("%x",a.x.i+a.x.j);

	exit(0);
}