#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _stack_ {
	int *data;
	int top;
	int size;
}Stack;

Stack *init_stack(void);
int push_stack(Stack *sta, int data);
int pop_stack(Stack *sta, int num);
int display_stack(Stack *sta);
int free_stack(Stack *sta);

int main()
{
	Stack *sta = NULL;

	sta = init_stack();

	push_stack(sta, 100);
	push_stack(sta, 300);
	push_stack(sta, 200);
	display_stack(sta);

	pop_stack(sta, 2);
	display_stack(sta);

	free_stack(sta);

	return 0;
}

Stack *init_stack()
{
	Stack *sta = NULL;

	sta = (Stack *)malloc(sizeof(Stack));
	sta->size = 5;
	sta->data = (int *)malloc(sizeof(int) * sta->size);
	memset(sta->data, 0 , sizeof(int) * sta->size);
	sta->top = -1;

	return sta;
}

int push_stack(Stack *sta, int data)
{
	if(sta->top == sta->size - 1)
		return -1;

	sta->data[++sta->top] = data;

	return 0;
}

int display_stack(Stack *sta)
{
	int i;

	for(i = 0; i <= sta->top; i++)
		printf("%5d",sta->data[i]);
	putchar('\n');

	return 0;
}

int pop_stack(Stack *sta, int num)
{
	int i;

	for(i = 0; i < num; i++)
	{
		if(sta->top == -1)
			return -1;

		sta->top--;
	}

	return 0;
}

int free_stack(Stack *sta)
{
	free(sta->data);
	free(sta);

	return 0;
}
