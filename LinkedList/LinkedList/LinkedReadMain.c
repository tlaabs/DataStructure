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
		printf("�ڿ��� �Է�: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;
		
		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;//���� �ڿ� �߰�
		tail = newNode; //�ڽ��� ���ο� ������ ��
	}
	printf("\n");

	printf("�Է� ���� �������� ��ü���! \n");
	if (head == NULL)
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
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

	//�޸� ����
	if (head == NULL)
		return 0;
	else
	{
		Node* delNode = head;
		Node* nextDelNode = head->next;

		printf("%d��(��) �����մϴ�. \n", head->data);
		free(delNode);
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