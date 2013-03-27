#include "seqstack.h"

#if DEBUG
void _debug_ (SeqStack *stack)
{
	int i;

	for(i = 0; i < stack->top; i ++)
		printf("%3d", stack->data[i]);
	putchar(10);
}
#endif

SeqStack *init_sqstack(int size)
{
	SeqStack *stack = NULL;

	stack = (SeqStack *)malloc(sizeof(SeqStack));
	stack->data = (int *)malloc(sizeof(int) * size);
	stack->top = 0;
	stack->size = size;

	return stack;
}

int free_sqstack(SeqStack *stack)
{
	free(stack->data);
	free(stack);
	return 0;
}

int is_full_sqstack(SeqStack *stack)
{
	return stack->top >= stack->size;
}

int is_empty_sqstack(SeqStack *stack)
{
	return stack->top <= 0;
}

int push_sqstack(SeqStack *stack ,int data)
{
	if( is_full_sqstack(stack))
		return -1;
	stack->data[stack->top ++] = data;
	return 0;
}

int pop_sqstack(SeqStack *stack, int *dest)
{	
	if(is_empty_sqstack(stack))
		return -1;
	*dest = stack->data[-- stack->top];
	return 0;
}

#if DEBUG
int get_top(SeqStack *stack)
{
	return stack->data[stack->top - 1];
}
#endif
