#include <stdio.h>
#define MAXNV 5
int DONE = 0;
int liters[MAXNV];
int numbers[MAXNV];
void show(int nv);
void filling(int amount, int cur, int nv);
int j=0;
int water;
int min=2147483647;
int min_numbers[MAXNV]={0};
int main(void)
{
    int nv, i;

    scanf("%d", &nv);
    for (i=0; i<nv; i++) {
        scanf("%d", &liters[i]);
    }
    scanf("%d", &water);
    filling(water, 0, nv);

    for(i=0;i<nv;i++)
        numbers[i]=min_numbers[i];
    show(nv);
    return 0;
}

void show(int nv)
{
    int i;
    printf("(%d", numbers[0]);
    for (i=1; i<nv; i++) {
        printf(",%d", numbers[i]);
    }
    printf(")\n");
}

void filling(int amount, int cur, int nv)
{
    /* your code */
    if (cur<nv) {
		if (amount == 0) {
            if(j < min)
            {
                //show(nv);
                //printf("Min: %d\n",j);
                for(int i=0;i<nv;i++)
                {
                    for(i=0;i<nv;i++)
                        min_numbers[i]=numbers[i];
                }
                min = j;
            }

		} else if (amount > 0) {
			filling(amount, cur+1, nv);
			numbers[cur]++;
			j++;
			filling(amount-liters[cur], cur, nv);
			numbers[cur]--;
			j--;
		}
	}
}
