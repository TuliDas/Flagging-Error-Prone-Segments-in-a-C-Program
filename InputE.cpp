static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include <chrono>
long long getTicks(){return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();}
#include<stdio.h>
int main()
{ freopen("Output.txt", "w+", stdout);
    int i,j,k;
auto startTime8 = getTicks();    for(i=0; i<1000000; i++)
    {
        k = i + i ;
    }printf("Time = %lld , ( 8 , 11 ) \n", getTicks() - startTime8);
auto startTime12 = getTicks();    for(i=0; i<100000; i++)
    {
auto startTime14 = getTicks();        for(j=0; j<10; j++)
        {
            k = i + j ;
        }printf("Time = %lld , ( 14 , 17 ) \n", getTicks() - startTime14);
    }printf("Time = %lld , ( 12 , 18 ) \n", getTicks() - startTime12);
    return 0;
}
