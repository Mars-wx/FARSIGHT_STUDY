#include <stdio.h>

int main()
{
	struct {
		int n;
		char ch[5];
		double d;
	}s;

	printf("sizeof(s): %d\n",sizeof(s));

	return 0;
}
