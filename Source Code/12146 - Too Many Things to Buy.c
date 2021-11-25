#include<stdio.h>
typedef struct items{
    int today;
    int tomorrow;
    int price;
}items;
items shopping[100000];
int compare(const void *a, const void *b)
{
    items aa = *(items *)a;
    items bb = *(items *)b;
    if(aa.price > bb.price)
    {
        return 1;
    }
    else if(aa.price < bb.price)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int main(void)
{
    int n, k, i;
    long long sum = 0;
    scanf("%d %d", &n, &k);
    for(i=0;i<n;i++)
    {
        scanf("%d", &shopping[i].today);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d", &shopping[i].tomorrow);
        shopping[i].price = shopping[i].today - shopping[i].tomorrow;
    }
    qsort(shopping, n, sizeof(shopping[0]), compare);
    for(i=0;i<k;i++)
    {
        sum = sum + shopping[i].today;
    }
    for(i=k;i<n;i++)
    {
        if(shopping[i].price <= 0)
        {
            sum = sum + shopping[i].today;
        }
        else
        {
            sum = sum + shopping[i].tomorrow;
        }
    }
    printf("%lld\n",sum);
    return 0;
}
