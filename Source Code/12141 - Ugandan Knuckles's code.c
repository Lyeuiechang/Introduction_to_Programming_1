#include<stdio.h>
#include<string.h>
int compare (const void * a, const void * b)
{
    return strlen(a) - strlen(b);
}
int main(void)
{
    int n, i, j;
    char stele[1000][1000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",stele[i]);
    }
    qsort(stele, n, sizeof(char[1000]), compare);
    for(i=0;i<n-1;i++)
    {
        if(strstr(stele[i+1], stele[i])==NULL)
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    for(i=0;i<n;i++)
    {
        printf("%s\n",stele[i]);
    }
    return 0;
}
