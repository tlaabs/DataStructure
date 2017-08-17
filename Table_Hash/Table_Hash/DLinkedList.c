#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist) 
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->tail = plist->head;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
	plist->comp = NULL;
}
void FInsert(List* plist,LData data) { //헤더에 정의되지 않은 함수
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	plist->tail->next = newNode;
	plist->tail = newNode;

	(plist->numOfData)++;
}
void SInsert(List* plist, LData data) { //헤더에 정의되지 않은 함수
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	Node * pred = plist->head; //더미 노드
	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}
	newNode->next = pred->next;
	pred->next = newNode;

	if (newNode->next == NULL)//꼬리
		plist->tail = newNode;

	(plist->numOfData)++;
}
void LInsert(List * plist, LData data) 
{
	if (plist->comp == NULL)//정렬기준이 없으면
		FInsert(plist, data);
	else//정렬기준에 근거하여 노드 추가
		SInsert(plist, data);
}
/* return int
1 :  데이터 반환 성공
0 : 저장된 데이터가 하나도 없음
*/
int LFirst(List * plist, LData * pdata)
{
	if (plist->head == plist->tail)
		return FALSE;

	plist->before = plist->head; //더미노드 가리킴
	plist->cur = plist->head->next; //더미 다음 노드(진정한 첫번째 노드)

	*pdata = plist->cur->data;
	return TRUE;
}
int LNext(List * plist, LData * pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}
//메모리 소멸의 기회를 줄 수 있도록 반환
LData LRemove(List * plist)
{
	Node* tmp = plist->cur;
	LData rdata = tmp->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(tmp);
	(plist->numOfData)--;
	return rdata;

}
int LCount(List * plist)
{
	return plist->numOfData;
}

void SetSortRule(List * plist, int(*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}