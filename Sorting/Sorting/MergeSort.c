#include <stdio.h>
#include <stdlib.h>
void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int lidx = left;
	int ridx = mid+1;

	int* sortArr = (int*)malloc(sizeof(int)*(right + 1));
	int sidx = left;
	//�������� ���Ľ�Ű����
	//�� �� �ϳ��� ���� ���Ŀ� ��� ����.
	while (lidx <= mid && ridx <= right)
	{
		if (arr[lidx] > arr[ridx])
			sortArr[sidx] = arr[ridx++];
		else
			sortArr[sidx] = arr[lidx++];
		sidx++;
	}
	//���� �ٸ� �� �迭 ó�� 
	if (lidx > mid)
	{
		for (int i = ridx; i <= right; i++)
			sortArr[sidx++] = arr[i];
	}
	else
	{
		for (int i = lidx; i <= mid; i++)
			sortArr[sidx++] = arr[i];
	}
	for (int i = left; i <= right; i++)
		arr[i] = sortArr[i];
	free(sortArr);

}
void MergeSort(int arr[], int left, int right)
{
	if (left == right)
		return;
	int mid = (left+right)/2;
	MergeSort(arr, left, mid);
	MergeSort(arr, mid + 1, right);

	MergeTwoArea(arr, left, mid, right);
}


int main()
{
	int arr[7] = { 3,2,4,1,7,6,5 };

	MergeSort(arr, 0, (sizeof(arr) / sizeof(int))-1);

	for (int i = 0; i < 7; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}