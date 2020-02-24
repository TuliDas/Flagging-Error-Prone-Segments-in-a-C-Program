static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include <chrono>
long long getTicks(){return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int fun2(int d,int e,int f)
{auto startTime7 = getTicks();
    int a = d + e + f ;
printf("Time = %lld , ( 7 , 11 ) \n", getTicks() - startTime7);    return a ;
printf("Time = %lld , ( 7 , 11 ) \n", getTicks() - startTime7);}
int fun(int x,int y,int z)
{auto startTime12 = getTicks();
    int a;
    int b;
    int c;
    int ans = fun2(x,y,z);
printf("Time = %lld , ( 12 , 19 ) \n", getTicks() - startTime12);    return ans;
printf("Time = %lld , ( 12 , 19 ) \n", getTicks() - startTime12);}
void fun3()
{auto startTime20 = getTicks();
    int a;
    int b;
    int c;
printf("Time = %lld , ( 20 , 25 ) \n", getTicks() - startTime20);}
int main()
{ freopen("Output.txt", "w+", stdout);
    int n = 10;
auto startTime29 = getTicks();    for(int i=1;i<=5;i++)
    {
        int z = fun(i,i,i);
    }printf("Time = %lld , ( 29 , 32 ) \n", getTicks() - startTime29);
    fun3();
    fun3();
    return 0;
}
