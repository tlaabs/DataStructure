#include <stdio.h>
void InsertionSort(int arr[], int n)
{
	int i, j;
	int tmp;
	for (i = 1; i < n ; i++)
	{
		tmp = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (tmp > arr[j])
				break;
			arr[j + 1] = arr[j];
		}
		arr[j+1] = tmp;
	}
}
int main()
{
	int arr[4] = { 3,2,4,1 };
	int i;
	InsertionSort(arr, sizeof(arr) / sizeof(int));

	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}