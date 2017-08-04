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

typedef LinkedList List; // main함수를 변경하지 않고도 다른 리스트로 교체할 수 있다.

void ListInit(List * plist);
void LInsert(List * plist, LData data);
/* return int
1 :  데이터 반환 성공
0 : 저장된 데이터가 하나도 없음
*/
int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);
//메모리 소멸의 기회를 줄 수 있도록 반환
LData LRemove(List * plist);
int LCount(List * plist);

void SetSortRule(List * plist, int(*comp)(LData d1, LData d2));

#endif