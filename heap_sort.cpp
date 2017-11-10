#include "stdio.h"

int heap_adjust(int *heap, int start, int end) {
	int root_value = heap[start];
	for (int child = start * 2; child < end; child = child * 2) {
		if (heap[child] <= heap[child + 1]) {
			child++;
		}
		if (root_value <= heap[child]) {
			heap[start] = heap[child];
			heap[child] = root_value;
		} else {
			break;
		}
		start = child;
	}
	return 0;
}

int heap_sort(int *array, int max_pos) {
	if (max_pos <= 1) {
		return -1;
	}

	for (int i = max_pos / 2; i > 0; --i) {
		heap_adjust(array, i, max_pos);
	}

	for (int i = max_pos; i >= 1; --i) {
		int tmp = array[i];
		array[i] = array[1];
		array[1] = tmp;
		heap_adjust(array, 1, i - 1);
	}
	return 0;
}

int main() {
	int array[10] = {9, 5, 6, 9, 110, 20, 34, 45, 56, 45};
	heap_sort(array, 9);
	for (int i = 0; i < 10; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}
