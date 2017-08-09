#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree2.h"

//후위 표기법의 수식을 받아서 수식 트리르 구성함 그리고
//그 수식트리의 루트 노드 주소값을 반환
BTreeNode * MakeExpTree(char exp[]);
//인자로 전달된 수식트리를 받아서 결과 반환
int EvaluateExpTree(BTreeNode * bt);
//수식 트리의 구성을 검증하기 위한 함수
// 수식트리의 수식을 전위, 중위, 후위 표기법으로 출력함
void ShowPrefixTypeExp(BTreeNode * bt);
void ShowInfixTypeExp(BTreeNode * bt);
void ShowPostfixTypeExp(BTreeNode * bt);

#endif