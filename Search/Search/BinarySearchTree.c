#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

//��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

//������ ����(����� �������� ����)
void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	BTreeNode * pNode = NULL; //parent
	BTreeNode * cNode = *pRoot; //current
	BTreeNode * nNode = NULL;

	//���ο� ��尡 ���Ե� ��ġ Ž��
	while (cNode != NULL)
	{
		if (GetData(cNode) == data)
			return;

		pNode = cNode;

		if (GetData(cNode) < data)
		{
			cNode = GetRightSubTree(cNode);
		}
		else
		{
			cNode = GetLeftSubTree(cNode);
		}
	}

	//���ο� ��� ����
	nNode = MakeBTreeNode();
	SetData(nNode, data);

	//����
	//�ƹ���嵵 ���� ��
	if (pNode == NULL)
	{
		*pRoot = nNode;
	}
	else
	{
		if (GetData(pNode) < data)
		{
			MakeRightSubTree(pNode,nNode);
		}
		else
		{
			MakeLeftSubTree(pNode, nNode);
		}
	}
	
}

//������ Ž��
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
	BTreeNode * cNode = bst;
	while (cNode != NULL)
	{
		if (GetData(cNode) == target)
			return cNode;
		if (GetData(cNode) < target)
			cNode = GetRightSubTree(cNode);
		else
			cNode = GetLeftSubTree(cNode);
	}
	return NULL;
}