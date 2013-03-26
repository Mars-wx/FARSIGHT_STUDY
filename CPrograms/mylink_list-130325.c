#include <stdio.h>
#include <stdlib.h>

typedef struct _linknode_ {
	int data;
	struct _linknode_ *next;
}LinkNode;

LinkNode *creat_linklist(void);
LinkNode *creat_linknode(int data);
int insert_linklist(LinkNode *head, int data);
int show_linklist(LinkNode *head);
int search_linklist(LinkNode *node, int data); 
int modify_linklist(LinkNode *node, int src, int dest);
int delete_linklist(LinkNode *node, int data);
int free_linklist(LinkNode *head);

int main()
{
	LinkNode *head = NULL;
	int locat = 0;

	head = creat_linklist();
	insert_linklist(head, 'a');
	insert_linklist(head, 'b');
	insert_linklist(head, 'c');
	insert_linklist(head, 'b');
	show_linklist(head);

	locat = search_linklist(head, 'a');
	printf("%5d\n", locat);

	modify_linklist(head, 'b', 'd');
	show_linklist(head);

	delete_linklist(head, 'c');
	show_linklist(head);

	free_linklist(head);

	return 0;
}


LinkNode *creat_linklist(void)
{
	LinkNode *node = NULL;
	
	node = creat_linknode(0);
	node->next = NULL;

	return node;
}

LinkNode *creat_linknode(int data)
{
	LinkNode *node = NULL;

	node = (LinkNode *)malloc(sizeof(LinkNode));
	node->data = data;
	node->next = NULL;

	return node;
}

int insert_linklist(LinkNode *head, int data)
{
	LinkNode *new = NULL;
	
	new = creat_linknode(data);
	new->next = head->next;
	
	head->next = new;
	return 0;
}

int show_linklist(LinkNode *head)
{
	head = head->next;
	while(NULL != head)
	{
		printf("%5c", head->data);
		head = head->next;
	}
	putchar('\n');
	return 0;
}

int search_linklist(LinkNode *node, int data)
{
	int i = 1;

	while(NULL != node->next)
	{
		if(node->next->data == data)
			return i;
		else
		{
			node = node->next;
			i++;
		}
	}

	return -1;
}

int modify_linklist(LinkNode *node, int src, int dest)
{
	while(NULL != node->next)
	{
		if(node->next->data == src)
			node->next->data = dest;	
		else
			node = node->next;
	}

	return 0;
}

int delete_linklist(LinkNode *node, int data)
{
	LinkNode *tmp = NULL;

	while(NULL != node->next)
	{
		if(node->next->data == data)
		{
			tmp = node->next;
			node->next = tmp->next;
			free(tmp);
		}	
		else
			node = node->next;
	}

	return 0;	
}

int free_linklist(LinkNode *head)
{
	LinkNode *tmp = NULL;
	
	while(NULL != head)
	{
		tmp = head;
		head = tmp->next;
		free(tmp);
	}
}
