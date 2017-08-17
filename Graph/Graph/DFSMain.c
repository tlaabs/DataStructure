#include <stdio.h>
#include "ALGraphDFS.h"

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

	//DFShowGraphVertext(&graph, A); printf("\n");
	//DFShowGraphVertext(&graph, C); printf("\n");
	DFShowGraphVertext(&graph, E); printf("\n");
	//DFShowGraphVertext(&graph, G); printf("\n");
	GraphDestroy(&graph);

	return 0;
}