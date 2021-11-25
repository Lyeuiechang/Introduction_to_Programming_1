#include<stdio.h>
int pounds[1001][1001]= {0};
int total[1001][1001]= {0};
void checkpounds(int i, int j, int inital_i, int initial_j)
{
    if(pounds[i][j] == -1)
    {
        total[inital_i][initial_j]++;
        pounds[i][j] = -2;
        checkpounds(i-1, j, inital_i, initial_j);
        checkpounds(i, j-1, inital_i, initial_j);
        checkpounds(i+1, j, inital_i, initial_j);
        checkpounds(i, j+1, inital_i, initial_j);
    }
}
int main(void)
{
    int m,n,i,j;
    int total_pounds = 0;
    char c;
    scanf("%d %d",&m, &n);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf(" %c",&c);
            if(c=='~')
            {
                pounds[i][j] = -1;
            }
            else if(c=='.')
            {
               pounds[i][j] = -2;
            }
        }
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            checkpounds(i,j,i,j);
        }
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(total[i][j]>0)
            {
                total_pounds++;
            }
        }
    }
    printf("%d\n",total_pounds);
    return 0;
}
