#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ExpressionTree.h"
#include "BinaryTree2.h"
#include "ListBaseStack.h"

BTreeNode * MakeExpTree(char exp[])
{
	BTreeNode* pnode;
	Stack stack;
	StackInit(&stack);

	int len = strlen(exp);
	int i;
	char tok;
	for (i = 0; i < len; i++)
	{
		pnode = MakeBTreeNode();
		tok = exp[i];
		if (isdigit(tok))
		{
			SetData(pnode, tok - '0');
		}
		else
		{
			SetData(pnode, tok);
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
		}
		SPush(&stack, pnode);
	}
	return SPop(&stack);
}

int EvaluateExpTree(BTreeNode * bt)
{
	int val1, val2;
	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt);
	char tok;
	val1 = EvaluateExpTree(GetLeftSubTree(bt));
	val2 = EvaluateExpTree(GetRightSubTree(bt));
	tok = GetData(bt);
	switch (tok)
	{
	case '+' :
		return val1 + val2;
		break;
	case '-':
		return val1 - val2;
		break;
	case '*':
		return val1 * val2;
		break;
	case '/':
		return val1 / val2;
		break;
	}
	return 0;
}

void ShowNodeData(int data)
{
	if (0 <= data && data <= 9)
		printf("%d", data);//피연산자
	else
		printf("%c", data);//연산자
}

void ShowPrefixTypeExp(BTreeNode * bt)
{
	PreorderTraverse(bt, ShowNodeData);
}
void ShowInfixTypeExp(BTreeNode * bt)
{
	if (bt == NULL)
		return;
	if (bt->left != NULL || bt->right != NULL)
		printf("(");
	ShowInfixTypeExp(bt->left);
	ShowNodeData(bt->data);
	ShowInfixTypeExp(bt->right);
	if (bt->left != NULL || bt->right != NULL)
		printf(")");
}
void ShowPostfixTypeExp(BTreeNode * bt)
{
	PostorderTraverse(bt, ShowNodeData);
}
