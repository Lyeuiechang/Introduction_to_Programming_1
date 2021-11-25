#include<stdio.h>
double A[5][5] = {0};
double city[5] = {0};
double new_city[5] = {0};
int main(void)
{
    int T,i,j,k,l,n;
    double p;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        int exceed = 0;
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                scanf("%lf",&A[j][k]);
            }
        }
        for(j=0;j<n;j++)
        {
            scanf("%lf",&city[j]);
        }
        scanf("%lf",&p);
        for(j=0;j<1000000;j++)
        {
            for(k=0;k<n;k++)
            {
                new_city[k] = 0;
                for(l=0;l<n;l++)
                {
                    new_city[k] = new_city[k] + city[l]*A[k][l];
                }
                //printf("%f ",new_city[k]);
            }
            //printf("\n");
            for(k=0;k<n;k++)
            {
                city[k] = new_city[k];
                if(city[0] <= p)
                {
                    //printf("%f\n",city[0]);
                    exceed = 1;
                }
            }
            if(exceed == 1)
            {
                break;
            }
        }
        if(exceed == 0)
        {
            printf("Never\n");
        }
        else
        {
            printf("%d\n",j+1);
        }
    }
    return 0;
}
