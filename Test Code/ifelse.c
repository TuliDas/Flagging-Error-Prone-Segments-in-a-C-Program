#include<stdio.h>

int main()
{
    int a= 10;
    if(a==10)
    {
        int x = 1000;
        int y = x + a;
    }
    if(a==10)
    {
        int x = 5;
        int y = 6;
        int z = x + y;
        x = z + x + y;
    }

    return 0;
}


