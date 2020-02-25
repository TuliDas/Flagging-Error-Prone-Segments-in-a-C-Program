static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include <chrono>
long long getTicks(){return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();}
#include<stdio.h>
void fun()
{printf("function_start_id %d line = %d\n", ++global_function_id, __LINE__);
printf("line = %d\n",__LINE__);    int i=0;
printf("line = %d\n",__LINE__);    i=1;
printf("line = %d\n",__LINE__);    i=2;
printf("line = %d\n",__LINE__);printf("function_end_id %d line = %d\n", global_function_id--, __LINE__);    return;
printf("function_end_id %d line = %d\n", global_function_id--, __LINE__);}
void fun2()
{printf("function_start_id %d line = %d\n", ++global_function_id, __LINE__);
printf("line = %d\n",__LINE__);  int i ;
printf("loop_start_id %d line = %d\n", ++global_loop_id, __LINE__);  for(i=0;i<=100000;i++)
  {
printf("line = %d\n",__LINE__);      int a = i * 2;
  }printf("loop_end_id %d line = %d\n", global_loop_id--, __LINE__);
printf("function_end_id %d line = %d\n", global_function_id--, __LINE__);}
int main()
{ freopen("Output.txt", "w+", stdout);printf("function_start_id %d line = %d\n", ++global_function_id, __LINE__);
printf("line = %d\n",__LINE__);    int i,j,k;
printf("loop_start_id %d line = %d\n", ++global_loop_id, __LINE__);    for(i=0; i<5; i++)
    {
printf("loop_start_id %d line = %d\n", ++global_loop_id, __LINE__);        for(j=0; j<10; j++)
        {
printf("line = %d\n",__LINE__);            int a = i+j;
        }printf("loop_end_id %d line = %d\n", global_loop_id--, __LINE__);
    }printf("loop_end_id %d line = %d\n", global_loop_id--, __LINE__);
printf("loop_start_id %d line = %d\n", ++global_loop_id, __LINE__);    for(i=0; i<1000000; i++)
    {
printf("line = %d\n",__LINE__);        int a = i+i;
    }printf("loop_end_id %d line = %d\n", global_loop_id--, __LINE__);
printf("line = %d\n",__LINE__);    k = 10;
    if (k>0)
    {printf("ifelse_start_id %d line = %d\n", ++global_ifelse_id, __LINE__);
printf("loop_start_id %d line = %d\n", ++global_loop_id, __LINE__);        for(i=0;i<100;i++)
        {
printf("line = %d\n",__LINE__);             j = j + i;
        }printf("loop_end_id %d line = %d\n", global_loop_id--, __LINE__);
printf("ifelse_end_id %d line = %d\n", global_ifelse_id--, __LINE__);    }
    if(k==10)
    {printf("ifelse_start_id %d line = %d\n", ++global_ifelse_id, __LINE__);
printf("loop_start_id %d line = %d\n", ++global_loop_id, __LINE__);        for(i=0;i<500;i++)
        {
printf("line = %d\n",__LINE__);             j = j + i;
        }printf("loop_end_id %d line = %d\n", global_loop_id--, __LINE__);
printf("ifelse_end_id %d line = %d\n", global_ifelse_id--, __LINE__);    }
printf("line = %d\n",__LINE__);    fun();
printf("line = %d\n",__LINE__);    fun2();
printf("line = %d\n",__LINE__);printf("function_end_id %d line = %d\n", global_function_id--, __LINE__);    return 0;
printf("function_end_id %d line = %d\n", global_function_id--, __LINE__);}
