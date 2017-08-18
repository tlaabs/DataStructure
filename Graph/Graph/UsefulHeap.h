#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

#include "ALEdge.h"
typedef Edge HData;
typedef int PriorityComp(HData d1, HData d2);

//typedef struct _heapElem {
//	Priority pr;
//	HData data;
//}HeapElem;

typedef struct _heap
{
	PriorityComp * comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap * ph, PriorityComp pc);
int HIsEmpty(Heap * ph);

void HInsert(Heap * ph, HData data);
HData HDelete(Heap * ph);


#endif