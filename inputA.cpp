static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include <chrono>
long long getTicks(){return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();}
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
{ freopen("Output.txt", "w+", stdout);
    fun();
    fun2();
    return 0;
}
