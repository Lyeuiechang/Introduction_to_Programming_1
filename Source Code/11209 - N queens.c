#include <stdio.h>


int n;
int count;
int cols[20];
int diag[20];  // col + row
int diag2[20];  // col - row + (n - 1)

void nqueen(int row)
{
    for (int col = 0; col < n; col++)
    {
        if (cols[col])
            continue;
        if (diag[col+row])
            continue;
        if (diag2[col-row+n-1])
            continue;

        // Check before entering the next depth. This is faster.
        if (row + 1 == n)
        {
            count++;
            return;
        }

        cols[col] = diag[col+row] = diag2[col-row+n-1] = 1;
        nqueen(row + 1);
        cols[col] = diag[col+row] = diag2[col-row+n-1] = 0;
    }
}

int main(void)
{
    scanf("%d",&n);
    nqueen(0);
    printf("%d", count);
    return 0;
}
