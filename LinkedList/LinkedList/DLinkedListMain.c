#include <stdio.h>
#include "DLinkedList.h"
int WhoIsPrecede(int d1, int d2)
{
	if (d1 < d2)
		return 0;//d1�� ���� ������ �ռ���.
	else
		return 1;
}
int main() {
	//List�� ���� �� �ʱ�ȭ
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);
	//����
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22), LInsert(&list, 22);
	LInsert(&list, 33);

	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &data))//ù ��° ������ ��ȸ
	{
		printf("%d ", data);

		while (LNext(&list, &data))//��� ��ȸ
			printf("%d ", data);
	}
	printf("\n\n");

	// ���� 22�� Ž���Ͽ� ��� ����
	if (LFirst(&list, &data))//ù ��° ������ ��ȸ
	{
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))//��� ��ȸ
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	//���� �� ���� ������ ���
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &data))//ù ��° ������ ��ȸ
	{
		printf("%d ", data);

		while (LNext(&list, &data))//��� ��ȸ
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}