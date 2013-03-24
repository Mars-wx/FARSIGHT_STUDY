#include <stdio.h>

#define IS_DIG(CH)	(CH >= '0' && CH <= '9')
#define IS_DOT(CH)	('.' == CH)

int main()
{
	char ch;
	int ip_8 = 0,
		ip_32 = 0;
	int n_dig = 0,
		n_dot = 0;

	while('\n' != (ch = getchar()))
	{
		if(IS_DIG(ch))
		{
			ip_8 *= 10;
			ip_8 += ch - '0';
			n_dig ++;
		}
		else if(IS_DOT(ch))
		{
			if(ip_8 > 255 || n_dig < 1 || n_dig > 3)
				goto Error;
			ip_32 <<= 8;
			ip_32 += ip_8;
			ip_8 = 0;
			n_dig = 0;
			n_dot ++;
		}
		else
			goto Error;
	}
	if(ip_8 > 255 || n_dig < 1 || n_dig > 3 || 3 != n_dot)
		goto Error;
	ip_32 <<= 8;
	ip_32 += ip_8;

	printf("%u\n", ip_32);
	return 0;

Error:
	puts("invalid ip !");
	return -1;
}
