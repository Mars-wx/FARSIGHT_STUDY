#include <stdio.h>
#include <string.h>

int main()
{
	/*struct student{
		char name[8];
		int age;
	}stu1 = {
		"wx1",
		23
	},stu2;

	strcpy(stu2.name, "wx2");
	stu2.age = 24;*/

	typedef struct student {
		char name[8];
		int age;
	}Stu,*Stus;

	Stu stu3 = {
		"wx3",
		25
	},stu4,stu5;

	Stus stus = &stu4;
	strcpy(stus -> name, "wx4");
	stus -> age = 26;

	scanf("%d%*c",&stu5.age);
	fgets(stu5.name,8,stdin);
//	stu5.sex = getchar();

	Stu stua[3] = {
		{
			"wx6",
			28
		},
		{
			"wx7",
			29
		},
	};

//	printf("Name: %s and Age: %d\n",stu1.name,stu1.age);
//	printf("Name: %s and Age: %d\n",stu2.name,stu2.age);
	printf("Name: %s and Age: %d\n",stu3.name,stu3.age);
	printf("Name: %s and Age: %d\n",stu4.name,stu4.age);
	printf("Name: %s and Age: %d\n",stu5.name,stu5.age);

	int i;
	for(i = 0; i < 3; i++)
	{
		printf("Name: %s and Age: %d\n",stua[i].name,stua[i].age);
	}

	return 0;
}
