#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE  1
#define FALSE 0

#define LIST_LEN 100
typedef int LData;

typedef struct array_list {
	LData arr[LIST_LEN]; //배열 기반 리스트
	int numOfData; //데이터 수
	int curPosition; //데이터 참조 위치
}ArrayList;

typedef ArrayList List; // main함수를 변경하지 않고도 다른 리스트로 교체할 수 있다.

void ListInit(List * plist);
void LInsert(List * plist, LData data);
/* return int
1 :  데이터 반환 성공
0 : 저장된 데이터가 하나도 없음
*/
int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);
LData LRemove(List * plist);
int LCount(List * plist);

#endif