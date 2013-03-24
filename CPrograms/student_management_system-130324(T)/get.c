#include "head.h"


int get_student_info(Stu *stu,int n_stus)
{
	char *buf = NULL;
	char *str = NULL;
	int index;
	int sum;
	int i;

	buf = (char *)malloc(sizeof(char) * 32);

	for(i = 0; i < n_stus; i ++)
	{
		sum = 0;
		index = 0;

		if(NULL == gets(buf))
			break;

		str = strtok(buf,":");
		strcpy(stu->name,str);

		str = strtok(NULL,":");
		stu->num = atoi(str);

		while(NULL != (str = strtok(NULL,":")))
		{
			index[&stu->chinese] = atoi(str);
			sum += (&stu->chinese)[index ++];
		}
		stu->total = sum;

		stu ++;
	}
	free(buf);
	return i;
}
