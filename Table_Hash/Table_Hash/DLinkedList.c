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
void FInsert(List* plist,LData data) { //����� ���ǵ��� ���� �Լ�
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	plist->tail->next = newNode;
	plist->tail = newNode;

	(plist->numOfData)++;
}
void SInsert(List* plist, LData data) { //����� ���ǵ��� ���� �Լ�
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	Node * pred = plist->head; //���� ���
	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}
	newNode->next = pred->next;
	pred->next = newNode;

	if (newNode->next == NULL)//����
		plist->tail = newNode;

	(plist->numOfData)++;
}
void LInsert(List * plist, LData data) 
{
	if (plist->comp == NULL)//���ı����� ������
		FInsert(plist, data);
	else//���ı��ؿ� �ٰ��Ͽ� ��� �߰�
		SInsert(plist, data);
}
/* return int
1 :  ������ ��ȯ ����
0 : ����� �����Ͱ� �ϳ��� ����
*/
int LFirst(List * plist, LData * pdata)
{
	if (plist->head == plist->tail)
		return FALSE;

	plist->before = plist->head; //���̳�� ����Ŵ
	plist->cur = plist->head->next; //���� ���� ���(������ ù��° ���)

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
//�޸� �Ҹ��� ��ȸ�� �� �� �ֵ��� ��ȯ
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