#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

#include <stdio.h>
#include <stdlib.h>
#include "comm.h"

typedef struct _sq_stack_ {
	int *data;
	int top;
	int size;
}SeqStack;

SeqStack *init_sqstack(int size);
int free_sqstack(SeqStack *stack);
int push_sqstack(SeqStack *stack ,int data);
int pop_sqstack(SeqStack *stack, int *dest);
int get_top(SeqStack *stack);

#endif
