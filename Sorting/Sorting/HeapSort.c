#include <stdio.h>
#include "UsefulHeap.h"
int PriComp(int n1, int n2)
{
	return n1 - n2;//오름차순,MinHeap

}
void HeapSort(int arr[], int n, PriorityComp pc)
{
	Heap heap;
	HeapInit(&heap, pc);

	for (int i = 0; i < n; i++)
		HInsert(&heap, arr[i]);
	for (int i = 0; i < n; i++)
		arr[i] = HDelete(&heap);
}
int main()
{
	int arr[4] = { 3,2,4,1 };
	int i;
	HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);

	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}