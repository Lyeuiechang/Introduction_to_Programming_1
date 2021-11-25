#include<stdio.h>
int main(void)
{
    int n, i, j, flag;
    char c;
    int Knuckles[26] ={0};
    scanf("%d",&n);
    flag = 0;
    for(i=0;i<n;i++)
    {
        scanf(" %c",&c);
        j = c - 'a';
        Knuckles[j]++;
        //printf("%d\n",j);
    }
    if(n == 1)
    {
        flag = 1;
    }
    else
    {
        for(i=0;i<26;i++)
        {
            if(Knuckles[i]>1)
            {
                flag = 1;
                break;
            }
        }
    }
    if(flag == 1)
    {
        printf("I'm the god of Knuckles!\n");
    }
    else
    {
        printf("Different makes perfect\n");
    }
    return 0;
}
