#include<stdio.h>
int products[300001];
long long price[300001];
int compare(const void *a, const void *b)
{
    int aa = *(int *)a;
    int bb = *(int *)b;
    return aa-bb;
}
int main(void)
{
    int t,i,j,n,p,k,ans;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d %d",&n,&p,&k);
        ans = 0;
        for(j=0;j<=300000;j++)
        {
            products[j] = 0;
            price[j] = 0;
        }
        for(j=1;j<=n;j++)
        {
            scanf("%d",&products[j]);
        }
        qsort(products,n+1,sizeof(products[0]),compare);
        for(j=1;j<=n;j++)
        {
            if(j < k)
            {
                price[j] = prihttps://acm.cs.nthu.edu.tw/contest/2060/https://acm.cs.nthu.edu.tw/contest/2060/ce[j-1] + products[j];
            }
            else
            {
                price[j] = price[j-k] + products[j];
            }
        }
        /*for(j=1;j<=n;j++)
        {
            printf("%d ",products[j]);
        }
        printf("\n");
        for(j=1;j<=n;j++)
        {
            printf("%d ",price[j]);
        }
        printf("\n");*/
        for(j=1;j<=n;j++)
        {
            if(price[j] <= p)
            {
                ans = j;
                //printf("ans = %d ",ans);
            }
        }
        /*printf("\n");*/
        printf("%d\n",ans);
    }
    return 0;
}
