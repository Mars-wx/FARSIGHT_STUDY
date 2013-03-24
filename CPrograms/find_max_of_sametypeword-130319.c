#include <stdio.h>
#define IS_UPER(CH)		(CH >= 'A' && CH <= 'Z')
#define IS_LOWER(CH)	(CH >= 'a' && CH <= 'z')
#define IS_DIGIT(CH)	(CH >= '0' && CH <= '9')

#if 0

#define F_UPER	'U'
#define F_LOWER	'L'
#define F_DIGIT	'd'

int main()
{
	char *str = "hello123ABCDhelloabc123456789helloworld";
	char *p = str;
	int count = 0,
		max = 0;
	int flag = 0;
	
	for(; '\0' != *p; p ++)
	{
		if(IS_LOWER(*p))
		{
			if(F_LOWER == flag)
				count ++;
			else
			{
				max = max > count ? max : count;
				count = 1;
			}
			flag = F_LOWER;
		}
		else if(IS_UPER(*p))
		{
			if(F_UPER == flag)
				count ++;
			else
			{
				max = max > count ? max : count;
				count = 1;
			}
			flag = F_UPER;
		}
		else if(IS_DIGIT(*p))
		{
			if(F_DIGIT == flag)
				count ++;
			else
			{
				max = max > count ? max : count;
				count = 1;
			}
			flag = F_DIGIT;
		}
	}
	max = max > count ? max : count;
	printf("max: %d\n", max);
	return 0;
}

#else

int main()
{
	char *str = "hello123ABCDhelloabc123456789helloworld";
	char *p = str;
	int count = 0;
	int max = 0;

	while('\0' != *p)
	{
		if(IS_LOWER(*p))
		{
			for(count = 0; IS_LOWER(*p); p ++)
				count ++;
			max = max > count ? max : count;
		}
		else if(IS_DIGIT(*p))
		{
			for(count = 0; IS_DIGIT(*p); p ++)
				count ++;
			max = max > count ? max : count;
		}
		else if(IS_UPER(*p))
		{
			for(count = 0; IS_UPER(*p); p ++)
				count ++;
			max = max > count ? max : count;
		}
	}
	printf("max = %d\n", max);
	return 0;
}
#endif
