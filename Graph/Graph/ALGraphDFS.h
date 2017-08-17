#ifndef __AL_GRAPH_DFS__
#define __AL_GRAPH_DFS__

#include "DLinkedList.h"

enum {A,B,C,D,E,F,G,H,I,J};

typedef struct _ual
{
	int numV;
	int numE;
	List * adjList;
	int * visitInfo;
}ALGraph;

void GraphInit(ALGraph * pg, int nv);

void GraphDestroy(ALGraph * pg);

void AddEdge(ALGraph * pg, int fromV, int toV);

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg);

//정점의 정보 출력 : Depth Fist Search 기반
void DFShowGraphVertext(ALGraph * pg, int startV);
#endif