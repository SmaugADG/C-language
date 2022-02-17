#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
*指针数组
*/


//字符串的选择排序
int main() {
	int i, j, k;
	char* name[5] = { "Javascript","Basic","Java","Fortune","Python" };
	char* tmp;

	for (i = 0; i < 5 - 1;i++) {
		k = i;
		for (j = i + 1; j < 5;j++) {
			if (strcmp(name[k],name[j])>0) {
				k = j;
			}
		}
		if (k!=i) {
			tmp = name[i];
			name[i] = name[k];
			name[k] = tmp;
		}
	}


	for (i = 0; i < 5;i++) {
		puts(name[i]);
	}

	exit(0);
}