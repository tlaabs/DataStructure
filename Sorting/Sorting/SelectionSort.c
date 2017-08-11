#include <stdio.h>
void SelectionSort(int arr[], int n)
{
	int i, j;
	int minidx;
	int tmp;
	for (i = 0; i < n - 1; i++)
	{
		//ÃÖ¼Ú°ª Å½»ö
		minidx = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[minidx] > arr[j])
				minidx = j;
		}
		tmp = arr[i];
		arr[i] = arr[minidx];
		arr[minidx] = tmp;
	}
}
int main()
{
	int arr[4] = { 3,2,4,1 };
	int i;
	SelectionSort(arr, sizeof(arr) / sizeof(int));

	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}