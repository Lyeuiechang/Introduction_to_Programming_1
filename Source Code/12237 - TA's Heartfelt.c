#include<stdio.h>
int main(void)
{
    float f;
    int i;
    void *p = &f;
    while(scanf("%f", &f)!=EOF)
    {
        for(i=31;i>=0;i--)
        {
            printf("%d", (*(int *)p) >> i & 1);
        }
        printf("\n");
    }
    return 0;
}
