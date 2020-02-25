#include<stdio.h>

int main()
{
    int i,j,k;
    for(i=0; i<5; i++)
    {
        for(j=0; j<10; j++)
        {
            int a = i+j;
        }
    }
    for(i=0; i<1000000; i++)
    {
        int a = i+i;
    }
    return 0;
}


