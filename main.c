#include <stdio.h>
#include "init.h"

int main(int argc, const char *argv[]) {

    clock_t start, end;
    start = clock();

    FalseClass obj;
    construct(&obj);

    for (int i = 0; i < 50; ++i) {
        obj.updateArray_FP(i, &(obj.count), obj.array);
    }

    obj.sum = obj.computeSum_FP(obj.count, obj.array);
    printf("sum of obj.array: %d\n", obj.sum);
    obj.mean = obj.computeMean_FP(obj.count, obj.sum);
    printf("mean of obj.array: %f\n", obj.mean);

    destruct(&obj);

    /* Time-consuming test */
    // for (int i = 0; i < 5000; ++i) {
    //     printf("%d running!\n", i);
    // }

    end = clock();
    printf("end - start = %lf s \n", (double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}