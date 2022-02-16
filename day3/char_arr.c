#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//判断一个字符串中单词的个数
void char_num() {
	char str[32];
	int count = 0, flag = 0, i;
	gets(str);
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == 32||str[i]==' ') {
			flag = 0;
		}
		else {
			if (flag == 0) {
				count++;
				flag = 1;
			}
		}
	}

	printf("%d ", count);

}

int main() {
	char_num();

	exit(0);
}