#include "head.h"

LinkNode *creat_linknode(int data)
{
	LinkNode *node = NULL;

	node = (LinkNode *)malloc(sizeof(LinkNode));
	node->data = data;
	node->next = NULL;

	return node;
}

int insert_linknode(LinkStack *stack, int data)
{
	LinkNode *new = NULL;

	new = creat_linknode(data);
	new->next = stack->top;
	stack->top = new;
	
	return 0;	
}

int delet_linknode(LinkStack *stack)
{
	LinkNode *tmp = NULL;

	tmp = stack->top;
	stack->top = tmp->next;
	free(tmp);

	return 0;
}
