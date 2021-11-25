#include<stdio.h>
#include<string.h>
int compare (const void * a, const void * b)
{
    const char* aa = (const char*)a;
    const char* bb = (const char*)b;
    int len_a = strlen(a);
    int len_b = strlen(b);
    int i;
    if(len_a < len_b)
    {
        char a_copy[1001];
        strcpy(a_copy, aa);
        int times = (len_b-len_a)/len_a;
        for(i = 0;i< times;i++)
        {
            strcat(a_copy, aa);
        }
        times = (len_b-len_a)%len_a;
        strncat(a_copy, aa, times);
        return strcmp(bb, a_copy);
    }
    else if(len_a > len_b)
    {
        char b_copy[1001];
        strcpy(b_copy, bb);
        int times = (len_a-len_b)/len_b;
        for(i = 0;i< times;i++)
        {
            strcat(b_copy, bb);
        }
        times = (len_a-len_b)%len_b;
        strncat(b_copy, bb, times);
        return strcmp(b_copy, aa);
    }
    else
    {
        return strcmp(bb, aa);
    }
}
int main(void)
{
    int n, i;
    while(scanf("%d",&n)!=EOF)
    {
        char integers[100][1001];
        for(i=0;i<n;i++)
        {
            scanf("%s",&integers[i]);
        }
        qsort(integers, n, sizeof(char[1001]), compare);
        for(i=0;i<n;i++)
        {
            printf("%s",integers[i]);
        }
        printf("\n");
    }
    return 0;
}
