//
// Created by Administrator on 2021/3/10.
//
/**
 * 选择排序
 * @param a
 * @param size
 * @return
 */
void select_sort(int *a, int size) {
    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (i != min) {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

void bubble_sort(int *a, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (a[j] < a[i]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void quick_sort(int a[], int left, int right) {
    if (left < right) {
        int start = left, end = right;
        int pivot = a[start];
        while (start < end) {
            while (start < end && a[end] >= pivot) {
                end--;
            }
            //交换
            if (start < end) {
                a[start++] = a[end];
            }
            while (start < end && a[start] < pivot) {
                start++;
            }
            if (start < end) {
                a[end--] = a[start];
            }
        }
        a[start] = pivot;
        quick_sort(a, left, start - 1);
        quick_sort(a, start + 1, right);
    }
}

/**
 * 归并排序 合并
 * @param a
 * @param left
 * @param mid
 * @param right
 * @param temp
 */
void merge(int a[], int left, int mid, int right, int *temp) {
    int i = left;
    int j = mid + 1;
    int t = 0;
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp[t++] = a[i++];
        } else {
            temp[t++] = a[j++];
        }
    }
    while (i <= mid) {
        temp[t++] = a[i++];
    }
    while (j <= right) {
        temp[t++] = a[j++];
    }
    t = 0;
    while (left <= right) {
        a[left++] = temp[t++];
    }

}

void merge_sort(int a[], int left, int right, int temp[]) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(a, left, mid, temp);
        merge_sort(a, mid + 1, right, temp);
        merge(a, left, mid, right, temp);
    }
}

