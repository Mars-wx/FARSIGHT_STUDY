#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N	16
#define DEBUG	0

typedef struct _sqlist_ {
	int *data;
	int len;
	int size;
}SeqList;

SeqList *init_sqlist(int len);
int free_sqlist(SeqList *sq);
int show_sqlist(SeqList *sq);
int insert_sqlist(SeqList *sq, int data);
int search_sqlist(SeqList *sq, int data);
int modify_sqlist(SeqList *sq, int src, int dest);
int delet_sqlist(SeqList *sq, int data);

int main()
{
	SeqList *sqlist = NULL;
	int locat = 0;
	
	sqlist = init_sqlist(N);
	
	insert_sqlist(sqlist, 100);
	insert_sqlist(sqlist, 200);
	insert_sqlist(sqlist, 300);
	insert_sqlist(sqlist, 500);

	locat = search_sqlist(sqlist, 1000);
	printf("%d:\t%d\n", 1000, locat);

	modify_sqlist(sqlist, 300, 3000);

	show_sqlist(sqlist);
	delet_sqlist(sqlist, 100);
	delet_sqlist(sqlist, 200);
	delet_sqlist(sqlist, 3000);
	delet_sqlist(sqlist, 500);
	delet_sqlist(sqlist, 3000);
#if DEBUG
	sqlist->len = N;
#endif
	show_sqlist(sqlist);
	free_sqlist(sqlist);
}

SeqList *init_sqlist(int len)
{
	SeqList *sq = NULL;

	sq = (SeqList *)malloc(sizeof(SeqList));
	sq->data = (int *)malloc(sizeof(int) * len);
	memset(sq->data, 0, sizeof(int) * len);
	sq->size = len;
	sq->len = 0;

	return sq;
}

int search_sqlist(SeqList *sq, int data)
{
	int i;

	for(i = 0; i < sq->len; i ++)
	{
		if(sq->data[i] == data)
			return i;
	}
	return -1;
}

int modify_sqlist(SeqList *sq, int src, int dest)
{
	int locat = 0;

	locat = search_sqlist(sq, src);
	if(locat >= 0)
		sq->data[locat] = dest;
	return locat;
}

int insert_sqlist(SeqList *sq, int data)
{
	int index;
	
	if(sq->len >= sq->size)
		return -1;
	for(index = sq->len; index > 0; index --)
		sq->data[index] = sq->data[index - 1];
	sq->data[0] = data;
	sq->len ++;
	return 0;
}

int delet_sqlist(SeqList *sq, int data)
{
	int locat = 0;
	int i;
	
	if(sq->len <= 0)
		return -1;
	locat = search_sqlist(sq, data);
	if(locat >= 0)
	{
		for(i = locat; i < sq->len - 1; i ++)
			sq->data[i] = sq->data[i + 1];
		sq->len --;
	}
	return locat;
}

int show_sqlist(SeqList *sq)
{
	int i;
	
	for(i = 0; i < sq->len; i ++)
		printf("%5d", sq->data[i]);
	putchar('\n');

	return i;
}

int free_sqlist(SeqList *sq)
{
	free(sq->data);
	free(sq);
	return 0;
}
