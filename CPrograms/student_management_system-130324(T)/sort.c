#include "head.h"

int sort_student_info(Stu *stus, int n_stus, int flag)
{
	int i,j;
	Stu tmp;

	n_stus --;
	for(i = 0; i < n_stus; i ++)
	{
		for(j = 0; j < n_stus - i; j ++)
		{
			if(flag[&stus[j].chinese] < flag[&stus[j + 1].chinese])
			{
				tmp = stus[j];
				stus[j] = stus[j + 1];
				stus[j + 1] = tmp;
			}
		}
	}
	return 0;
}
