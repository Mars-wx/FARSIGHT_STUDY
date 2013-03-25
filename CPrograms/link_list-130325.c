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
int free_linklist(LinkNode *head);
int search_linklist(LinkNode *head, int data);
int modify_linklist(LinkNode *head, int src, int dest);
int delet_linklist(LinkNode *head, int data);

int main()
{
	LinkNode *head = NULL;
	int locate = 0;
	
	head = creat_linklist();
	insert_linklist(head, 'a');
	insert_linklist(head, 'b');
	insert_linklist(head, 'c');
	locate = search_linklist(head, 'z');
	printf("%d\n", locate);
	modify_linklist(head, 'b', 'z');
	show_linklist(head);
	delet_linklist(head, 'c');
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

int search_linklist(LinkNode *head, int data)
{
	int index = 0;
	
	head = head->next;
	while(NULL != head)
	{
		index ++;
		if(data == head->data)
			return index;
		head = head->next;
	}
	return 0;
}

int modify_linklist(LinkNode *head, int src, int dest)
{
	int index = 0;
	int flag = 0;
	
	head = head->next;
	while(NULL != head)
	{
		index ++;
		if(src == head->data)
		{
			head->data = dest;
			flag ++;
		}
		head = head->next;
	}
	return flag;
}

int delet_linklist(LinkNode *head, int data)
{
	int index = 0;
	LinkNode *tmp = NULL;
	
	while(NULL != head && NULL != head->next)
	{
		index ++;
		if(data == head->next->data)
		{
			tmp = head->next;
			head->next = tmp->next;
			free(tmp);
		}
		head = head->next;
	}
	return 0;
	
}
