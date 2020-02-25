static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include <chrono>
long long getTicks(){return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();}
#include<stdio.h>
void fun()
{
printf("line = %d\n",__LINE__);    int i = 0;
printf("line = %d\n",__LINE__);    int b =10;
printf("line = %d\n",__LINE__);    int a = b + 1 ;
}
void fun2()
{
printf("line = %d\n",__LINE__);    int i = 0;
printf("line = %d\n",__LINE__);    int b =10;
printf("line = %d\n",__LINE__);    int a = b + 1 ;
printf("line = %d\n",__LINE__);    i = 0;
printf("line = %d\n",__LINE__);     b =10;
printf("line = %d\n",__LINE__);    a = b + 1 ;
}
int main()
{ freopen("Output.txt", "w+", stdout);
printf("line = %d\n",__LINE__);    fun();
printf("line = %d\n",__LINE__);    fun2();
printf("line = %d\n",__LINE__);    return 0;
}
