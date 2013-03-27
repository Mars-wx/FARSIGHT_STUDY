
#define N	10
#include "head.h"
#define DEBUG	1

#if DEBUG
void _debug_linkqueue_(LinkQueue *linkque)
{
	int i;
	LinkNode *p = linkque->head->next;

	for(i = 0; i < linkque->size; i++)
	{
		printf("%5d",p->data);
		p = p->next;
	}
	putchar('\n');
}
#endif


int main()
{
	LinkQueue *linkque = NULL;
	int value = 1;
	int i;

	linkque = init_linkqueue(N);
	while(0 <= enqueue(linkque, value))
		value++;

	#if DEBUG
	_debug_linkqueue_(linkque);
	#endif

	for(i = 0; i < 7; i++)
	{
		dequeue(linkque, &value);
		printf("%5d",value);
	}
	putchar('\n');

	for(value = 20; value > 15; value--)
		enqueue(linkque, value);

	while(0 <= dequeue(linkque, &value))
		printf("%5d", value);
	putchar('\n');

	free_linkqueue(linkque);
	return 0;
}

LinkQueue *init_linkqueue(int size)
{
	LinkQueue *linkque = NULL;

	linkque = (LinkQueue *)malloc(sizeof(LinkQueue));
	linkque->head = linkque->tail = create_linknode(0);
	linkque->len = 0;
	linkque->size = size;

	return linkque;
}

int free_linkqueue(LinkQueue *linkque)
{
	LinkNode *p = NULL,
			 *tmp = NULL;
	p = linkque->head;

	while(NULL != p)
	{
		tmp = p;
		p = p->next;
		free(tmp);
	}
	free(linkque);

	return 0;
}

int is_full(LinkQueue *linkque)
{
	return linkque->len >= linkque->size;
}

int enqueue(LinkQueue *linkque, int data)
{
	if(is_full(linkque))
		return -1;

	insert_linknode(linkque->tail, data);
	linkque->tail = linkque->tail->next;
	linkque->len++;

	return 0;
}

int is_empty(LinkQueue *linkque)
{
	return linkque->head == linkque->tail;
}

int dequeue(LinkQueue *linkque,int *dest)
{
	if(is_empty(linkque))
		return -1;

	linkque->head = linkque->head->next;
	*dest = linkque->head->data;
	linkque->len--;

	return 0;
}
