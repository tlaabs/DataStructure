#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__
#include "BinaryTree2.h"

typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode ** pRoot);

//��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode * bst);

//������ ����(����� �������� ����)
void BSTInsert(BTreeNode ** pRoot, BSTData data);

//������ Ž��
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);
#endif