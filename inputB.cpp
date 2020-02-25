static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include <chrono>
long long getTicks(){return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();}
#include<stdio.h>
int main()
{ freopen("Output.txt", "w+", stdout);
printf("line = %d\n",__LINE__);    int i,j,k;
    for(i=0; i<1000000; i++)
    {
printf("line = %d\n",__LINE__);        k = i + i ;
    }
    for(i=0; i<100000; i++)
    {
        for(j=0; j<10; j++)
        {
printf("line = %d\n",__LINE__);            k = i + j ;
        }
    }
printf("line = %d\n",__LINE__);    return 0;
}
