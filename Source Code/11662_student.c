#include <stdio.h>
#define MAXNV 5
int DONE = 0;
int liters[MAXNV];
int numbers[MAXNV];
void show(int nv);
void filling(int amount, int cur, int nv);
int j=0;
int water;
int min=100;
int min_numbers[MAXNV]= {0};
int total = 0;
int main(void)
{
    int nv, i;

    scanf("%d", &nv);
    for (i=0; i<nv; i++)
    {
        scanf("%d", &liters[i]);
    }
    scanf("%d", &water);
    filling(water, 0, nv);

    for(i=0; i<nv; i++)
        numbers[i]=min_numbers[i];
    show(nv);
    return 0;
}

void show(int nv)
{
    int i;
    printf("(%d", numbers[0]);
    for (i=1; i<nv; i++)
    {
        printf(",%d", numbers[i]);
    }
    printf(")\n");
}

void filling(int amount, int cur, int nv)
{
    int i;
    int a = amount;
    if(amount==0 && total == 0)
    {
        show(nv);

        total++;
    }
    if(amount<liters[nv-1])
        return ;
    for(i=cur; i<nv; i++)
    {
        if(liters[i]<=amount)
        {
            if(liters[i]<=amount)
            {
                numbers[i]++;
                filling(amount-liters[i],i,nv);
                numbers[i]--;
            }
        }
    }

}