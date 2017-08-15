#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

//노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

//데이터 저장(노드의 생성과정 포함)
void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	BTreeNode * pNode = NULL; //parent
	BTreeNode * cNode = *pRoot; //current
	BTreeNode * nNode = NULL;

	//새로운 노드가 삽입될 위치 탐색
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

	//새로운 노드 생성
	nNode = MakeBTreeNode();
	SetData(nNode, data);

	//부착
	//아무노드도 없을 때
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

//데이터 탐색
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