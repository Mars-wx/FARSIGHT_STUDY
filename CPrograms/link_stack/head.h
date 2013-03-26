#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <stdlib.h>

#define N	10
#define DEBUG 0	

typedef struct _linknode_{
	int data;
	struct _linknode_ *next;
}LinkNode;

typedef struct _linkstack_{
	LinkNode *top;
	int len;
	int size;
}LinkStack;

LinkStack *init_linkstack(int size);
int free_linkstack(LinkStack *stack);
int push_linkstack(LinkStack *stack, int data);
int pop_linkstack(LinkStack *stack, int *dest);

#endif
