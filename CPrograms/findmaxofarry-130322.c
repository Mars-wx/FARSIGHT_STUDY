#include <stdio.h>

void find(int s[], int t,int *k)
{
	int i,max = 0;
	
	for(i = 0; i < t; i++)
	{
		if(s[i] > max)
		{
			max = s[i];
			*k = i;
		}
	}
}

int main()
{
	int a[10] = {12,23,34,45,56,67,78,89,11,22},k;
	find(a, 10, &k);
	printf("max:%d , id:%d\n",a[k],k);
	return 0;
}
