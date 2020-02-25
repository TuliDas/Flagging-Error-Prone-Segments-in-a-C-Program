static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include <chrono>
long long getTicks(){return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();}
#include<stdio.h>
int main()
{ freopen("Output.txt", "w+", stdout);
    int i,j,k;
    for(i=0; i<1000000; i++)
    {
        k = i + i ;
    }
    for(i=0; i<100000; i++)
    {
        for(j=0; j<10; j++)
        {
            k = i + j ;
        }
    }
    return 0;
}
