#include<stdio.h>

int fun2(int d,int e,int f)
{
    int a = d + e + f ;
    return a ;
}

int fun(int x,int y,int z)
{
    int a;
    int b;
    int ans = fun2(x,y,z);
    return ans;
}

void fun3()
{
    int a;
    int b;
    int c;
}

int main()
{
    int z;
    z = fun(1,2,3);
    z = fun(4,5,6);
    z = fun(7,8,8);
    fun3();
    return 0;
}
