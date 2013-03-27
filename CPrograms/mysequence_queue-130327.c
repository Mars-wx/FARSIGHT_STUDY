#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N	10
#define DEBUG	0

typedef struct _sequencequeue_ {
	int *data;
	int head;
	int tail;
	int size;
}SeqQueue;

SeqQueue *init_seqqueue(int size);
int enqueue(SeqQueue *seqque, int data);
int dequeue(SeqQueue *seqque, int *dest);
int free_seqqueue(SeqQueue *seqque);

#if DEBUG
void _debug_squeue_(SeqQueue *seqque)	
{
	int i;

	for(i = 0; i <seqque->size; i++)
		printf("%5d",seqque->data[i]);
	putchar('\n');
}
#endif

int main()
{
	SeqQueue *seqque = NULL;
	int value = 1;

	seqque = init_seqqueue(N);
	
	while(0 <= enqueue(seqque, value))
		value++;
#if DEBUG
	_debug_squeue_(seqque);
#endif
	while(0 <= dequeue(seqque, &value))
		printf("%5d",value);
	putchar('\n');

	free_seqqueue(seqque);

	return 0;
}

SeqQueue *init_seqqueue(int size)
{
	SeqQueue *seqque = NULL;

	seqque = (SeqQueue *)malloc(sizeof(SeqQueue));
	seqque->data = (int *)malloc(sizeof(int) * size);
	//memset(seqque->data, 0 , sizeof(int) * size);
	seqque->size = size;
	seqque->head = seqque->tail = 0;
	
	return seqque;
}

int free_seqqueue(SeqQueue *seqque)
{
	free(seqque->data);
	free(seqque);

	return 0;
}

int is_full(SeqQueue *seqque)
{
	return seqque->head == (seqque->tail + 1) % seqque->size;
}

int enqueue(SeqQueue *seqque, int data)
{
	if(is_full(seqque))
		return -1;
	seqque->data[seqque->tail] = data;
	seqque->tail = (seqque->tail + 1) % seqque->size;
	return 0;
}

int is_empty(SeqQueue *seqque)
{
	return seqque->head == seqque->tail;
}

int dequeue(SeqQueue *seqque, int *dest)
{
	if(is_empty(seqque))
		return -1;
	*dest = seqque->data[seqque->head];
	seqque->head = (seqque->head + 1) % seqque->size;
	return 0;
}
