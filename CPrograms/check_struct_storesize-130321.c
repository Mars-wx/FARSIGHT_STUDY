#include <stdio.h>

int main()
{
	struct {
		char n;
		int i;
		char m;
	}s;
	
	printf("sizeof(s): %u\n",sizeof(s)); //14

	struct {
		char l;
		double n;
		int i;
		char m;
	}t;
	
	printf("sizeof(t): %u\n",sizeof(t)); //20

	struct {
		char l;
		short i;
		char m;
	}o;
		
	printf("sizeof(o): %u\n",sizeof(o)); //6
	
	struct {
		char l;
		long i;
		char m;
	}p;
		
	printf("sizeof(p): %u\n",sizeof(p)); //12	

	return 0;
}
