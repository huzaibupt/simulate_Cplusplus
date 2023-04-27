#ifndef __INIT_H__
#define __INIT_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ARRAY_SIZE 100

typedef struct FalseClass_ {
    int count;
    int sum;
    int *array;
    float mean;
    void (*updateArray_FP)(int, int*, int*);
    int (*computeSum_FP)(int, int*);
    float (*computeMean_FP)(int, int);
} FalseClass;


void logError(const char *str);

void construct(FalseClass* obj);
void destruct(FalseClass* obj);

void updateArray(int number, int *count, int* array);
int computeSum(int count, int *array);
float computeMean(int count, int sum);

#endif