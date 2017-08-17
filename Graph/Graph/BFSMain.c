#include <stdio.h>
#include "ALGraphBFS.h"

int main()
{
	ALGraph graph;
	GraphInit(&graph, 7);

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, D, C);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, F);
	AddEdge(&graph, E, G);

	ShowGraphEdgeInfo(&graph);

	BFShowGraphVertext(&graph, A); printf("\n");
	BFShowGraphVertext(&graph, C); printf("\n");
	BFShowGraphVertext(&graph, E); printf("\n");
	BFShowGraphVertext(&graph, G); printf("\n");
	GraphDestroy(&graph);

	return 0;
}