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


void adjust_heap(int a[], int i, int size) {
    int temp = a[i];
    for (int k = 2 * i + 1; k < size; k = k * 2 + 1) {
        if (k + 1 < size && a[k + 1] > a[k]) {//比较左子节点和右子节点的值;如果右子节点大于左子节点，则k=k+1指向右子节点,否则k仍指向左子节点
            k++;
        }
        if (a[k] > temp) {//比较当前位置a[k]与父节点temp大小
            a[i] = a[k];
            i = k;
        } else {
            continue;
        }
    }
    a[i] = temp;//最终存放位置
}

void swap(int a[], int p, int q) {
    int temp = a[p];
    a[p] = a[q];
    a[q] = temp;
}

void heap_sort(int a[], int size) {
    int i = size / 2 - 1;
    //调整堆，首次调整从i=(size/2-1)处开始进行
    for (int j = i; j >= 0; j--) {
        adjust_heap(a, j, size);
    }
    for (int j = size - 1; j >= 0; j--) {
        swap(a, 0, j);//交換根节点与尾部叶子结点的值
        adjust_heap(a, 0, j);//调整堆，从0节点开始，因为顶部根节点刚刚做了交换
    }
}

