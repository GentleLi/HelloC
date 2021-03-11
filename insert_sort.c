//
// Created by Administrator on 2021/3/10.
//
/**
 * 直接插入排序算法
 * @param a
 * @param size
 */
void insert_sort(int *a, int size) {
    for (int i = 1; i < size; i++) {
        if (a[i] < a[i - 1]) {
            int j = i - 1;
            int temp = a[i];
            while (j > -1 && temp < a[j]) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = temp;
        }
    }
}