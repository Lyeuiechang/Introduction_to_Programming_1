#include<stdio.h>
#include<string.h>
typedef struct str{
    int frequency[26];
    int visited;
}str;
str names[2000];
int groups;
//int groups[2000];
void DFS(int current, int n, int entry)
{
    int i,j,found;
    if(names[current].visited == 0)
    {
        names[current].visited = 1;
        //groups[entry]++;
        groups++;
    }
    for(i=0;i<n;i++)
    {
        //printf("current=%d i=%d\n",current, i);
        if(i==current)
        {
            continue;
        }
        else if(names[i].visited == 1)
        {
            continue;
        }
        else
        {
            //printf("current=%d i=%d\n",current, i);
            found = 0;
            for(j=0;j<26;j++)
            {
                if(names[current].frequency[j] > 0 && names[i].frequency[j] > 0)
                {
                    //printf("frequency_letter = %d %d\n",names[current].frequency[j],names[i].frequency[j]);
                    found = 1;
                    break;
                }
            }
            if(found == 1)
            {
                names[i].visited = 1;
                //groups[entry]++;
                DFS(i, n, entry);
            }
        }
    }
}
int main(void)
{
    int t,i,n,j,k,len_s,letter,ans;
    char s[1001];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        groups = 0;
        for(j=0;j<n;j++)
        {
            for(k=0;k<26;k++)
            {
                names[j].frequency[k] = 0;
            }
            //groups[j] = 0;
            names[j].visited = 0;
            scanf("%s",&s);
            len_s = strlen(s);
            for(k=0;k<len_s;k++)
            {
                letter = s[k] - 'a';
                names[j].frequency[letter]++;
            }
        }
        ans = 0;
        for(j=0;j<n;j++)
        {
            DFS(j, n, j);
        }
        /*for(j=0;j<n;j++)
        {
            if(groups[j] > 0)
            {
                ans++;
            }
        }*/
        printf("%d\n",groups);
    }
    return 0;
}
