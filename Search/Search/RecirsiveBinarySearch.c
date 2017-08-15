#include <stdio.h>

int BSearchRecur(int arr[], int first, int last, int target)
{
	if (first > last)
		return -1;
	int mid = (first + last) / 2;

	if (arr[mid] == target)
		return mid;
	else if(arr[mid] < target)
		return BSearchRecur(arr,mid+1, last, target);
	else
		return BSearchRecur(arr,first, mid - 1, target);
}

int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(arr) / sizeof(int);

	int result = BSearchRecur(arr, 0, len - 1, 10);
	printf("idx : %d", result);
	printf("\n");
	return 0;
}