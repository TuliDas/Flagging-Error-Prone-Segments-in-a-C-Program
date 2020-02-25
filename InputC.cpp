static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include <chrono>
long long getTicks(){return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();}
#include<stdio.h>
int main()
{ freopen("Output.txt", "w+", stdout);
printf("line = %d\n",__LINE__);    int i,j,k;
printf("loop_start_id %d line = %d\n", ++global_loop_id, __LINE__);    for(i=0; i<1000000; i++)
    {
printf("line = %d\n",__LINE__);        k = i + i ;
    }printf("loop_end_id %d line = %d\n", global_loop_id--, __LINE__);
printf("loop_start_id %d line = %d\n", ++global_loop_id, __LINE__);    for(i=0; i<100000; i++)
    {
printf("loop_start_id %d line = %d\n", ++global_loop_id, __LINE__);        for(j=0; j<10; j++)
        {
printf("line = %d\n",__LINE__);            k = i + j ;
        }printf("loop_end_id %d line = %d\n", global_loop_id--, __LINE__);
    }printf("loop_end_id %d line = %d\n", global_loop_id--, __LINE__);
printf("line = %d\n",__LINE__);    return 0;
}
