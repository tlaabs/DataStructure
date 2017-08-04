#include <stdio.h>
#include "DLinkedList.h"
int WhoIsPrecede(int d1, int d2)
{
	if (d1 < d2)
		return 0;//d1이 정렬 순서상 앞선다.
	else
		return 1;
}
int main() {
	//List의 생성 및 초기화
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);
	//삽입
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22), LInsert(&list, 22);
	LInsert(&list, 33);

	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data))//첫 번째 데이터 조회
	{
		printf("%d ", data);

		while (LNext(&list, &data))//계속 조회
			printf("%d ", data);
	}
	printf("\n\n");

	// 숫자 22를 탐색하여 모두 삭제
	if (LFirst(&list, &data))//첫 번째 데이터 조회
	{
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))//계속 조회
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	//삭제 후 남은 데이터 출력
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data))//첫 번째 데이터 조회
	{
		printf("%d ", data);

		while (LNext(&list, &data))//계속 조회
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}