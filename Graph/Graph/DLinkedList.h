#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE  1
#define FALSE 0

typedef int LData;

typedef struct _node {
	LData data;
	struct _node * next;
}Node;

typedef struct _linkedList {
	Node * head;
	Node * tail;
	Node * cur;
	Node * before;
	int numOfData;
	int (*comp)(LData d1, LData d2);
}LinkedList;

typedef LinkedList List; // main�Լ��� �������� �ʰ� �ٸ� ����Ʈ�� ��ü�� �� �ִ�.

void ListInit(List * plist);
void LInsert(List * plist, LData data);
/* return int
1 :  ������ ��ȯ ����
0 : ����� �����Ͱ� �ϳ��� ����
*/
int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);
//�޸� �Ҹ��� ��ȸ�� �� �� �ֵ��� ��ȯ
LData LRemove(List * plist);
int LCount(List * plist);

void SetSortRule(List * plist, int(*comp)(LData d1, LData d2));

#endif