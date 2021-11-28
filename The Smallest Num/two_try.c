#include<stdio.h>
#define N 1000000
#define WORD_LENGTH (sizeof(int) * 8)

/*
 * 哎
 * 抄书的部分很多
 * 毕竟bit--一生之敌
 * 
 */

int lst[16] = {18, 4, 8, 10, 16, 1, 14, 7, 19, 3, 0, 5, 2, 11, 6};

void setbit(unsigned int *bits, unsigned int i)
{
    bits[i / WORD_LENGTH] |= 1 << (i % WORD_LENGTH);
}

int testbit(unsigned int *bits, unsigned int i)
{
    return bits[i / WORD_LENGTH] & (1 << (i % WORD_LENGTH));
}

unsigned int bits[N / WORD_LENGTH];

int minfree(int* xs, int n)
{
    int i, len = N / WORD_LENGTH + 1;
    for (i = 0; i < len; ++i)
        bits[i] = 0;
    for (i = 0; i < n; ++i)
        if(xs[i] < n)
            setbit(bits, xs[i]);
    for (i = 0; i < n; ++i)
        if(!testbit(bits, i))
            return i;
}
int main()
{
    int *looken = lst;
    printf("%d", minfree(looken, 15));
    return 0;
}
