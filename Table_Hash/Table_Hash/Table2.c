#include <stdio.h>
#include <stdlib.h>
#include "Table2.h"
#include "DLinkedList.h"

void TBLInit(Table * pt, HashFunc * f)
{
	for (int i = 0; i < MAX_TBL; i++)
		ListInit(&(pt->tbl[i]));

	pt->hf = f;
}

void TBLInsert(Table * pt, Key k, Value v)
{
	int hv = pt->hf(k);
	Slot sData = { k,v };
	//키 중복 확인
	if (TBLSearch(pt, k) != NULL)
	{
		printf("키 중복 오류 발생 \n");
		return;
	}
	else
	{
		LInsert(&pt->tbl[hv], sData);
	}
}

Value TBLDelete(Table * pt, Key k)
{
	int hv = pt->hf(k);
	Slot cSlot;
	//
	if (LFirst(&pt->tbl[hv], &cSlot))
	{
		//찾으면
		if (cSlot.key == k)
		{
			cSlot = LRemove(&pt->tbl[hv]);
			return cSlot.val;
		}
		else
		{
			while (LNext(&pt->tbl[hv], &cSlot))
			{
				if (cSlot.key == k)
				{
					cSlot = LRemove(&pt->tbl[hv]);
					return cSlot.val;
				}
			}
		}
	}
	return NULL;
}
Value TBLSearch(Table * pt, Key k)
{
	int hv = pt->hf(k);
	Slot cSlot;
	//
	if (LFirst(&pt->tbl[hv], &cSlot))
	{
		//찾으면
		if (cSlot.key == k)
			return cSlot.val;
		else
		{
			while (LNext(&pt->tbl[hv], &cSlot))
			{
				if (cSlot.key == k)
					return cSlot.val;
			}
		}
	}
	return NULL;
}