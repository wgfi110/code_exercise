/*
 * find_k_max.cpp
 *
 *  Created on: 2017年11月16日
 *      Author: wangfei26
 */
#include "stdio.h"

int find_k_th(int *input, int size, int k) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        int pivot = input[start];
        int last_start = start;
        int last_end = end;
        while (true) {
            while ((start < end) && pivot <= input[end]) {
                 --end;
            }
            input[start] = input[end];
            while ((start < end) && pivot >= input[start]) {
                 ++start;
            }
            input[end] = input[start];
            if (start == end) {
                printf("here, start:%d, end:%d\n", start, end);
                break;
            }
        }
        input[start] = pivot;

        if (start == (k - 1)) {
            return input[start];
        } else if (start > (k - 1)) {
            end = start - 1;
            start = last_start;
        } else {
        	start = start + 1;
            end = last_end;
        }
        printf("start:%d, end:%d\n", start, end);

    }

    return -1;
}

int main () {
	int array[10] = {40, 5, 6, 8, 19, 20, 21, 22, 35, 50};
	printf("hello world\n");

	printf("the %d th number is %d!\n", 6, find_k_th(array, 10, 6));
}

