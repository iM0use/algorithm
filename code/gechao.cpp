#include<stdio.h>
#include<iostream>
using namespace std;
#define LL long long
int main()
{
    LL n,sum;
    while(scanf("%lld", &n)!=EOF)
    {
        sum=n/2+n/5+n/11+n/13;
        LL ccc=sum-n/10-n/22-n/26-n/55-n/65-n/143+n/110+n/130+n/286+n/715-n/1430;
        LL res=n-ccc;
        printf("%lld\n", res);
    }
    return 0;
}
