static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include <chrono>
long long getTicks(){return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();}
#include<stdio.h>
void fun()
{
printf("line = %d\n",__LINE__);    int i=0;
printf("line = %d\n",__LINE__);    i=1;
printf("line = %d\n",__LINE__);    i=2;
printf("line = %d\n",__LINE__);    return;
}
void fun2()
{
printf("line = %d\n",__LINE__);  int i ;
  for(i=0;i<=100000;i++)
  {
printf("line = %d\n",__LINE__);      int a = i * 2;
  }
}
int main()
{ freopen("Output.txt", "w+", stdout);
printf("line = %d\n",__LINE__);    int i,j,k;
    for(i=0; i<5; i++)
    {
        for(j=0; j<10; j++)
        {
printf("line = %d\n",__LINE__);            int a = i+j;
        }
    }
    for(i=0; i<1000000; i++)
    {
printf("line = %d\n",__LINE__);        int a = i+i;
    }
printf("line = %d\n",__LINE__);    k = 10;
    if (k>0)
    {
        for(i=0;i<100;i++)
        {
printf("line = %d\n",__LINE__);             j = j + i;
        }
    }
    if(k==10)
    {
        for(i=0;i<500;i++)
        {
printf("line = %d\n",__LINE__);             j = j + i;
        }
    }
printf("line = %d\n",__LINE__);    fun();
printf("line = %d\n",__LINE__);    fun2();
printf("line = %d\n",__LINE__);    return 0;
}
