//
// Created by Administrator on 2021/3/10.
//
#include <stdio.h>

int size_of() {
    int a = 4;
    int size = sizeof(int);
    printf("int 型占用字节 %d\n", size);
    printf("a的地址：%p\n", &a);
    printf("地址长度:%d", sizeof(&a));//打印地址长度，64位操作系统，地址长度为8字节
    return 0;
}