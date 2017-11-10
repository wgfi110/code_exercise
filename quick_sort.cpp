#include "stdlib.h"
#include "stdio.h"

int once_quick(int *iArray, int low, int high) {
	int iPivot = iArray[low];
	while(low < high) {
		while (low < high && iArray[high] >= iPivot) {
			--high;
		}
		iArray[low] = iArray[high];
		while (low < high && iArray[low] < iPivot) {
			++low;
		}
		iArray[high] = iArray[low];
	}
	iArray[low] = iPivot;
	return low;
}

int quick_sort(int *array, int low, int high) {

	if (low < high) {
		int pivot_pos = once_quick(array, low, high);
		printf("pivot_pos:%d\n", pivot_pos);
		for (int i = 0; i < 10; ++i) {
			printf("%d ", array[i]);
		}
		printf("\n");
		quick_sort(array, low, pivot_pos - 1);
		quick_sort(array, pivot_pos + 1, high);
	}
	return 0;
}

int main() {
	int array[10] = {3, 5, 6, 9, 110, 20, 34, 45, 56, 45};
	quick_sort(array, 0, 9);
	for (int i = 0; i < 10; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}
