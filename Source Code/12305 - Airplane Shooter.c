#include<stdio.h>
#include<stdlib.h>
typedef struct element{
    int index;
    int admin_level;
    int license_number;
}element;
element a[100001];
int compare(const void *a, const void *b)
{
    element aa = *(element *)a;
    element bb = *(element *)b;
    //printf("aa=%d bb=%d\n",aa.index, bb.index);
    //printf("aa=%d bb=%d\n",aa.admin_level, bb.admin_level);
    //printf("aa=%d bb=%d\n",aa.license_number, bb.license_number);
    if(aa.admin_level != bb.admin_level)
    {
        return aa.admin_level - bb.admin_level;
    }
    else
    {
        return aa.license_number - bb.license_number;
    }
}
int main(void)
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a[i].admin_level, &a[i].license_number);
        a[i].index = i;
    }
    qsort(a,n, sizeof(a[0]),compare);
    printf("%d",a[0].index+1);
    for(i=1;i<n;i++)
    {
        printf(" %d",a[i].index+1);
    }
    printf("\n");
    return 0;
}
