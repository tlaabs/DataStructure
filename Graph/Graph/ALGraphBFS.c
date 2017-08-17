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
		printf("%c와 연결된 정점: ", 'A' + i);
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
	//미방문 상태
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
	//VisitVertex(pg, visitV); // 시작 점 방문


		//인접 노드 하나씩 꺼내면서 지나가지 않은 vertex를 찾기
		while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
		{
			if (VisitVertex(pg, nextV) == TRUE)
				Enqueue(&queue, nextV);
			//연결된 모드를 모두 탐색해봄
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

	//이후 탐색을 위해 정보 초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

