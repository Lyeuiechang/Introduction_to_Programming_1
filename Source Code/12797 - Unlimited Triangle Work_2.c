#include<stdio.h>
int main(void)
{
    int T, i, A, B, C, D, j;
    long long ans;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d %d %d %d", &A, &B, &C, &D);
        int Triangle[100005] ={0};
        ans = 0;
        for(j=A;j<=B;j++)
        {
            Triangle[j+B] = Triangle[j+B] + 1;
            Triangle[j+C+1] = Triangle[j+C+1] - 1;
        }
        for(j=A+B-1;j<=B+C+1;j++)
        {
            Triangle[j] = Triangle[j] + Triangle[j-1];
        }
        for(j=A+B-1;j<=B+C+1;j++)
        {
            Triangle[j] = Triangle[j] + Triangle[j-1];
        }
        for(j=C;j<=D;j++)
        {
            if(j > B+C+1)
                break;
            ans = ans + (Triangle[B+C+1] - Triangle[j]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
