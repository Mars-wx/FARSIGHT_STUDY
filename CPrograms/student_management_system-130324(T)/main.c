#include "head.h"

int main(int argc, char *argv[])
{
	int flag = 0;
	Stu *stus = NULL;
	int nu = 0;

	if(argc != 2 || '-' != argv[1][0] || 2 != strlen(argv[1]))
	{
		printf("invalid arguments of '%s'.\n",argv[1]);
		return -1;
	}

	switch(argv[1][1])
	{
	case 'c':
		flag = 0;
		break;
	case 'm':
		flag = 1;
		break;
	case 'e':
		flag = 2;
		break;
	case 't':
		flag = 3;
		break;
	default:
		printf("invalid arguments of '%s'.\n",argv[1]);
		return -1;
	}

	stus = (Stu *)malloc(sizeof(Stu) * STUS_LEN);

	nu = get_student_info(stus,STUS_LEN);
	sort_student_info(stus,STUS_LEN,flag);
	show_student_info(stus,nu);
	free(stus);
	return 0;
}



