#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphKruskal.h"
#include "ArrayBaseStack.h"
#include "DLinkedList.h"

int WhoIsPrecede(int data1, int data2);
int PQWeightComp(Edge d1, Edge d2);

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

	PQueueInit(&(pg->pqueue), PQWeightComp);
}

int WhoIsPrecede(int data1, int data2)
{
	if (data1 > data2)
		return 0;
	else
		return 1;
}
int PQWeightComp(Edge d1, Edge d2)
{
	return d2.weight - d1.weight;
}

void GraphDestroy(ALGraph * pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);
	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}

void AddEdge(ALGraph * pg, int fromV, int toV, int weight)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	Edge eg = { fromV,toV,weight };
	PEnqueue(&(pg->pqueue), eg);
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

void DFShowGraphVertext(ALGraph * pg, int startV)
{
	Stack stack;

	int visitV = startV;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV); // 시작 점 방문
	SPush(&stack, visitV);


	//인접 노드 하나씩 꺼내면서 지나가지 않은 vertex를 찾기
	while (LFirst(&(pg->adjList[visitV]), &nextV))
	{
		int visitFlag = FALSE;
		//찾음
		if (VisitVertex(pg, nextV) == TRUE)
		{
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		//인접하지만 이미 지나간 vertex 라면
		else
		{
			//연결된 모드를 모두 탐색해봄
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if (VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}
		//주변의 모든 사람들이 연락을 받았다면
		if (visitFlag == FALSE)
		{
			if (SIsEmpty(&stack) == TRUE)
				break;
			else
				visitV = SPop(&stack);
		}

	}

	//이후 탐색을 위해 정보 초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void RemoveEdge(ALGraph * pg, int fromV, int toV)
{
	int edge;
	if (LFirst(&(pg->adjList[fromV]), &edge) == TRUE)
	{
		if (edge == toV)
		{
			LRemove(&(pg->adjList[fromV]));
			return;
		}
		while (LNext(&(pg->adjList[fromV]), &edge) == TRUE)
		{
			if (edge == toV)
			{
				LRemove(&(pg->adjList[fromV]));
				return;
			}
		}
	}
}
void ConKruskalMST(ALGraph * pg) //최소 비용 신장 트리의 구성
{
	Edge mainEdge[20];
	Edge eg;
	int mainIdx = 0;
	//MST 완성 조건
	while (pg->numE +1 > pg->numV)
	{
		//큐에서 데이터 꺼내기
		eg = PDequeue(&pg->pqueue);
		/*printf("eg : %d %D", eg.weight);*/
		//삭제시 고립 노드 발생한다면
		if (LCount(&pg->adjList[eg.v1]) == 1 || LCount(&pg->adjList[eg.v2]) == 1)
		{
			//MST를 이루는 간선이기에 저장
			mainEdge[mainIdx++] = eg;
			continue;
		}
		else //간선삭제
		{
			RemoveEdge(pg, eg.v1, eg.v2);
			RemoveEdge(pg, eg.v2, eg.v1);
			(pg->numE)--;
		}
	}
	for (int i = 0; i < mainIdx; i++)
	{
		PEnqueue(&pg->pqueue, mainEdge[i]);
	}
	//간선회복 - 간선의 가중치 정보 출력을 위해
}

void ShowGraphEdgeWeightInfo(ALGraph * pg) //가중치 정보 출력
{
	Edge edge;
	while (!PQIsEmpty(&pg->pqueue))
	{
		edge = PDequeue(&pg->pqueue);
		printf("(%c-%c), w:%d \n", edge.v1 + 65, edge.v2 + 65, edge.weight);
	}

}