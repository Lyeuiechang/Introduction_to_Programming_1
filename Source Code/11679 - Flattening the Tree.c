#include<stdio.h>
int Tree[1024] = {0};
int n,level,index;
int find_seq(int cur, int cur_level)
{
    if(cur_level == level)
    {
        if(index == 0)
        {
            printf("%d",Tree[cur]);
        }
        else
        {
            printf(" %d",Tree[cur]);
        }
        index++;
    }
    else
    {
        find_seq(cur*2, cur_level+1);
        if(index == 0)
        {
            printf("%d",Tree[cur]);
        }
        else
        {
            printf(" %d",Tree[cur]);
        }
        index++;
        find_seq(cur*2+1, cur_level+1);
    }
}
int main(void)
{
    int i,j;
    scanf("%d",&n);
    j = n+1;
    level = 0;
    index = 0;
    while(j>1)
    {
        j = j / 2;
        level++;
    }
    //printf("%d\n",level);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&Tree[i]);
    }
    find_seq(1, 1);
    printf("\n");
    return 0;
}
