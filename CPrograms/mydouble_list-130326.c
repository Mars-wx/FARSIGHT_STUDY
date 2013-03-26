#include <stdio.h>
#include <stdlib.h>


typedef struct _dlinknode_ {
	int data;
	struct _dlinknode_ *next,
					   *pre;
}DlinkNode;

DlinkNode *creat_dlinklist(void);
DlinkNode *creat_dlinknode(int data);
int insert_dlinklist(DlinkNode *head, int data);
int search_dlinklist(DlinkNode *node, int data);
int modify_dlinklist(DlinkNode *node, int src, int dest);
int delete_dlinklist(DlinkNode *node, int data);
int show_dlinklist(DlinkNode *head);

int main()
{
	DlinkNode *head = NULL;
	int locat = 0;

	head = creat_dlinklist();
	insert_dlinklist(head, 100);
	insert_dlinklist(head, 200);
	insert_dlinklist(head, 300);
	insert_dlinklist(head, 400);
	show_dlinklist(head);

	locat = search_dlinklist(head, 200);
	printf("locate:%5d\n",locat);

	modify_dlinklist(head, 300, 3000);
	show_dlinklist(head);

	delete_dlinklist(head, 100);
	show_dlinklist(head);

	return 0;
}

DlinkNode *creat_dlinklist(void)
{
	return creat_dlinknode(0);
}

DlinkNode *creat_dlinknode(int data)
{
	DlinkNode *node = NULL;

	node = (DlinkNode *)malloc(sizeof(DlinkNode));
	node->data = data;
	node->next = node->pre = NULL;
//	memset(node + offsetof(DlinkNode, next), 0, sizeof(DlinkNode) - offsetof(DlinkNode, next));
}

int insert_dlinklist(DlinkNode *head, int data)
{
	DlinkNode *node = NULL;

	node = creat_dlinknode(data);
	node->next = head->next;
	head->next = node;
	node->pre = head;
	if(node->next)
		node->next->pre = node;
	return 0;
}

int show_dlinklist(DlinkNode *head)
{
	while(NULL != head->next)
	{
		printf("%5d", head->next->data);
		head = head->next;
//		head->next = head->next->next;	//  error !!!
	}
	putchar('\n');

	while(NULL != head->pre)
	{
		printf("%5d", head->data);
		head = head->pre;
	}
	putchar(10);
	return 0;
}

int search_dlinklist(DlinkNode *node, int data)
{
	int index = 0;

	while(NULL != node->next)
	{
		if(data == node->next->data)
			return index;
		else
		{
			node = node->next;
			index ++;
		}
	}

	return -1;
}

int modify_dlinklist(DlinkNode *node, int src, int dest)
{
	while(NULL != node->next)
	{
		if(src == node->next->data)
			node->next->data = dest;
		else
			node = node->next;
	}
	return 0;
}

int delete_dlinklist(DlinkNode *node, int data)
{
	DlinkNode *tmp = NULL;

	while(NULL != node->next)
	{
		if(data == node->next->data)
		{
			tmp = node->next;
			if(NULL != tmp->next)
			{
				node->next = tmp->next;
				tmp->next->pre = tmp->pre;
			}
			else
				node->next = NULL;
			free(tmp);
		}
		else
			node = node->next;
	}
	return 0;

}
