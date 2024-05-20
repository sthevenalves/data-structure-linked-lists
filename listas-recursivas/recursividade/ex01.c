#include<stdio.h>
#include<stdlib.h>

int fat(int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n == 0)
    {
        return 1;
    }
    return n + (fat(n-1));
}

int main()
{
    int fatn=0;
    fatn = fat(5);
    printf("%d", fatn);

    return 0;
}