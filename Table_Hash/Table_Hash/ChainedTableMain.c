#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table2.h"

int MyHashFunc(int k)
{
	return k % 100;
}

int main()
{
	Table myTbl;
	Person * np;
	Person * sp;
	Person * rp;

	TBLInit(&myTbl, MyHashFunc);

	np = MakePersonData(20120003, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);
	np = MakePersonData(20130012, "KIM", "Jeju");
	TBLInsert(&myTbl, GetSSN(np), np);
	np = MakePersonData(20170049, "HAN", "Kangwon");
	TBLInsert(&myTbl, GetSSN(np), np);

	//탐색
	sp = TBLSearch(&myTbl, 20120003);
	if (sp != NULL)
		ShowPerInfo(sp);

	//삭제
	rp = TBLDelete(&myTbl, 20120003);
	if (rp != NULL)
	{
		free(rp);
		printf("삭제 완료\n");
	}
	return 0;
}