#include<stdio.h>
#define MOD 1000000007
typedef struct Matrix{
    long long m[2][2];
}Matrix;
long long power(long long x);
Matrix Matrix_multiply(Matrix a, Matrix b, Matrix c);
void Print_martix(Matrix a);
int main(void)
{
    int t, i;
    long long x, ans;
    while(scanf("%lld",&x)!=EOF)
    {
        ans = power(x);
        printf("%lld\n",ans);
    }
    return 0;
}

long long power(long long x)
{
    int num = 0;
    if(x==1)
    {
        return 1;
    }
    else if(x == 2)
    {
        return 1;
    }
    else
    {
        x = x - 2;
        Matrix a;
        int i,j;
        for(i=0;i<2;i++)
        {
            for(j=0;j<2;j++)
            {
                a.m[i][j] = 0;
            }
        }
        a.m[0][0] = 1;
        a.m[0][1] = 1;
        a.m[1][0] = 1;
        Matrix zero;
        for(i=0;i<2;i++)
        {
            for(j=0;j<2;j++)
            {
                zero.m[i][j] = 0;
            }
        }
        //Print_martix(a);
        Matrix ans;
        for(i=0;i<2;i++)
        {
            for(j=0;j<2;j++)
            {
                ans.m[i][j] = 0;
            }
        }
        ans.m[0][0] = 1;
        ans.m[1][1] = 1;
        //Print_martix(ans);
        while(x!=0)
        {
            //printf("X:%d\n", x);
            if(x&1)
            {
                ans = Matrix_multiply(ans, a, zero);
            }
            a = Matrix_multiply(a, a, zero);
            //Print_martix(ans);
            //printf("------\n");
            //Print_martix(a);
            x = x / 2;
        }
        //ans = Matrix_multiply(ans, a);
        //Print_martix(ans);
        num = (num + (ans.m[0][0])%MOD)%MOD;
        num = (num + (ans.m[0][1])%MOD)%MOD;
        /*for(i=0;i<3;i++)
        {
            num = (num + (ans.m[i][0]*1)%MOD)%MOD;
        }
        for(i=0;i<3;i++)
        {
            num = (num + (ans.m[i][1]*12)%MOD)%MOD;
        }
        for(i=0;i<3;i++)
        {
            num = (num + (ans.m[i][2]*13)%MOD)%MOD;
        }*/
    }
    return num;
}

Matrix Matrix_multiply(Matrix a, Matrix b, Matrix c)
{
    Matrix d;
    int i, j, k;
    d = c;
    //Print_martix(a);
    //Print_martix(b);
    //Print_martix(c);
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<2;k++)
            {
                //Print_martix(c);
                //printf("-----\n%d %d %d\n-----\n",i, j, k);
                d.m[i][j] = (d.m[i][j] + (a.m[i][k] * b.m[k][j])%MOD)%MOD;
            }
        }
    }
    return d;
}

void Print_martix(Matrix a)
{
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("%d ",a.m[i][j]);
        }
        printf("\n");
    }
}
