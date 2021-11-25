#include<stdio.h>
long long a[1000001] = {0};
int binary_search(int low, int high, long long f)
{
    int mid;
    while(high >= low)
    {
        //printf("%d %d\n",high, low);
        mid = (high+low)/2;
        if(a[mid] < f)
        {
            low = mid+1;
        }
        else
        {
            high = mid - 1;
        }
    }
    //printf("%d %d\n",high, low);
    //printf("high = %d\n",high+1);
    return high+1;
}
int main(void)
{
    int n, k, q, i, j, min_index, result;
    long long min_value, f;
    scanf("%d %d %d",&n, &k, &q);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(i=0;i<q;i++)
    {
        scanf("%lld",&f);
        if(f > a[n-1])
        {
            result= -1;
        }
        else
        {
            result = binary_search(0, n-1, f);
            //printf("result = %d\n",result);
        }
        if(result == -1)
        {
            printf("gan ni nya sai bau\n");
        }
        else
        {
            min_value = a[result];
            min_index = (n-k+result)%n;
            while(min_value == a[result])
            {
                if((n-k+result)%n < min_index)
                {
                    min_index = (n-k+result)%n;
                }
                result++;
            }
            printf("%d\n", min_index+1);
        }
    }
    return 0;
}
