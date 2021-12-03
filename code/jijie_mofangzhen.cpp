#include<stdio.h>
#define MM 105
int jjing[MM][MM];
int main()
{
    int n, i, j, k;
    scanf("%d", &n);
    int x = 1, y = (n + 1) / 2, x1, y1;
    jjing[x][y] = 1;
    for (i = 2; i <= n * n; ++ i)
    {
        x1 = (x - 1 > 0) ? (x - 1) : (x - 1 + n);
        y1 = (y + 1 <= n) ? (y + 1) : (y + 1 - n);
        //x1 = x - 1, y1 = y + 1;
        if(jjing[x1][y1])
        {
            jjing[x + 1][y] = i;
            //printf("jjing[%d][%d] = %d\n", x + 1, y, jjing[x + 1][y]);
            x++;
        }
        else
        {
            jjing[x1][y1] = i;
            //printf("jjing[%d][%d] = %d\n", x1, y1, jjing[x1][y1]);
            x=x1;
            y=y1;
        }  
    }
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
            printf("%4d", jjing[i][j]);
        printf("\n");
    }
    return 0;
}
