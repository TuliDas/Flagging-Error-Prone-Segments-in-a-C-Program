static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include <chrono>
long long getTicks(){return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int fun2(int d,int e,int f)
{
    int a = d + e + f ;
    return a ;
}
int fun(int x,int y,int z)
{
    int a;
    int b;
    int c;
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
{ freopen("Output.txt", "w+", stdout);
    int n = 10;
    for(int i=1;i<=5;i++)
    {
        int z = fun(i,i,i);
    }
    fun3();
    fun3();
    return 0;
}
