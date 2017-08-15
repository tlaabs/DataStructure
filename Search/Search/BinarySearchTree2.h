#ifndef __BINARY_SEARCH_TREE2_H__
#define __BINARY_SEARCH_TREE2_H__
#include "BinaryTree3.h"

typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode ** pRoot);

//��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode * bst);

//������ ����(����� �������� ����)
void BSTInsert(BTreeNode ** pRoot, BSTData data);

//������ Ž��
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target);

//���� Ž�� Ʈ���� ����� ��� ����� ������ ���
void BSTShowAll(BTreeNode * bst);
#endif