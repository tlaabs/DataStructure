#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree2.h"

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
			MakeRightSubTree(pNode, nNode);
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

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
	//타겟과 타겟의 부모 주소를 얻기
	//삭제대상이 루트인 경우를 별도로 고려
	BTreeNode* pVRoot = MakeBTreeNode();//가상 루트 만들기
	BTreeNode* pNode = pVRoot;
	BTreeNode* cNode = *pRoot;
	BTreeNode* dNode = NULL;
	

	ChangeRightSubTree(pVRoot, *pRoot);

	//삭제 노드 찾기
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

	//삭제노드가 단말 노드인 경우
	if (GetRightSubTree(dNode) == NULL && GetLeftSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}
	//삭제노드가 한개의 노드를 가진 경우
	else if (GetRightSubTree(dNode) == NULL || GetLeftSubTree(dNode) == NULL)
	{
		BTreeNode * dcNode; //삭제대상의 자식 노드
		
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
	//두개
	else
	{
		//대체 노드
		BTreeNode* mNode = GetRightSubTree(dNode);
		//대체 노드의 부모
		BTreeNode* mpNode = dNode;
		int delData;
		//대체 노드 찾기
		while(GetLeftSubTree(mNode) != NULL)
		{
			mpNode = dNode;
			mNode = GetLeftSubTree(mNode);
		}
		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));
		//대체 노드의 부모 노드와 자식 노드 연결
		if (GetLeftSubTree(mpNode) == mNode)
		{
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		}
		//한줄 나란히
		else
		{
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
		}

		dNode = mNode;
		SetData(dNode, delData); //백업 데이터 복원
	}

	//루트 노드가 삭제된 경우에 대한 처리
	if (GetRightSubTree(pVRoot) != *pRoot)
	{
		*pRoot = GetRightSubTree(pVRoot);
	}
	//가상 루트 제거
	free(pVRoot);

	//사실상 free할 노드의 주소는 대체주소와 같다.
	return dNode;
}

//이진 탐색 트리에 저장된 모든 노드의 데이터 출력
void ShowIntData(int data)
{
	printf("%d ", data);
}
void BSTShowAll(BTreeNode * bst)
{
	InorderTraverse(bst, ShowIntData);
}