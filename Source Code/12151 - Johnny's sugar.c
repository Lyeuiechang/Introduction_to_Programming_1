#include<stdio.h>
int array[1000][1000] = {0};
int main(void)
{
    int n, i, j;
    int max_row = 0;
    int min_col = 50001;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        max_row = 0;
        for(j=0;j<n;j++)
        {
            scanf("%d",&array[i][j]);
            if(array[i][j] > max_row)
            {
                //printf("%d", max_row);
                max_row = array[i][j];
            }
        }
        if(i<n-1)
        {
            printf("%d ", max_row);
        }

    }
    printf("%d\n", max_row);
    for(j=0;j<n;j++)
    {
        min_col = 50001;
        for(i=0;i<n;i++)
        {
            if(array[i][j] < min_col)
            {
                min_col = array[i][j];
            }
        }
        if(j<n-1)
        {
            printf("%d ", min_col);
        }
    }
    printf("%d\n", min_col);
    return 0;
}
