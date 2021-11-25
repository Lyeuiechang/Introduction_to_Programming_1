#include<stdio.h>
int main(void)
{
    int T, i, A, B, C, D, x, y, z, count;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        count = 0;
        scanf("%d %d %d %d",&A, &B, &C, &D);
        for(y=B;y<=C;y++)
        {
            if(B+y < C)
            {
                //printf("if %d %d %d %d\n", A, y, C, count);
            }
            else
            {
                for(x=A;x<=B;x++)
                {
                    if(x+y > C)
                    {
                        if(x+y > D)
                        {
                            count = count + (D-C+1);
                        }
                        else if(x+y == D)
                        {
                            count = count + (D-C);
                        }
                        else
                        {
                            count = count + ((x+y)-C);
                        }
                        //printf("else %d %d %d %d\n", x, y, C, count);
                    }
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
