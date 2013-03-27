#ifndef __LINKNODE_H__
#define __LINKNODE_H__

#include <stdlib.h>

typedef struct _linknode_ {
	int data;
	struct _linknode_ *next;
}LinkNode;

extern LinkNode *create_linknode(int data);
extern int insert_linknode(LinkNode *linknode, int data);

#endif
