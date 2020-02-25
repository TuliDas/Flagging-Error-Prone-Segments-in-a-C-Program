#include<stdio.h>

void fun()
{
    int i = 0;
    int b =10;
    int a = b + 1 ;
}
void fun2()
{
    int i = 0;
    int b =10;
    int a = b + 1 ;
    i = 0;
     b =10;
    a = b + 1 ;
}

int main()
{
    fun();
    fun2();
    return 0;
}




