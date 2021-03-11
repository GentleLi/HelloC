#include <stdio.h>
#include "insert_sort.h"
#include "sort.h"
#include "print_util.h"

int main() {
    int a[9] = {8, 4, 5, 7, 1, 3, 6, 2, 0};
    int size = sizeof(a) / sizeof(int);
    print_array(a, size);
//    insert_sort(a, size);
//    select_sort(a, size);
//    bubble_sort(a, size);
//    quick_sort(a, 0, size - 1);
    int temp[9] = {0};
    merge_sort(a, 0, size - 1, temp);
    print_array(a, size);
    return 0;
}











