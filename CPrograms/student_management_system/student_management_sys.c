#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N	10

typedef struct studentInfo {
	char name[N];
	int id;
	int chinese;
	int mathe;
	int english;
	int total;
} Stu;

int getData(Stu *stus);
int sortstu(Stu *stus);
int displaystu(Stu *stus);

int main()
{
	Stu *stus = NULL;
	stus = malloc(sizeof(struct studentInfo) * 10);

	getData(stus);

	puts("Before:\nName  \t\tId  \t\tChinese  \t\tMath  \t\tEnglish  \tTotal");

	displaystu(stus);

	sortstu(stus);
	
	puts("\nAfter:\nName  \t\tId  \t\tChinese  \t\tMath  \t\tEnglish  \tTotal");

	displaystu(stus);

	free(stus);

	return 0;
}

int getData(Stu *stus)
{
	int i,sum = 0;
	char buff[50];

	for(i = 0; i < 10; i++)
	{
		if(NULL == fgets(buff, 50, stdin))
		{
			puts("invalid");
			break;
		}
		else
		{
			strcpy(stus[i].name, strtok(buff, ":"));
			stus[i].id = atoi(strtok(NULL, ":"));
			sum += (stus[i].chinese = atoi(strtok(NULL, ":")));
			sum += (stus[i].mathe = atoi(strtok(NULL, ":")));
			sum += (stus[i].english = atoi(strtok(NULL, ":")));
			stus[i].total = sum;
			sum = 0;
		}
	}

	return 0;
}

int sortstu(Stu *stus)
{
	int i,j;
	Stu p;
	
	for(i = 0; i < 10; i++)
		for(j = i + 1; j < 10; j++)
		{
			if(stus[i].english > stus[j].english)
			{
				p = stus[i];
				stus[i] = stus[j];
				stus[j] = p;
			}
		}

	return 0;
}

int displaystu(Stu *stus)
{
	int i;

	for(i = 0; i < 10; i++)
	{
		printf("%s  \t%d  \t%d  \t\t\t%d  \t\t%d  \t\t%d\n", stus[i].name, stus[i].id, stus[i].chinese, stus[i].mathe, stus[i].english, stus[i].total);
	}
	return 0;
}
