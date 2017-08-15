#ifndef __BINARY_SEARCH_TREE2_H__
#define __BINARY_SEARCH_TREE2_H__
#include "BinaryTree3.h"

typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode ** pRoot);

//노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode * bst);

//데이터 저장(노드의 생성과정 포함)
void BSTInsert(BTreeNode ** pRoot, BSTData data);

//데이터 탐색
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target);

//이진 탐색 트리에 저장된 모든 노드의 데이터 출력
void BSTShowAll(BTreeNode * bst);
#endif