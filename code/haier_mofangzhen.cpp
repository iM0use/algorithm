#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
#define N 50
int n, aa[N][N], i, j, k, n_q_4, x0, x1;
int yz;
int main()
{
    /*
     * n 可以整除 4
     * n = 1 个边上的数目
     */
    scanf("%d", &n);
    n_q_4 = n / 4;
    for (i = 1; i <= n; ++ i)
        for (j = 1; j <= n; ++ j)
            aa[i][j] = (i - 1) * n + j;
    for (i = 1; i <= n; ++ i)
    {
        for (j = 1; j <= n; ++ j)
            printf("%4d", aa[i][j]);
        printf("\n");
    }
    printf("\n");
    for (i = 1; i <= n_q_4; ++i)
    {
        for (j = 1; j <= n_q_4; ++j)
        {
            x0 = (i - 1) * 4 + 1;
            yz = (j - 1) * 4 + 1;
            for (k = 0; k <= 3; ++k)
                //aa[x0 + k][yz + k] = n * n + 1 - aa[x0 + k][yz + k];
                printf("%d %d\n", aa[x0 + k][yz + k], aa[n + 1 - x0 - k][n + 1 - yz - k]);
                swap(aa[x0 + k][yz + k], aa[n + 1 - x0 - k][n + 1 - yz - k]);
                //aa[x0 + k][yz + k] ^= aa[n + 1 - x0 - k][n + 1 - yz - k] ^= aa[x0 + k][yz + k] ^= aa[n + 1 - x0 - k][n + 1 - yz - k];

            x0 = i * 4;
            for (k = 0; k <= 3; ++k)
                //aa[x0 - k][yz + k] = n * n + 1 - aa[x0 - k][yz + k];
                swap(aa[x0 - k][yz + k], aa[n + 1 - x0 + k][n + 1 - yz - k]);
                //aa[x0 - k][yz + k] ^= aa[n + 1 - x0 + k][n + 1 - yz - k] ^= aa[x0 - k][yz + k] ^= aa[n + 1 - x0 + k][n + 1 - yz - k];
        }
    }
    // for (i = 1; i <= n; ++ i)
    // {
    //     for (j = 1; j <= n; ++ j)
    //         printf("%4d", aa[i][j]);
    //     printf("\n");
    // }
        
    return 0;
}
