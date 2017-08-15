#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree2.h"

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
			MakeRightSubTree(pNode, nNode);
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

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
	//Ÿ�ٰ� Ÿ���� �θ� �ּҸ� ���
	//��������� ��Ʈ�� ��츦 ������ ���
	BTreeNode* pVRoot = MakeBTreeNode();//���� ��Ʈ �����
	BTreeNode* pNode = pVRoot;
	BTreeNode* cNode = *pRoot;
	BTreeNode* dNode = NULL;
	

	ChangeRightSubTree(pVRoot, *pRoot);

	//���� ��� ã��
	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;
		if (GetData(cNode) > target)
			cNode = GetLeftSubTree(cNode);
		else if (GetData(cNode) < target)
			cNode = GetRightSubTree(cNode);
	}
	
	if (cNode == NULL)
		return;
	dNode = cNode;

	//������尡 �ܸ� ����� ���
	if (GetRightSubTree(dNode) == NULL && GetLeftSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}
	//������尡 �Ѱ��� ��带 ���� ���
	else if (GetRightSubTree(dNode) == NULL || GetLeftSubTree(dNode) == NULL)
	{
		BTreeNode * dcNode; //��������� �ڽ� ���
		
		if (GetRightSubTree(dNode) == NULL)
		{
			dcNode = GetLeftSubTree(dNode);
		}
		else
			dcNode = GetRightSubTree(dNode);

		if (GetLeftSubTree(pNode) == dNode)
		{
			ChangeLeftSubTree(pNode, dcNode);
		}
		else
			ChangeRightSubTree(pNode, dcNode);
	}
	//�ΰ�
	else
	{
		//��ü ���
		BTreeNode* mNode = GetRightSubTree(dNode);
		//��ü ����� �θ�
		BTreeNode* mpNode = dNode;
		int delData;
		//��ü ��� ã��
		while(GetLeftSubTree(mNode) != NULL)
		{
			mpNode = dNode;
			mNode = GetLeftSubTree(mNode);
		}
		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));
		//��ü ����� �θ� ���� �ڽ� ��� ����
		if (GetLeftSubTree(mpNode) == mNode)
		{
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		}
		//���� ������
		else
		{
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
		}

		dNode = mNode;
		SetData(dNode, delData); //��� ������ ����
	}

	//��Ʈ ��尡 ������ ��쿡 ���� ó��
	if (GetRightSubTree(pVRoot) != *pRoot)
	{
		*pRoot = GetRightSubTree(pVRoot);
	}
	//���� ��Ʈ ����
	free(pVRoot);

	//��ǻ� free�� ����� �ּҴ� ��ü�ּҿ� ����.
	return dNode;
}

//���� Ž�� Ʈ���� ����� ��� ����� ������ ���
void ShowIntData(int data)
{
	printf("%d ", data);
}
void BSTShowAll(BTreeNode * bst)
{
	InorderTraverse(bst, ShowIntData);
}