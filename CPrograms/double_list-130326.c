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
int show_dlinklist(DlinkNode *head);
int search_dlinklist(DlinkNode *head, int data);
int delet_dlinklist(DlinkNode *head, int data);
int modify_dlinklist(DlinkNode *head, int src, int dest);

int main()
{
	DlinkNode *head = NULL;
	int locate = 0;

	head = creat_dlinklist();
	insert_dlinklist(head, 200);
	insert_dlinklist(head, 200);
	insert_dlinklist(head, 200);
	insert_dlinklist(head, 200);
	locate = search_dlinklist(head, 1000);
	printf("locate:\t%d\n", locate);
	modify_dlinklist(head, 3000, 1000);
	show_dlinklist(head);
	delet_dlinklist(head, 100);
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

int search_dlinklist(DlinkNode *head, int data)
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

int delet_dlinklist(DlinkNode *head, int data)
{
	DlinkNode  *tmp = NULL;
	
	while(NULL != head && NULL != head->next)
	{
		if(data == head->next->data)
		{
			tmp = head->next;
			head->next = tmp->next;
			if(tmp->next)
				tmp->next->pre = head;
			free(tmp);
		}
		else
			head = head->next;
	}
	return 0;
}

int modify_dlinklist(DlinkNode *head, int src, int dest)
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
