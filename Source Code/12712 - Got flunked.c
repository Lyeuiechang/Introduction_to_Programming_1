#include<stdio.h>
#define _10e18_odd 499999999999999999
#define real_odd 500000000
#define _10e18 10000000000000000000
unsigned long long binary_search(unsigned long long l, unsigned long long r, unsigned long long x, int j, unsigned long long series)
{
    if(series-1 == x)
    {
        return 0;
    }
    while (l <= r) {
        unsigned long long m = l + (r-l) / 2;
        unsigned long long odd_m = 2*m+1;
        unsigned long long result = odd_m*(odd_m-1)/2 + odd_m*(series-1);
        //printf("l = %llu r = %llu m = %llu odd_m = %llu result = %llu series = %llu\n",l, r, m, odd_m, result,series);
        // Check if x is present at mid
        if (result == x)
            return m;

        // If x greater, ignore left half
        if (result < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was
    // not present
    return -1;
}
int main(void)
{
    int T,i,j;
    unsigned long long n,series,ans,odd_k,k;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%llu",&n);
        series = 1;
        ans = _10e18+1;
        for(j=0;j<60;j++)
        {
            k = binary_search(1,real_odd,n,j,series);
            if(k != -1)
            {
                odd_k = (2*k+1)*series;
                if(ans > odd_k)
                {
                    ans = odd_k;
                }
            }
            series = series * 2;
        }
        if(ans == _10e18+1)
        {
            printf("-1\n");
        }
        else
        {
            printf("%llu\n",ans);
        }
    }
}
