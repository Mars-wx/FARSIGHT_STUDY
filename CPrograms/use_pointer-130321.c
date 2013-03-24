#include <stdio.h>

//const int i = 100;

int main()
{
	const int i = 100;

	int *p = &i;

	printf("%p\n",&i);

	*p = 10000;
	
	printf("%p\n",*p);
}
