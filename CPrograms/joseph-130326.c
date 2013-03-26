#include <stdio.h>
#include <stdlib.h>

typedef struct _linknode_ {
	int data;
	struct _linknode_ *next;
}LinkNode;

LinkNode *creat_linknode(int data);
int insert_linklist(LinkNode *head, int data);
int show_linklist(LinkNode *head);
int free_linklist(LinkNode *head);
LinkNode *joseph(LinkNode *list, int base);

int main()
{
	LinkNode *list = NULL;
	int i;
	int n, base;
	
	scanf("%d%d", &n, &base);	
	list = creat_linknode(1);
	for(i = n; i > 1 ; i --)	
		insert_linklist(list, i);
	show_linklist(list);
	list = joseph(list, base);
	show_linklist(list);
	free_linklist(list);
	return 0;
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
	
	do{
		printf("%5d", p->data);
		p = p->next;
	}
	while(head != p);
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

LinkNode *joseph(LinkNode *list, int base)
{
	int i = 0;
	LinkNode *tmp = NULL;
	
	while(list != list->next)
	{
		i ++;
		if( i == base - 1)	//if(!(i % (base -1)))
		{
			tmp = list->next;
			list->next = tmp->next;
			free(tmp);
			i = 0;
		}
		list = list->next;
	}
	return list;
}
