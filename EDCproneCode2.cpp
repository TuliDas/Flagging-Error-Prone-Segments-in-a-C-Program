#include<stdio.h>

int main()
{
    int i,j,k;
    for(i=0; i<1000000; i++)
    {
        k = i + i ;
    }
    for(i=0; i<100000; i++)
    {
        for(j=0; j<10; j++)
        {
            k = i + j ;
        }
    }

    return 0;
}

