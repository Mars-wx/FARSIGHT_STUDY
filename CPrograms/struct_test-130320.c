#include <stdio.h>
#include <string.h>

#define SIZE	16	

int main()
{
	typedef struct student {
		int id;
		char name[SIZE];
		int score;
		char sex;
	}Stu, *StuP;


	Stu stu1 = {
		201301,
		"james",
		90,
		'm'
	},stu2 = {
		201302,
		"david",
		99,
		'm'
	}, stu3;

	stu3 = stu1;
	
	StuP stus[3] = { &stu1, &stu2, &stu3};


#if 0
	StuP stup = &stu2;

	stup->id = 201302;
	strcpy(stup->name, "lucy");
	stup->sex = 'f';
	stup->score = 80;

	puts("id:");
	scanf("%d%*c", &stup->id);
	puts("name");
	//	fgets(stu3.name, SIZE, stdin);	
	scanf("%s", stup->name);
	puts("score:");
	scanf("%d%*c", &stu3.score);
	puts("sex:");
	stu3.sex = getchar();

	printf("id:\t%d\n", stu1.id);
	printf("name:\t%s\n", stu1.name);
	printf("score:\t%d\n", stu1.score);
	printf("sex:\t%c\n", stu1.sex);

	printf("id:\t%d\n", stu2.id);
	printf("name:\t%s\n", stu2.name);
	printf("score:\t%d\n", (*stup).score);
	printf("sex:\t%c\n", stup->sex);

	printf("id:\t%d\n", stu3.id);
	printf("name:\t%s", stu3.name);
	printf("score:\t%d\n", stu3.score);
	printf("sex:\t%c\n", stu3.sex);
#endif
	for(int i = 0; i < 3; i ++)
	{
		printf("id:\t%d\n", stus[i]->id);
		printf("name:\t%s\n", stus[i]->name);
		printf("score:\t%d\n", stus[i]->score);
		printf("sex:\t%c\n\n", stus[i]->sex);
	}	
	return 0;
}


#include <stdio.h>

int main()
{
#if 1
	int a[10] = {1,2,3,4,[6] = 7,8,9,10};
	int i;

	for(i = 0; i < 10; i ++)
		printf("%d\n", a[i]);
#endif
	
	struct _test_ {
		int id;
		int score;
		char name[16];
		char sex;
	}stu1 = {
		1,
		100,
		"james",
		'm'
	}, stu2 = {
		.id = 2,
		.score = 100,
		.name = "lucy",
		.sex = 'f'
	};
	printf("id:\t%d\n", stu2.id);
	printf("name:\t%s\n", stu2.name);
	printf("score:\t%d\n", stu2.score);
	printf("sex:\t%c\n", stu2.sex);

	
	return 0;
}
