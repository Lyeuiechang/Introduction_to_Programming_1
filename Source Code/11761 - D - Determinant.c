#include<stdio.h>
long long determinant_reducer(int n, int A[][9]);
int main(void)
{
    int n, i, j;
    long long ans;
    int A[9][9] = {0};
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    ans = determinant_reducer(n, A);
    printf("%lld\n",ans);
    return 0;
}
long long determinant_reducer(int n, int A[][9])
{
    if(n == 1)
    {
        return A[1][1];
    }
    else
    {
        //printf("%d", A[2][1]);
        int i, j, k, m, l;
        long long ans, tmp;
        ans = 0;
        for(i=1;i<=n;i++)
        {
            int B[9][9] = {0};
            for(j=2,m=1;j<=n;j++,m++)
            {
                for(k=1,l=1;k<=n;k++,l++)
                {
                    if(k == i)
                    {
                        l = l-1;
                    }
                    else
                    {
                        B[m][l] = A[j][k];
                        //printf("%d \n", A[j][k]);
                    }
                }
            }
            /*for(int a =1;a<n;a++)
            {
                for(int b =1;b<n;b++)
                {
                    printf("%d ", B[a][b]);
                }
                printf("\n");
            }*/
            //printf("%d ", ans);
            if(i%2 == 0)
            {
                ans = ans - A[1][i] * determinant_reducer(n-1, B);;
            }
            else
            {
                ans = ans + A[1][i] * determinant_reducer(n-1, B);;
            }
        }
        return ans;
    }
}
