#include "InfixToPostfix.h"
#include "ListBaseStack.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//�������� �켱������ ��ȯ
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
//�������� �켱���� ��
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
	Stack stack;//������ ����
	int expLen = strlen(exp);
	char* convExp = (char*)malloc(expLen+1);//��ȯ���� ���� �迭

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
				//tok�� ���ð� ��������� ���ų� ���ٸ�
				//������ ���� �� ���� ��������
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack);

				SPush(&stack, tok);
				break;

			}
		}
	}
	//���� ��� ��������
	while (!SIsEmpty(&stack))
		convExp[idx++] = SPop(&stack);

	strcpy(exp, convExp);
	free(convExp);
}