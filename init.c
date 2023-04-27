#include "init.h"

/**
 * 报错信息log
*/
void logError(const char *str) {
    printf("Error: ");
    printf(str);
    printf("\n");
}

/**
 * 构造函数
*/
void construct(FalseClass* obj) {
    obj->array = (int*)malloc(sizeof(int) * ARRAY_SIZE);
    obj->updateArray_FP = updateArray;
    obj->computeSum_FP = computeSum;
    obj->computeMean_FP = computeMean;
}

/**
 * 析构函数
*/
void destruct(FalseClass* obj) {
    free(obj->array);
    obj->array = NULL;
    obj->updateArray_FP = NULL;
    obj->computeSum_FP = NULL;
    obj->computeMean_FP = NULL;
}

/**
 * 更新数组
*/
void updateArray(int number, int *count, int* array) {
    int num = *count;
    if (num + 1 >= ARRAY_SIZE) {
        logError("No enough space!");
    }
    array[num] = number;
    *count = num + 1;
}

/**
 * 计算数组之和
*/
int computeSum(int count, int *array) {
    int sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += array[i];
    }
    return sum;
}

/**
 * 计算数组均值
*/
float computeMean(int count, int sum) {
    if (count <= 0) {
        return 0.0;
    }
    return (float)sum / count;
}

