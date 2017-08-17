#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphBFS.h"
#include "CircularQueue.h"
#include "DLinkedList.h"

int WhoIsPrecede(int data1, int data2);
void GraphInit(ALGraph * pg, int nv)
{
	pg->numV = nv;
	pg->numE = 0;
	pg->adjList = (List*)malloc(sizeof(List) * nv);

	for (int i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&pg->adjList[i], WhoIsPrecede);
	}

	pg->visitInfo = (int*)malloc(sizeof(int)* pg->numV);
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}
void GraphDestroy(ALGraph * pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);
	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}

void AddEdge(ALGraph * pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph * pg)
{
	int data;
	for (int i = 0; i < pg->numV; i++)
	{
		printf("%c�� ����� ����: ", 'A' + i);
		if (LFirst(&(pg->adjList[i]), &data))
		{
			printf("%c ", 'A' + data);
			while (LNext(&(pg->adjList[i]), &data))
			{
				printf("%c ", 'A' + data);
			}
		}
		printf("\n");
	}
}

int VisitVertex(ALGraph * pg, int visitV)
{
	//�̹湮 ����
	if (pg->visitInfo[visitV] == 0)
	{
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 'A');
		return TRUE;
	}
	return FALSE;
}

void BFShowGraphVertext(ALGraph * pg, int startV)
{
	Queue queue;

	int visitV = startV;
	int nextV;

	QueueInit(&queue);
	//VisitVertex(pg, visitV); // ���� �� �湮


		//���� ��� �ϳ��� �����鼭 �������� ���� vertex�� ã��
		while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
		{
			if (VisitVertex(pg, nextV) == TRUE)
				Enqueue(&queue, nextV);
			//����� ��带 ��� Ž���غ�
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if (VisitVertex(pg, nextV) == TRUE)
					Enqueue(&queue, nextV);
			}

			if (QIsEmpty(&queue) == TRUE)
				break;
			else
				visitV = Dequeue(&queue);
		}

	//���� Ž���� ���� ���� �ʱ�ȭ
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}
