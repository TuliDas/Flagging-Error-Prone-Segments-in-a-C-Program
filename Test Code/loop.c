#include<stdio.h>

int main()
{
    int i,j,k;
    for(i=0; i<5; i++)
    {
        for(j=0; j<10; j++)
        {
            int a = i+j;
            printf("summation is %d: \n",a);
        }
    }
    for(i=0; i<40; i++)
    {
        int a = i+i;
        printf("summation is %d: \n",a);
    }
    return 0;
}

