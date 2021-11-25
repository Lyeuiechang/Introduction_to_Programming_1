#include <stdio.h>
#include <stdlib.h>
#include "function.h"
int compare(const void *a, const void *b)
{
    int aa = *(int *)a;
    int bb = *(int *)b;
    return aa - bb;
}
void my_sort(int* B)
{
    int *real_b = *B;
    int *b = real_b+1;
    int N = real_b[0];
    //printf("%d\n",N);
    qsort(b,N,sizeof(int),compare);
}
