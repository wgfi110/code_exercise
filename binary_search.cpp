#include "stdio.h"

int bin_search(int *sort_array, int target, int low, int high) {
	while (low <= high) {
		int mid_pos = (low + high) / 2;
		if (target > sort_array[mid_pos]) {
			low = mid_pos + 1;
		}
		if (target < sort_array[mid_pos]) {
			high = mid_pos - 1;
		}
		if (target == sort_array[mid_pos]) {
			return mid_pos;
		}
	}
	return -1;
}

int main() {
	int sort_array[10] = {0, 10, 33, 45, 78, 99, 101, 203, 333, 400};

	printf("bin_search:%d\n", bin_search(sort_array, 101, 0, 9));
}

