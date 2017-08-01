#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node * next;
}Node;

int main() {
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;
	Node* newNode = NULL;
	int readData;

	while (1) {
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;
		
		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;//꼬리 뒤에 추가
		tail = newNode; //자신이 새로운 꼬리가 됨
	}
	printf("\n");

	printf("입력 받은 데이터의 전체출력! \n");
	if (head == NULL)
		printf("저장된 자연수가 존재하지 않습니다. \n");
	else
	{
		cur = head;
		printf("%d ", cur->data);
		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n");

	//메모리 해제
	if (head == NULL)
		return 0;
	else
	{
		Node* delNode = head;
		Node* nextDelNode = head->next;

		printf("%d을(를) 삭제합니다. \n", head->data);
		free(delNode);
		while (nextDelNode != NULL)
		{
			delNode = nextDelNode;
			nextDelNode = nextDelNode->next;
			printf("%d을(를) 삭제합니다. \n", delNode->data);
			free(delNode);
		}
	}
	return 0;
}