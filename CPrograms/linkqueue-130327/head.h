#ifndef __HEAD_H__
#define __HEAD_H__

#include "linknode.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct _linkqueue_{
	LinkNode *head,
			 *tail;
	int size;
	int len;
}LinkQueue;

extern LinkQueue *init_linkqueue(int size);
extern int free_linkqueue(LinkQueue *queue);
extern int enqueue(LinkQueue *queue, int data);
extern int dequeue(LinkQueue *queue, int *dest);

#endif
