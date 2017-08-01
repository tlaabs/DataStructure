#include <stdio.h>
#include "ArrayList.h"

int main() {
	//List의 생성 및 초기화
	List list;
	Point comPos;
	Point * ppos;
	
	ListInit(&list);

	//삽입
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))//첫 번째 데이터 조회
	{
		ShowPointPos(ppos);

		while (LNext(&list,&ppos))//계속 조회
			ShowPointPos(ppos);
	}
	printf("\n\n");

	//xpos가 2인 모든 데이터 삭제
	comPos.xpos = 2;
	comPos.ypos = 0;
	if (LFirst(&list, &ppos))//첫 번째 데이터 조회
	{
		if (PointComp(&comPos, ppos) == 1)
		{
			ppos = LRemove(&list);
			free(ppos);//메모리 수동 반환 해주어야함
		}

		while (LNext(&list, &ppos))//계속 조회
		{
			if (PointComp(&comPos, ppos) == 1)
			{
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}

	//삭제 후 남은 데이터 출력
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))//첫 번째 데이터 조회
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))//계속 조회
			ShowPointPos(ppos);
	}
	printf("\n\n");
	return 0;
}