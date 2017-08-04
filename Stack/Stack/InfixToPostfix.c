#include "InfixToPostfix.h"
#include "ListBaseStack.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//연산자의 우선순위를 반환
int GetOpPrec(char op)
{
	switch (op)
	{
	case '*':
	case '/':
		return 2;
		break;
	case '+':
	case '-':
		return 1;
		break;
	case '(':
		return 0;
	}
	return -1;
}
//연산자의 우선순위 비교
int WhoPrecOp(char op1, char op2)
{
	int val = GetOpPrec(op1) - GetOpPrec(op2);
	if (val > 0)
		return 1;
	else if (val < 0)
		return -1;
	return 0;
}

void ConvToRPNExp(char exp[])
{
	Stack stack;//연산자 스택
	int expLen = strlen(exp);
	char* convExp = (char*)malloc(expLen+1);//변환수식 저장 배열

	memset(convExp, 0, sizeof(char)*expLen + 1);
	StackInit(&stack);

	int i,idx = 0;
	char tok, popOp;
	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];
		if (isdigit(tok))
		{
			convExp[idx++] = tok;
		}
		else
		{
			switch (tok)
			{
			case '(':
				SPush(&stack, tok);
				break;
			case ')':
				while (1)
				{
					popOp = SPop(&stack);
					if (popOp == '(')
						break;
					convExp[idx++] = popOp;
				}
				break;
			case '+': case '-':
			case '/': case '*':
				//tok이 스택과 연산순위가 같거나 낮다면
				//높은게 나올 때 까지 내보내기
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack);

				SPush(&stack, tok);
				break;

			}
		}
	}
	//스택 모두 내보내기
	while (!SIsEmpty(&stack))
		convExp[idx++] = SPop(&stack);

	strcpy(exp, convExp);
	free(convExp);
}