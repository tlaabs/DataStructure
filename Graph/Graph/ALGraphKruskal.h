#ifndef __AL_GRAPH_KRUSKAL__
#define __AL_GRAPH_KRUSKAL__

#include "DLinkedList.h"
#include "PriorityQueue.h"
#include "ALEdge.h"

enum { A, B, C, D, E, F, G, H, I, J };

typedef struct _ual
{
	int numV;
	int numE;
	List * adjList;
	int * visitInfo;
	PQueue pqueue; // 간선의 가중치 정보 저장
}ALGraph;

void GraphInit(ALGraph * pg, int nv);

void GraphDestroy(ALGraph * pg);

void AddEdge(ALGraph * pg, int fromV, int toV, int weight);

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg);

//정점의 정보 출력 : Depth Fist Search 기반
void DFShowGraphVertext(ALGraph * pg, int startV);

//new add

void ConKruskalMST(ALGraph * pg); //최소 비용 신장 트리의 구성

void ShowGraphEdgeWeightInfo(ALGraph * pg); //가중치 정보 출력
#endif