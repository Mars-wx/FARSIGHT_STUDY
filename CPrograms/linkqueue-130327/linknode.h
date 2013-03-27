#ifndef __LINKNODE_H__
#define __LINKNODE_H__

#include <stdlib.h>

typedef struct _linknode_{
	int data;
	struct _linknode_ *next;
}LinkNode;

extern LinkNode *creat_linknode(int data);
extern int insert_linknode(LinkNode *list, int data);
extern int delet_linknode(LinkNode **list);

#endif
