#include <stdio.h>
#include "BinarySearchTree.h"

int main()
{
	BTreeNode * bstRoot;
	BTreeNode * sNode;

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 5);

	sNode = BSTSearch(bstRoot, 1);
	if (sNode == NULL)
		printf("Ž�� ���� \n");
	else
		printf("Ž���� ������ Ű�� ��: %d \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 10);
	if (sNode == NULL)
		printf("Ž�� ���� \n");
	else
		printf("Ž���� ������ Ű�� ��: %d \n", BSTGetNodeData(sNode));

	return 0;
}