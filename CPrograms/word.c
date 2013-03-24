#include <stdio.h>
#define N	30
#define SPACE	1	
#define WORD	0

int main()
{
	char ch;
	int count;
	int n_word = 0;
	int flag = SPACE;

	for(count = 0; count < N && '\n' != (ch = getchar()); count ++)
	{
		if(ch >= 'a' && ch <= 'z')
		{
			n_word += flag;
			flag = WORD;
		}
		else if (ch >= 'A' && ch <= 'Z')
		{
			ch += 32;
			n_word += flag;
			flag = WORD;
		}
		else
		{
			ch = 32;
			flag = SPACE;	
		}
		putchar(ch);
	}

	printf("\nn_word : %d\n", n_word);
	return 0;
}
