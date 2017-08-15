#include <stdio.h>

int ISearch(int arr[], int first, int last, int target)
{
	if (first > last)
		return -1;
	if (arr[first] > target || arr[last] < target)
		return -1;
	int mid = ((double)(target-arr[first])/(arr[last]-arr[first])*(last-first))+first;
	printf("mid : %d\n", mid);
	if (arr[mid] == target)
		return mid;
	else if (arr[mid] < target)
		return ISearch(arr, mid + 1, last, target);
	else
		return ISearch(arr, first, mid - 1, target);
}

int main() {
	int arr[] = { 1,3,4,7,9,13,15};
	int len = sizeof(arr) / sizeof(int);
	int result = ISearch(arr, 0, len - 1, 2);
	printf("idx : %d", result);
	printf("\n");
	return 0;
}