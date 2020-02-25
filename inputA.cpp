static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include <chrono>
long long getTicks(){return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();}
#include<stdio.h>
void fun()
{
    int i=0;
    i=1;
    i=2;
    return;
}
void fun2()
{
  int i ;
  for(i=0;i<=100000;i++)
  {
      int a = i * 2;
  }
}
int main()
{ freopen("Output.txt", "w+", stdout);
    int i,j,k;
    for(i=0; i<5; i++)
    {
        for(j=0; j<10; j++)
        {
            int a = i+j;
        }
    }
    for(i=0; i<1000000; i++)
    {
        int a = i+i;
    }
    k = 10;
    if (k>0)
    {
        for(i=0;i<100;i++)
        {
             j = j + i;
        }
    }
    if(k==10)
    {
        for(i=0;i<500;i++)
        {
             j = j + i;
        }
    }
    fun();
    fun2();
    return 0;
}
