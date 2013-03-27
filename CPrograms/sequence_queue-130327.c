#include <stdio.h>
#include <stdlib.h>

#define N	10
#define DEBUG	1

typedef struct _sequeue_ {
	int *data;
	int head;
	int tail;
	int size;
}SeQueue;

SeQueue *init_sequeue(int size);
int free_sequeue(SeQueue *queue);
int enqueue(SeQueue *queue, int data);
int dequeue(SeQueue *queue, int *dest);

#if DEBUG 
void _debug_sequeue_(SeQueue *queue)
{
	int i;
	
	for(i = 0; i < queue->size; i ++)
		printf("%5d", queue->data[i]);
	putchar('\n');
	
}
#endif

int main()
{
	SeQueue *queue = NULL;
	int value = 1;
	int i;
	
	queue = init_sequeue(N);
	while(0 <= enqueue(queue, value))
		value ++;
#if DEBUG
	_debug_sequeue_(queue);
#endif
	for(i = 0; i < 7; i ++)
	{
		dequeue(queue, &value);
		printf("%3d", value);
	}
	putchar('\n');

	for(value = 10; value < 15; value ++)
		enqueue(queue, value);
	while(0 <= dequeue(queue, &value))
		printf("%3d", value);
	putchar('\n');
#if DEBUG && 0
	_debug_sequeue_(queue);
#endif
	free_sequeue(queue);
	return 0;
}

SeQueue *init_sequeue(int size)
{
	SeQueue *queue = NULL;

	queue = (SeQueue *)malloc(sizeof(SeQueue));
	queue->data = (int *)malloc(sizeof(int) * size);
	queue->head = 0;
	queue->tail = 0;
	queue->size = size;

	return queue;
}

int free_sequeue(SeQueue *queue)
{
	free(queue->data);
	free(queue);
	
	return 0;
}

int is_empty_sequeue(SeQueue *queue)
{
	return queue->head == queue->tail;
}

int is_full_sequeue(SeQueue *queue)
{
	return queue->head == (queue->tail + 1) % queue->size;
}

int enqueue(SeQueue *queue, int data)
{
	if(is_full_sequeue(queue))
		return -1;
	queue->data[queue->tail] = data;
	queue->tail = (queue->tail + 1) % queue->size;
	return 0;
}

int dequeue(SeQueue *queue, int *dest)
{
	if(is_empty_sequeue(queue))
		return -1;
	*dest = queue->data[queue->head];
	queue->head = (queue->head + 1 ) % queue->size;
	return 0;
}
