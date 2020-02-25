static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include <chrono>
long long getTicks(){return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();}
#include<stdio.h>
void fun()
{auto startTime5 = getTicks();
    int i = 0;
    int b =10;
    int a = b + 1 ;
printf("Time = %lld , ( 5 , 10 ) \n", getTicks() - startTime5);}
void fun2()
{auto startTime11 = getTicks();
    int i = 0;
    int b =10;
    int a = b + 1 ;
    i = 0;
     b =10;
    a = b + 1 ;
printf("Time = %lld , ( 11 , 19 ) \n", getTicks() - startTime11);}
int main()
{ freopen("Output.txt", "w+", stdout);auto startTime20 = getTicks();
    fun();
    fun2();
printf("Time = %lld , ( 20 , 25 ) \n", getTicks() - startTime20);    return 0;
printf("Time = %lld , ( 20 , 25 ) \n", getTicks() - startTime20);}
