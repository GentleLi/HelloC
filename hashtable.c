//
// Created by Administrator on 2021/3/5.
//
#include <stdio.h>
#include "uthash.h"

struct hashTable {
    int key;
    int val;
    UT_hash_handle hh;
};

struct hashTable *hash_table;

struct hashTable *find(int ikey) {
    struct hashTable *tmp;
    HASH_FIND_INT(hash_table, &ikey, tmp);
    return tmp;
}

void insert(int ikey, int ival) {
    struct hashTable *it = find(ikey);
    if (it == NULL) {
        struct hashTable *tmp = malloc(sizeof(struct hashTable));
        tmp->key = ikey, tmp->val = ival;
        HASH_ADD_INT(hash_table, key, tmp);
    } else {
        it->val = ival;
    }
}

int *twoSum(int *nums, int numSize, int target, int *resultSize) {
    hash_table = NULL;
    int i = 0;
    for (i = 0; i < numSize; i++) {
        struct hashTable *it = find(target - nums[i]);
        if (it != NULL) {
            int *ret = malloc(sizeof(int) * 2);
            ret[0] = it->val, ret[1] = i;
            return ret;
        }
        insert(nums[i], i);
    }
    *resultSize = 0;
    return NULL;
}







