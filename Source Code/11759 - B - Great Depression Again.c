#include<stdio.h>
#include<string.h>
typedef struct car{
    char brand[21];
    int A;
    int B;
    int earnAmoney;
}car;
car profit[501];
car carAprofitmax[501];
int compare_char(const void *a, const void *b)
{
    car aa = *(car *)a;
    car bb = *(car *)b;
    return strcmp(aa.brand, bb.brand);
}
int compare_int(const void *a, const void *b)
{
    car aa = *(car *)a;
    car bb = *(car *)b;
    return bb.earnAmoney - aa.earnAmoney;
}
int main(void)
{
    int i,n,x,y;
    scanf("%d %d %d",&n,&x,&y);
    for(i=0;i<n;i++)
    {
        scanf("%s",&profit[i].brand);
        scanf("%d %d",&profit[i].A, &profit[i].B);
        profit[i].earnAmoney = profit[i].A - profit[i].B;
    }
    qsort(profit,n,sizeof(car),compare_int);
    for(i=0;i<x;i++)
    {
        carAprofitmax[i] = profit[i];
    }
    qsort(carAprofitmax,x,sizeof(car),compare_char);
    for(i=0;i<x;i++)
    {
        printf("%s\n",carAprofitmax[i].brand);
    }
    return 0;
}
