#include "head.h"

#if DEBUG 
void _debug_linkstack_ (LinkStack *stack)
{
	LinkNode *p = stack->top;

	while(NULL != p)
	{
		printf("%3d", p->data);
		p = p->next;
	}
	putchar('\n');
}
#endif

int main()
{
	LinkStack *stack = NULL;
	int value = 1;
	
	stack = init_linkstack(N);

	while(0 <= push_linkstack(stack, value))
		value ++;
#if DEBUG
	_debug_linkstack_(stack);
#endif
	while(0 <= pop_linkstack(stack, &value))
		printf("%3d", value);
	putchar('\n');
	free_linkstack(stack);

	return 0;
}

LinkStack *init_linkstack(int size)
{
	LinkStack *stack = NULL;

	stack = (LinkStack *)malloc(sizeof(LinkStack));
	stack->size = size;
	stack->len = 0;
	stack->top = NULL;

	return stack;
}

int free_linkstack(LinkStack *stack)
{
	LinkNode *p = stack->top,
			 *tmp = NULL;
	
	while(NULL != p)
	{
		tmp = p;
		p = tmp->next;
		free(tmp);
	}
	free(stack);

	return 0;
}



int is_full_linkstack(LinkStack *stack)
{
	return stack->len >= stack->size;
}

int is_empty_linkstack(LinkStack *stack)
{
	return stack->len <= 0;
}

int push_linkstack(LinkStack *stack, int data)
{
	if(is_full_linkstack(stack))
		return -1;
	insert_linknode(stack, data);
	stack->len ++;
	return 0;
}

int pop_linkstack(LinkStack *stack, int *dest)
{
	if(is_empty_linkstack(stack))
		return -1;
	*dest = stack->top->data;
	delet_linknode(stack);
	stack->len --;

	return 0;
}
