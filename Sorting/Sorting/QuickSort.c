#include <stdio.h>
void swap(int * p1, int * p2)
{
	int tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void choiceMid(int arr[], int left, int right)
{
	int val1 = left;
	int val2 = (left + right) / 2;
	int val3 = right;
	//printf("%d %d %d\n", val1, val2, val3);
	int choice;
	if (arr[val2] <= arr[val1] && arr[val1] <= arr[val3])
		choice = val1;
	else if (arr[val1] <= arr[val2] && arr[val2] <= arr[val3])
		choice = val2;
	else
		choice = val3;
	swap(&arr[left], &arr[choice]);
}
int Partition(int arr[], int left, int right)
{
	int low, high, pivot;
	low = left + 1, high = right;
	choiceMid(arr, left, right);
	pivot = arr[left];

	printf("ÇÇ¹þ : %d \n", pivot);
	while (low <= high)
	{
		while (arr[low] <= pivot && low <= right) low++;
		while (arr[high] >= pivot && high >= (left+1)) high--;
		if (low <= high)
			swap(&arr[low], &arr[high]);
	}
	swap(&arr[high], &arr[left]);
	return high;
}

void QuickSort(int arr[], int left, int right)
{
	if (left >= right)
		return;
	int pivot; // Á¤·ÄµÈ pivot
	pivot = Partition(arr,left,right);
	QuickSort(arr,left,pivot-1);
	QuickSort(arr,pivot+1,right);
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	//int arr[7] = { 3,2,4,1,7,6,5 };
	//int arr[3] = { 3,3,3 };
	int len = sizeof(arr) / sizeof(int);
	QuickSort(arr, 0, (sizeof(arr) / sizeof(int)) - 1);

	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}