#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree2.h"

//���� ǥ����� ������ �޾Ƽ� ���� Ʈ���� ������ �׸���
//�� ����Ʈ���� ��Ʈ ��� �ּҰ��� ��ȯ
BTreeNode * MakeExpTree(char exp[]);
//���ڷ� ���޵� ����Ʈ���� �޾Ƽ� ��� ��ȯ
int EvaluateExpTree(BTreeNode * bt);
//���� Ʈ���� ������ �����ϱ� ���� �Լ�
// ����Ʈ���� ������ ����, ����, ���� ǥ������� �����
void ShowPrefixTypeExp(BTreeNode * bt);
void ShowInfixTypeExp(BTreeNode * bt);
void ShowPostfixTypeExp(BTreeNode * bt);

#endif