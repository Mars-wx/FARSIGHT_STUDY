#include <stdio.h>

int main()
{
#if 0
	union {
		int i;
		char s;
	}u;

	u.i = 0x01020304;

	if(u.s == 4)
	{
		puts("little endian");
	}
	else 
	{
		puts("big endian");
	}
#endif

	int value = 0x01020304;
	char *p = (char *)&value;

	if(*p == 4)
		puts("little endian");
	else
		puts("big endian");

	return 0;
}
