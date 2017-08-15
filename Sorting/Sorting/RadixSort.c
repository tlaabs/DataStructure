#include <stdio.h>
#include "ListBaseQueue.h"
#define BUCKET_NUM 10
void RadixSort(int arr[], int len, int maxLen)
{
	Queue buckets[BUCKET_NUM];
	for (int i = 0; i < BUCKET_NUM; i++)
		QueueInit(&buckets[i]);

	int ten = 1;
	for (int i = 0; i < maxLen; i++)
	{
		//버킷에 데이터 저장
		for (int k = 0; k < len; k++)
		{
			int buckIdx = (arr[k] / ten) % 10;
			Enqueue(&buckets[buckIdx], arr[k]);
		}
		//...

		//버킷 데이터 확인
		int arridx = 0;
		for (int j = 0; j < BUCKET_NUM; j++)
		{
			//버켓에 데이터가 존재하면
			while (!QIsEmpty(&buckets[j]))
			{
				int data = Dequeue(&buckets[j]);
				arr[arridx++] = data;
			}
		}
		ten *= 10;
	}
}
int main()
{
	int arr[7] = { 13,212,14,7141,10987,6,15 };
	int len = sizeof(arr) / sizeof(int);
	int i;

	RadixSort(arr, len, 5);

	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}