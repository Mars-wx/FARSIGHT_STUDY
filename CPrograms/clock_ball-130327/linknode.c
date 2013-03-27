#include "linknode.h"

LinkNode *creat_linknode(int data)
{
	LinkNode *node = NULL;

	node = (LinkNode *)malloc(sizeof(LinkNode));
	node->data = data;
	node->next = NULL;

	return node;
}

int insert_linknode(LinkNode *list, int data)
{
	list->next = creat_linknode(data);
	return 0;
}

int delet_linknode(LinkNode **list)
{
	LinkNode *tmp = *list;

	*list = tmp->next;
	free(tmp);

	return 0;
}

