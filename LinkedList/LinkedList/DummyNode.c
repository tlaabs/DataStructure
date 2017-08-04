#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node * next;
}Node;

int main() {
	Node* head = (Node*)malloc(sizeof(Node));
	Node* tail = head;
	Node* cur = NULL;
	Node* newNode = NULL;
	int readData;

	while (1) {
		printf("�ڿ��� �Է�: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;
		
		tail->next = newNode;
		tail = newNode;
	}
	printf("\n");

	printf("�Է� ���� �������� ��ü���! \n");
	if (head == tail)
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	else
	{
		cur = head;
		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n");

	//�޸� ����
	if (head == tail)
		return 0;
	else
	{
		Node* delNode;
		Node* nextDelNode = head->next;

		while (nextDelNode != NULL)
		{
			delNode = nextDelNode;
			nextDelNode = nextDelNode->next;
			printf("%d��(��) �����մϴ�. \n", delNode->data);
			free(delNode);
		}
	}
	return 0;
}