#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist) {
	plist->numOfData = 0;
	plist->curPosition = -1;
}

void LInsert(List * plist, LData data) {
	if (plist->numOfData >= 100) {
		puts("������ �Ұ����մϴ�.");
		return;
	}
	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}
int LFirst(List * plist, LData * data) {
	if (plist->numOfData == 0) //����� �����Ͱ� �ϳ��� ���ٸ�
		return FALSE;
	plist->curPosition = 0; //������ġ �ʱ�ȭ
	*data = plist->arr[0];
	return TRUE;
}

int LNext(List * plist, LData * pdata) {
	if (plist->numOfData <= (plist->curPosition) + 1)
		return FALSE;
	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List * plist) {
	int spos = plist->curPosition;
	int lpos = (plist->numOfData)-1;
	LData data = plist->arr[spos]; // �����Ϸ��� ������ �ӽ�����(��ȯ��)
	for (int i = spos; i < lpos; i++)
		plist->arr[i] = plist->arr[i + 1];
	(plist->curPosition)--;
	(plist->numOfData)--;
	return data;
}
int LCount(List * plist) {
	return plist->numOfData;
}