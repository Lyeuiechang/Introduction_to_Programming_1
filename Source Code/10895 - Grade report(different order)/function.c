#include <stdio.h>
#include <stdlib.h>
#include "function.h"
char directions;
int compare(const void *a, const void *b)
{
    Grade aa = *(Grade *)a;
    Grade bb = *(Grade *)b;
    if(directions == 'a')
    {
        if(aa.total != bb.total)
        {
            //printf("%d %d\n",aa.total - bb.total, bb.total);
            return aa.total - bb.total;
        }
        else if(aa.Chinese != bb.Chinese)
        {
            return aa.Chinese - bb.Chinese;
        }
        else if(aa.English != bb.English)
        {
            return aa.English - bb.English;
        }
        else if(aa.math != bb.math)
        {
            return aa.math - bb.math;
        }
        else if(aa.science != bb.science)
        {
            return aa.science - bb.science;
        }
        else
        {
            return aa.ID - bb.ID;
        }
    }
    else
    {
        if(aa.total != bb.total)
        {
            return bb.total - aa.total;
        }
        else if(aa.Chinese != bb.Chinese)
        {
            return bb.Chinese - aa.Chinese;
        }
        else if(aa.English != bb.English)
        {
            return bb.English - aa.English;
        }
        else if(aa.math != bb.math)
        {
            return bb.math - aa.math;
        }
        else if(aa.science != bb.science)
        {
            return bb.science - aa.science;
        }
        else
        {
            return aa.ID - bb.ID;
        }
    }
}
void sortGrade(Grade *gList, int n, char *order)
{
    int i;
    for(i=0;i<n;i++)
    {
        gList[i].total = gList[i].Chinese + gList[i].English + gList[i].math + gList[i].science;
    }
    directions = order[0];
    qsort(gList,n,sizeof(Grade),compare);
}
