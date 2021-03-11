//
// Created by Administrator on 2021/3/10.
//
#include <stdio.h>

void print_array(int *a, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

