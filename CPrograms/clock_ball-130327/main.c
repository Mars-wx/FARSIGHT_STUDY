#include "linkqueue.h"
#include "seqstack.h"

#define QUEUE_SIZE	27
#define M1_SIZE		4
#define M5_SIZE		11
#define H1_SIZE		11

int check_queue(LinkQueue *queue);

int main()
{
	LinkQueue *lq = NULL;
	SeqStack *m1 = NULL,
			 *m5 = NULL,
			 *h1 = NULL;
	int ball;
	int value;
	int count = 0;

	lq = init_linkqueue(QUEUE_SIZE);
	m1 = init_sqstack(M1_SIZE);
	m5 = init_sqstack(M5_SIZE);
	h1 = init_sqstack(H1_SIZE);
	
	for(ball = 1; ball <= QUEUE_SIZE; ball ++)
		enqueue(lq, ball);
#if DEBUG
	_debug_linkqueue_(lq);
#endif

	while(1)
	{
		count ++;
		dequeue(lq, &ball);

		if(0 <= push_sqstack(m1, ball))
			continue;
		while(0 <= pop_sqstack(m1, &value))
			enqueue(lq, value);
	
		if(0 <= push_sqstack(m5, ball))
			continue;
		while(0 <= pop_sqstack(m5, &value))
			enqueue(lq, value);

		if(0 <= push_sqstack(h1, ball))
			continue;
		while(0 <= pop_sqstack(h1, &value))
			enqueue(lq, value);

		enqueue(lq,ball);

		if(0 <= check_queue(lq))
			break;
	}
#if DEBUG
	_debug_linkqueue_(lq);
#endif
	printf("%d-%d:%d\n", count / 60 / 24, count / 60 % 24, count % 60);
	free_sqstack(m1);
	free_sqstack(m5);
	free_sqstack(h1);
	free_linkqueue(lq);
	return 0;
}

int check_queue(LinkQueue *queue)
{
	LinkNode *p = queue->head->next;

	while(NULL != p && NULL != p->next)
	{
		if(p->data > p->next->data)
			return -1;
		p = p->next;
	}
	return 0;
}
