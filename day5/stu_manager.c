#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NAMESIZE 32
#define MAXSIZE 5
//定义出生日期
typedef struct {
	int year;	//年
	int month;	//月
	int day;	//日
}birthday_st;
//定义成绩
typedef struct {
	double art;
	double math;
	double program;
}grade_st;
//定义学生
typedef struct {
	int id;	//id
	char name[NAMESIZE];	//名字
	birthday_st birth;	//出生如期
	grade_st grad;	//成绩
}student_st;	

//ADD
void stu_add(student_st* stu) {
	printf("ID:");
	scanf("%d",&stu->id);

	printf("NAME:");
	scanf("%s",stu->name);

	printf("BIRTHDAY:");
	scanf("%d%d%d",&stu->birth.year,&stu->birth.month,&stu->birth.day);

	printf("GRADE:ART MATH PRAGRAM:");
	scanf("%lf%lf%lf",&stu->grad.art,&stu->grad.math,&stu->grad.program);
}
//mod
void stu_mod(student_st* stu) {
	//只提供修改名字的功能，其他类似
	char new_name[NAMESIZE];
	printf("input new name:");
	scanf("%s",new_name);
	strncpy(stu->name,new_name,NAMESIZE);
}
//del
void stu_del(student_st* stu) {
	free(stu);
	stu = NULL;
	if (stu==NULL) {
		printf("success!");
	}
}

//show
void stu_show(student_st* stu) {
	if (stu==NULL) {
		printf("no message!\n");
		return;
	}
		printf("--------------------------------\n");
		printf("ID:%d\nNAME:%s\n",stu->id, stu->name);
		printf("BIRTHDAY:%d-%d-%d\n", stu->birth.year, stu->birth.month, stu->birth.day);
		printf("GRADE: ART:%.2lf  MATH:%.2lf  PROGRAM:%.2lf\n", stu->grad.art, stu->grad.math, stu ->grad.program);
		printf("--------------------------------\n");
}

void menu() {
	printf("***1 ADD***\n");
	printf("***2 MOD***\n");
	printf("***3 DEL***\n");
	printf("***4 CHK***\n");
	printf("***0 exit**\n");
	printf("intput num:");
}
int main() {
	int num;
	student_st* stup = malloc(sizeof(student_st));
	//student_st* stup=NULL;
	
	do {
		menu();
		scanf("%d",&num);
		switch (num){
			case 1:
				stu_add(stup);
				stu_show(stup);
				
				break;
			case 2:
				stu_mod(stup);
				break;
			case 3:
				//stu_del(stup);	//有问题！
				break;
			case 4:
				stu_show(stup);
				break;
			case 0:
				free(stup);
				stup = NULL;
				break;
			default:
				printf("wrong code!\n");
				break;
		}
	} while (num);
	
	exit(0);
}