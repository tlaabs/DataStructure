#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack * pstack)
{
	pstack->topIndex = -1;
}
int SIsEmpty(Stack *pstack)
{
	if (pstack->topIndex < 0)
		return TRUE;
	return FALSE;
}

void SPush(Stack *pstack, Data data)
{
	if (pstack->topIndex >= STACK_LEN - 1)
	{
		printf("꽉 찼습니다.");
		return;
	}
	pstack->stackArr[++(pstack->topIndex)] = data;
}
Data SPop(Stack *pstack)
{
	if (SIsEmpty(pstack) == TRUE)
	{
		printf("자료가 없습니다.");
		exit(-1);
	}
	return pstack->stackArr[(pstack->topIndex)--];
}
Data SPeek(Stack * pstack)
{
	if (SIsEmpty(pstack) == TRUE)
	{
		printf("자료가 없습니다.");
		exit(-1);
	}
	return pstack->stackArr[(pstack->topIndex)];
}