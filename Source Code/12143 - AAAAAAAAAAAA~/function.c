#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int BS_full(int *input, int q, int s, int n)
{
	int m = (s+n)/2;
	if(input[m] == q)
    {
        return m;
    }
    else if(input[m] < q)
    {
        return BS_full(input, q, m, n);
    }
    else
    {
        return BS_full(input, q, s, m);
    }
}

int BS(int *input, int q, int n)
{
    return BS_full(input, q, 0, n);
}
