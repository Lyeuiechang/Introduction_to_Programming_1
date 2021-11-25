#include<stdio.h>
int main(void)
{
    int n, k, i, current_length, change, checkpoint_prev, checkpoint_next, failed;
    int checkpoint[100001]= {0};
    scanf("%d %d", &n, &k);
    checkpoint_prev = 0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&checkpoint_next);
        checkpoint[i] = checkpoint_next - checkpoint_prev;
        checkpoint_prev = checkpoint_next;
    }
    /*for(i=0;i<n;i++)
    {
        printf("%d ",checkpoint[i]);
    }*/
    current_length = 0;
    change = 0;
    failed = 0;
    for(i=0;i<n;i++)
    {
        if(checkpoint[i] > k)
        {
            printf("The Legend Falls.\n");
            failed = 1;
            break;
        }
        //current_length = current_length + checkpoint[i];
        if(current_length + checkpoint[i] > k)
        {
            change++;
            current_length = checkpoint[i];
        }
        else
        {
            current_length = current_length + checkpoint[i];
        }
    }
    if(failed == 0)
    {
        printf("%d\n",change);
    }
    return 0;
}
