#include <stdio.h>

int main()
{
	char s[20];
	int i,j;
	gets(s);
	for(i = j = 0; s[i] != '\0'; i++)
		if(s[i] != 'c')
			s[j++] = s[i];
	s[j] = '\0';
	puts(s);
	return 0;
}
