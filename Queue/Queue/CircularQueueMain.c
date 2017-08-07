#include <stdio.h>
#include "ListBaseQueue.h"

int main()
{
	Queue q;
	QueueInit(&q);

	Enqueue(&q, 1), Enqueue(&q, 2);
	Enqueue(&q, 3), Enqueue(&q, 4);
	Enqueue(&q, 5);

	while (!QIsEmpty(&q))
		printf("%d ",Dequeue(&q));

	Enqueue(&q, 6), Enqueue(&q, 7);
	Enqueue(&q, 8), Enqueue(&q, 9);
	Enqueue(&q, 10);

	while (!QIsEmpty(&q))
		printf("%d ", Dequeue(&q));
	return 0;
}