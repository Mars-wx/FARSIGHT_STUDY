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
	locate = search_linklist(head, 'a');
	printf("%d\n", locate);
	modify_linklist(head, 'd', 'z');
	show_linklist(head);
	delet_linklist(head, 'c');
	show_linklist(head);
	free_linklist(head);
	return 0;
}


LinkNode *creat_linklist(void)
{
	return creat_linknode(0);
}

LinkNode *creat_linknode(int data)
{
	LinkNode *node = NULL;

	node = (LinkNode *)malloc(sizeof(LinkNode));
	node->data = data;
	node->next = node;

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
	LinkNode *p = head;
	
	p = head->next;
	while(head != p)
	{
		printf("%5c", p->data);
		p = p->next;
	}
	putchar('\n');
	return 0;
}

int free_linklist(LinkNode *head)
{
	LinkNode *tmp = NULL;
	LinkNode *p = head;
		
	while(head != p->next)
	{
		tmp = p->next;
		p->next = tmp->next;
		free(tmp);
	}
	free(head);
	return 0;
}

int search_linklist(LinkNode *head, int data)
{
	int index = 0;
	LinkNode *p = head->next;

	while(head != p)
	{
		index ++;
		if(data == p->data)
			return index;
		p = p->next;
	}
	return 0;
}

int modify_linklist(LinkNode *head, int src, int dest)
{
	int index = 0;
	int flag = 0;
	LinkNode *p = head->next;
	
	while(head != p)
	{
		index ++;
		if(src == p->data)
		{
			p->data = dest;
			flag ++;
		}
		p = p->next;
	}
	return flag;
}

int delet_linklist(LinkNode *head, int data)
{
	int index = 0;
	LinkNode *tmp = NULL;
	LinkNode *p = head;

	while(head != p->next)
	{
	//	index ++;
		if(data == p->next->data)
		{
			tmp = p->next;
			p->next = tmp->next;
			free(tmp);
		}
		p = p->next;
	}
	return 0;
	
}
