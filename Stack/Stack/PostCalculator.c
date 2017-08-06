#include "string.h"
#include "ctype.h"
#include "PostCalculator.h"
#include "ListBaseStack.h"

int EvalRPNExp(char exp[])
{
	Stack stack;
	StackInit(&stack);
	int len = strlen(exp);
	int i = 0;
	char tok, pop1, pop2;
	while (i < len)
	{
		tok = exp[i];
		if (isdigit(tok))
		{
			SPush(&stack, tok - '0');
		}
		else
		{
			pop1 = SPop(&stack), pop2 = SPop(&stack);
			printf("[ : %d %d\n", pop1, pop2);
			switch (tok)
			{
			case '+':
				SPush(&stack,pop1 + pop2);
				break;
			case '-':
				SPush(&stack,pop1 - pop2);
				break;
			case '*':
				SPush(&stack,pop1 * pop2);
				break;
			case '/':
				SPush(&stack,pop2 / pop1);
				break;
			}
		}
		i++;
	}
	return SPop(&stack);
}