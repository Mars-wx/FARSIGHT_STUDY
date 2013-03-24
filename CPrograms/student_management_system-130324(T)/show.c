#include "head.h"

int show_student_info(Stu *stu,int n_stus)
{
	int i;
	
	printf("%-10s%-10s%-8s%-10s%-8s%-10s\n",
			"name","number","chinese","math",
			"english","total");

	for(i = 0; i < n_stus; i ++)
	{
		printf("%-10s%-10d%-8d%-10d%-8d%-10d\n",
			stu->name, stu->num, stu->chinese, 
			stu->math, stu->english, stu->total);
		stu ++;
	}

	return 0;
}
