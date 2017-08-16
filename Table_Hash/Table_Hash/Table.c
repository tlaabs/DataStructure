#include <stdio.h>
#include "Table.h"

void TBLInit(Table * pt, HashFunc * f)
{
	for (int i = 0; i < MAX_TBL; i++)
		(pt->tbl[i]).status = EMPTY;
	pt->hf = f;
}

void TBLInsert(Table * pt, Key k, Value v)
{
	int hv = pt->hf(k);
	pt->tbl[hv].key = k;
	pt->tbl[hv].val = v;
	pt->tbl[hv].status = INUSE;
}

Value TBLDelete(Table * pt, Key k)
{
	int hv = pt->hf(k);
	if (pt->tbl[hv].status == INUSE)
	{
		Value data = pt->tbl[hv].val;
		pt->tbl[hv].status = DELETED;
		return data;
	}
	else
		return NULL;
}
Value TBLSearch(Table * pt, Key k)
{
	int hv = pt->hf(k);
	if (pt->tbl[hv].status == INUSE)
		return pt->tbl[hv].val;
	else
		return NULL;
}