//
// Created by Administrator on 2021/3/10.
//
#include <stdio.h>

/**
 * 控制台输入为数组赋值
 * @return
 */

int input_from_console() {
    //函数声明
    int arr[5];
    printf("请输入5个整型数：\n");
    fflush(stdout);
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &arr[i]);
    }
    int length = sizeof(arr) / sizeof(int);
    printf("数组长度：%d\n", length);
    fflush(stdout);
    for (int i = 0; i < length; ++i) {
        printf("arr[%d] = %d \n ", i, arr[i]);
    }
    printf("%p", &arr);
}
