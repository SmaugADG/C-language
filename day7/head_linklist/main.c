#include"linklist.h"
/**
*带头节点单链表
*/

int main() {
	int ret,k;
	datatype arr[] = {3,4,7,9,0,1,2,5};
	linklist* list = NULL;
	//创建链表
	list=list_create();
	ret=list_cycinsert(list,0,sizeof(arr)/sizeof(arr[0]),arr);
	
	if (ret < 0) {
		fprintf(stderr,"error parameter!\n");//参数非法
	}
	list_display(list);
	//按值删除
	scanf("%d",&k);
	ret=list_delete(list,&k);
	if (ret==-1) {
		fprintf(stderr,"no such value!\n");
	}
	list_display(list);
	//按位置删除
	list_delete_at(list,3,&ret);
	printf("%d \n",ret);
	list_display(list);

	list_destory(list);
	exit(0);
}