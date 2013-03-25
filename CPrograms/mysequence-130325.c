#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N	20

typedef struct _seqlist_{
	int *data;
	int len;
	int size;
}Seqlist;

Seqlist *init_seqlist(int len);
int insert_seqlist(Seqlist *seqlist, int data);
int search_seqlist(Seqlist *seqlist, int data);
int modify_seqlist(Seqlist *seqlist, int src, int dest);
int delete_seqlist(Seqlist *seqlist, int data);
int display_seqlist(Seqlist *seqlist);
int free_seqlist(Seqlist *seqlist);

int main()
{
	Seqlist *seqlist = NULL;
	int locat = 0;
	
	seqlist = init_seqlist(N);
	insert_seqlist(seqlist, 100);
	insert_seqlist(seqlist, 200);
	insert_seqlist(seqlist, 500);
	insert_seqlist(seqlist, 300);
	insert_seqlist(seqlist, 1000);
	display_seqlist(seqlist);

	locat = search_seqlist(seqlist, 300);
	printf("%5d\n", locat);

	modify_seqlist(seqlist, 500, 5000);
	display_seqlist(seqlist);

	delete_seqlist(seqlist, 100);
	display_seqlist(seqlist);

	free_seqlist(seqlist);

	return 0;
}

Seqlist *init_seqlist(int len)
{
	Seqlist *seqlist = NULL;

	seqlist = (Seqlist *)malloc(sizeof(Seqlist));
	seqlist->data = (int *)malloc(sizeof(int) * len);
	memset(seqlist->data, 0 , sizeof(int) * len);	//set to zero
	seqlist->size = len;
	seqlist->len = 0;

	return seqlist;
}

int insert_seqlist(Seqlist *seqlist, int data)
{
	int i;

	if(seqlist->len >= seqlist->size)
		return -1;

	for(i = seqlist->len; i > 0; i--)
		seqlist->data[i] = seqlist->data[i - 1];
	seqlist->data[0] = data;
	seqlist->len ++;

	return 0;
}

int search_seqlist(Seqlist *seqlist, int data)
{
	int i;

	for(i = 0; i < seqlist->len; i++)
		if(seqlist->data[i] == data)
			return i;
	return -1;
}

int modify_seqlist(Seqlist *seqlist, int src, int dest)
{
	int locat;

	locat = search_seqlist(seqlist, src);

	if(locat >= 0)
		seqlist->data[locat] = dest;
	return locat;
}

int display_seqlist(Seqlist *seqlist)
{
	int i;

	for(i = 0; i < seqlist->len; i++)
		printf("%8d",seqlist->data[i]);
	putchar('\n');

	return 0;
}

int delete_seqlist(Seqlist *seqlist, int data)
{
	int i,
		locat;

	if(seqlist->len >= seqlist->size)
		return -1;

	locat = search_seqlist(seqlist, data);
	
	if(locat >= 0)
	{
		for(i = locat; i < seqlist->len - 1; i++)
			seqlist->data[locat] = seqlist->data[locat + 1];
		seqlist->len --;
	}

	return 0;
}

int free_seqlist(Seqlist *seqlist)
{
	free(seqlist->data);
	free(seqlist);

	return 0;
}
