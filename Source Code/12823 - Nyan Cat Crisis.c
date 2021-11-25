#include<stdio.h>
#include <math.h>
typedef struct corrd
{
    int x;
    int y;
    int visited;
} corrd;
corrd cat_toast[501];
int groups[501]= {0};
void DFS(int current, int n, int r, int holes)
{
    int i,dist_x,dist_y;
    if(cat_toast[current].visited == 0)
    {
        cat_toast[current].visited = 1;
        groups[holes]++;
    }
    for(i=0; i<n; i++)
    {
        //printf("current=%d i=%d\n",current, i);
        if(i==current)
        {
            continue;
        }
        else if(cat_toast[i].visited == 1)
        {
            continue;
        }
        else
        {
            //printf("current=%d i=%d\n",current, i);
            dist_x = (cat_toast[current].x-cat_toast[i].x);
            dist_y = (cat_toast[current].y-cat_toast[i].y);
            if((dist_x*dist_x)+(dist_y*dist_y) <= r*r)
            {
                cat_toast[i].visited = 1;
                groups[holes]++;
                DFS(i, n, r, holes);
            }
        }
    }
}
int main(void)
{
    int t,n,r,h,i,j,black_hole,remain,threshold;
    //double distance;
    scanf("%d",&t);
    for(h=0; h<t; h++)
    {
        black_hole = 0;
        remain = 0;
        scanf("%d %d %d",&n,&r,&threshold);
        for(i=0; i<n; i++)
        {
            scanf("%d %d",&cat_toast[i].x, &cat_toast[i].y);
            cat_toast[i].visited = 0;
            groups[i] = 0;
        }
        for(i=0; i<n; i++)
        {
            DFS(i, n, r, i);
        }
        /*
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    dist_x = (cat_toast[i].x-cat_toast[j].x);
                    dist_y = (cat_toast[i].y-cat_toast[j].y);
                    //distance = sqrt((dist_x*dist_x)+(dist_y*dist_y));
                    //printf("distance=%lf\n",distance);
                    //printf("%d %d\n",i, j);
                    if((dist_x*dist_x)+(dist_y*dist_y) <= r*r)
                    {
                        if(cat_toast[i].hole==0 && cat_toast[j].hole==0)
                        {
                            black_hole++;
                            cat_toast[i].hole = 1;
                            cat_toast[j].hole = 1;
                        }
                        else if(cat_toast[i].hole==1 && cat_toast[j].hole==0)
                        {
                            cat_toast[j].hole = 1;
                        }
                        else if(cat_toast[i].hole==0 && cat_toast[j].hole==1)
                        {
                            cat_toast[i].hole = 1;
                        }
                        else
                        {

                        }
                    }
                }
            }
        }*/
        for(i=0; i<n; i++)
        {
            if(groups[i] > 0)
            {
                if(groups[i] >= threshold)
                {
                    black_hole++;
                }
                else if(groups[i] < threshold)
                {
                    remain++;
                }
            }
        }
        printf("%d %d\n",remain,black_hole);
    }
    return 0;
}
