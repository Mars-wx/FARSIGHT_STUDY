#include "linkqueue.h"


#if DEBUG
void _debug_linkqueue_(LinkQueue *queue)
{
	LinkNode *p = queue->head->next;

	while(NULL != p)
	{
		printf("%5d", p->data);
		p = p->next;
	}
	putchar('\n');
}
#endif

LinkQueue *init_linkqueue(int size)
{
	LinkQueue *queue = NULL;

	queue = (LinkQueue *)malloc(sizeof(LinkQueue));
	queue->head = creat_linknode(0);
	queue->tail = queue->head;
	queue->size = size;
	queue->len = 0;

	return queue;
}

int free_linkqueue(LinkQueue *queue)
{
	LinkNode *p = queue->head,
			 *tmp = NULL;
	
	while(NULL != p)
	{
		tmp = p;
		p = p->next;
		free(tmp);
	}
	free(queue);
	
	return 0;
}

int is_full_linkqueue(LinkQueue *queue)
{
	return queue->len >= queue->size;
}

int is_empty_linkqueue(LinkQueue *queue)
{
	return queue->head == queue->tail;
}

int enqueue(LinkQueue *queue, int data)
{
	if(is_full_linkqueue(queue))
		return -1;
	insert_linknode(queue->tail, data);
	queue->tail = queue->tail->next;
	queue->len ++;
	return 0;
}

int dequeue(LinkQueue *queue, int *dest)
{
	if(is_empty_linkqueue(queue))
		return -1;
//	*dest = queue->head->next->data;
	delet_linknode(&queue->head);
	*dest = queue->head->data;
	queue->len --;

	return 0;
}
