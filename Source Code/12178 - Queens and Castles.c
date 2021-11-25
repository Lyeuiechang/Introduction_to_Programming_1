#include <stdio.h>
const char Rook='R';
const char Queen='Q';
const char OnlyRook='O';
int M,N,cnt=0;
char chess[11][2] = {0};
void Search(int i,int Q,int R)
{
    int j;
    if(i==M+N)
    {
        cnt++;
        return;
    }
    char able_put[M+N];
    for(j=0;j<M+N;j++)
    {
        able_put[j]=1;
    }
    memset(able_put,1,sizeof(able_put));
    for(j=0;j<i;j++)
    {
        int posB=i-j+chess[j][1],posT=chess[j][1]-(i-j);
        if(chess[j][0]==Rook)
        {
            able_put[chess[j][1]]=0;
            if(able_put[posB]==1&&posB<M+N)
                able_put[posB]=OnlyRook;
            if(able_put[posT]==1&&posT>=0)
                able_put[posT]=OnlyRook;
        }
        else if(chess[j][0]==Queen)
        {
            able_put[chess[j][1]]=0;
            if(able_put[posB]&&posB<M+N)
                able_put[posB]=0;
            if(able_put[posT]&&posT>=0)
                able_put[posT]=0;
        }
    }
    for(j=0;j<M+N;j++)
    {
        if(able_put[j]!=0)
        {
            chess[i][1]=j;
            if(R>0)
            {
                chess[i][0]=Rook;
                Search(i+1,Q,R-1);
                chess[i][0]=0;
            }
            if(able_put[j]!=OnlyRook&&Q>0)
            {
                chess[i][0]=Queen;
                Search(i+1,Q-1,R);
                chess[i][0]=0;
            }
            chess[i][1]=0;
        }
    }
}
int main(void)
{
    scanf("%d %d",&M,&N);
    cnt=0;
    Search(0,M,N);
    printf("%d\n",cnt);
    return 0;
}
