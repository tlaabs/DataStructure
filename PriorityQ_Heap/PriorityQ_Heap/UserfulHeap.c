#include <stdio.h>
#include <stdlib.h>
#include "UsefulHeap.h"

void HeapInit(Heap * ph, PriorityComp pc)
{
	ph->numOfData = 0;
	ph->comp = pc;
}
int HIsEmpty(Heap * ph)
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx)
{
	return idx / 2;
}

int GetLChildIdx(int idx)
{
	return idx * 2;
}

int GetRChildIdx(int idx)
{
	return GetLChildIdx(idx) + 1;
}


void HInsert(Heap * ph, HData data)
{
	int idx = (ph->numOfData) + 1;
	//HeapElem newElem = { pr,data };

	while (idx != 1)
	{
		int parentIDX = GetParentIDX(idx);
		/*if (pr < ph->heapArr[parentIDX].pr)*/
		if(ph->comp(data, ph->heapArr[parentIDX]) < 0)
		{
			ph->heapArr[idx] = ph->heapArr[parentIDX];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}
	/*ph->heapArr[idx] = newElem;*/
	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}
//�� ���� �ڽ� ��� �� ���� �켱���� �ڽ� ��� �ε��� ��ȯ
int GetHiPriChildIdx(Heap * ph, int idx)
{
	//�������� �ʴ� ��� �˻� ��
	if (GetLChildIdx(idx) > ph->numOfData)
		return 0;
	//���� ��常 �ְ� ������ ���� ���� ��
	else if (GetLChildIdx(idx) == ph->numOfData)
		return GetLChildIdx(idx);
	else
	{
		/*if (ph->heapArr[GetLChildIdx(idx)].pr >
			ph->heapArr[GetRChildIdx(idx)].pr)*/
		if(ph->comp(ph->heapArr[GetLChildIdx(idx)], ph->heapArr[GetRChildIdx(idx)]) > 0)
			return GetRChildIdx(idx);
		else
			return GetLChildIdx(idx);
	}
}
HData HDelete(Heap * ph)
{
	HData retData = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;
	while (childIdx = GetHiPriChildIdx(ph, parentIdx))
	{
		//swap
		/*if (lastElem.pr <= ph->heapArr[childIdx].pr)*/
		if(ph->comp(lastElem,ph->heapArr[childIdx]) <= 0)
			break;
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;

	}
	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;
}