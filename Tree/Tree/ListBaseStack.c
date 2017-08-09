#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack)
{
	pstack->head = NULL;
}
int SIsEmpty(Stack *pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	return FALSE;
}

void SPush(Stack *pstack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pstack->head;
	pstack->head = newNode;
}
Data SPop(Stack *pstack)
{
	Node* tmp = pstack->head;
	Data tdata = tmp->data;
	if (SIsEmpty(pstack))
	{
		printf("데이터가 없습니다.");
		exit(-1);
	}
	pstack->head = tmp->next;
	free(tmp);
	return tdata;
}
Data SPeek(Stack * pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("데이터가 없습니다.");
		exit(-1);
	}
	return pstack->head->data;
}