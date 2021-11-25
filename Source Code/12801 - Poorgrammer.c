#include<stdio.h>
#include<stdlib.h>
int a[200005] = {0};
long long b[200005] = {0};
int ability_check(int day, int m, int n)
{
    int quotient,remaining,useful,reduce, i;
    long long coffee, ability;
    reduce = -1;
    useful = 0;
    //useful = binarysearch(a,quotient-1,n);
    for(i=0;i<n;i++)
    {
        //printf("a[j]:%d j:%d\n",a[j],j);
        if(i%day==0)
        {
            reduce++;
        }
        if(a[i]<=reduce)
        {
            //printf("a[j]:%d j:%d\n",a[j],j);
            break;
        }
    }
    useful = i;
    //printf("useful:%d\n",useful);
    coffee = b[useful-1];
    quotient = useful / day;
    remaining = useful % day;
    //printf("ability:%d\n",ability);
    ability = coffee - ((quotient*(quotient-1))/2)*day - quotient*remaining;
   // printf("quotient:%d remaining:%d ability:%lld\n",quotient,remaining,ability);
    //system("pause");
    if(ability < m)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
int binary_search(int low, int high, int m, int n)
{
    int mid;
    int valid;
    while(high >= low)
    {
        //printf("%d %d\n",high, low);
        mid = (high+low)/2;
        valid = ability_check(mid, m, n);
        if(valid==-1)
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
    int t,i,n,m,j,day;
    long long coffee;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&n,&m);
        coffee = 0;
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
            //printf("coffee:%lld\n",coffee);
            coffee = coffee + a[j];
            b[j] = coffee;
        }
        //printf("coffee:%lld\n",coffee);
        if(coffee < m)
        {
            printf("-1\n");
        }
        else
        {
            day = 0;
            day = binary_search(1, n, m, n);
            printf("%d\n",day);
        }
    }
    return 0;
}
