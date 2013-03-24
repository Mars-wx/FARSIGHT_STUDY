
#ifndef _HEAD_H_
#define _HEAD_H_



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STUS_LEN	10

typedef struct _student_ {
	char name[16];
	int num;
	int chinese;
	int math;
	int english;
	int total;
}Stu;

extern int get_student_info(Stu *stu, int n_stus);
extern int sort_student_info(Stu *stus, int n_stus, int flag);
extern int show_student_info(Stu *stu, int n_stus);

#endif
