#include <stdio.h>
#include "ArrayList.h"

int main() {
	//List�� ���� �� �ʱ�ȭ
	List list;
	Point comPos;
	Point * ppos;
	
	ListInit(&list);

	//����
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))//ù ��° ������ ��ȸ
	{
		ShowPointPos(ppos);

		while (LNext(&list,&ppos))//��� ��ȸ
			ShowPointPos(ppos);
	}
	printf("\n\n");

	//xpos�� 2�� ��� ������ ����
	comPos.xpos = 2;
	comPos.ypos = 0;
	if (LFirst(&list, &ppos))//ù ��° ������ ��ȸ
	{
		if (PointComp(&comPos, ppos) == 1)
		{
			ppos = LRemove(&list);
			free(ppos);//�޸� ���� ��ȯ ���־����
		}

		while (LNext(&list, &ppos))//��� ��ȸ
		{
			if (PointComp(&comPos, ppos) == 1)
			{
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}

	//���� �� ���� ������ ���
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))//ù ��° ������ ��ȸ
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))//��� ��ȸ
			ShowPointPos(ppos);
	}
	printf("\n\n");
	return 0;
}