#include "linknode.h"

LinkNode *create_linknode(int data)
{
	LinkNode *linknode = NULL;

	linknode = (LinkNode *)malloc(sizeof(LinkNode));
	linknode->data = data;
	linknode->next = NULL;

	return linknode;
}

int insert_linknode(LinkNode *linknode, int data)
{
	linknode->next = create_linknode(data);

	return 0;
}
