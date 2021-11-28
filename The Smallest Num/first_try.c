#include<stdio.h>
#include<iostream>

int lst[16] = {18, 4, 8, 10, 16, 1, 14, 7, 19, 3, 0, 5, 2, 11, 6};
int minfree(int[],int);
int minfree_enforce(int[]);
int main()
{
    int lst_length = sizeof(lst) / sizeof(int);
    int res = minfree(lst, lst_length);
    printf("%d\n", res);
    return 0;
}
int minfree(int lst[], int length)
{
    int x = 0, i, j;
    while(1)
    {
        for (i = 0;; ++i)
        {
            x = 0;
            for(j = 0; j <= length; ++ j)
            {
                if(i == lst[j])
                    x = 1;
            } 
            if (!x)
                return i;
        }
        return -1;
    }
}
