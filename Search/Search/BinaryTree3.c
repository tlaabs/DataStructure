#include <stdlib.h>
#include <stdio.h>
#include "BinaryTree3.h"

BTreeNode * MakeBTreeNode(void)
{
	BTreeNode * newNode = (BTreeNode *)malloc(sizeof(BTreeNode));
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
BTData GetData(BTreeNode * bt)
{
	return bt->data;
}
void SetData(BTreeNode * bt, BTData data)
{
	bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
	return bt->left;
}
BTreeNode * GetRightSubTree(BTreeNode * bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
	if (main->left != NULL)
		free(main->left);//순회가 필요함

	main->left = sub;
}
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;
	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);

}
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;
	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;
	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}

void DeleteTree(BTreeNode * bt)
{
	if (bt == NULL)
		return;
	DeleteTree(bt->left);
	DeleteTree(bt->right);
	printf("del : %d\n", bt->data);
	free(bt);

}

BTreeNode * RemoveLeftSubTree(BTreeNode * bt)
{
	BTreeNode* dNode = NULL;
	if (bt != NULL)
	{
		dNode = bt->left;
		bt->left = NULL;
	}
	return dNode;
}
BTreeNode * RemoveRightSubTree(BTreeNode * bt)
{
	BTreeNode* dNode = NULL;
	if (bt != NULL)
	{
		dNode = bt->right;
		bt->right = NULL;
	}
	return dNode;
}
//메모리의 소멸을 동반하지 않음
void ChangeLeftSubTree(BTreeNode * main, BTreeNode *sub)
{
	main->left = sub;
}
void ChangeRightSubTree(BTreeNode * main, BTreeNode *sub)
{
	main->right = sub;
}