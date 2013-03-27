#ifndef __HEAD_H__
#define __HEAD_H__

#include "linknode.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _linkqueue_ {
	LinkNode *head;
	LinkNode *tail;
	int len;
	int size;
}LinkQueue;

extern LinkQueue *init_linkqueue(int size);
extern int enqueue(LinkQueue *linkque, int data);
extern int dequeue(LinkQueue *linkque, int *dest);
extern int free_linkqueue(LinkQueue *linkque);

#endif
