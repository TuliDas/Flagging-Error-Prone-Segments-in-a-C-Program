static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include <chrono>
long long getTicks(){return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();}
#include<stdio.h>
void fun()
{auto startTime5 = getTicks();
    int i=0;
    i=1;
    i=2;
printf("Time = %lld , ( 5 , 11 ) \n", getTicks() - startTime5);    return;
printf("Time = %lld , ( 5 , 11 ) \n", getTicks() - startTime5);}
void fun2()
{auto startTime12 = getTicks();
  int i ;
auto startTime15 = getTicks();  for(i=0;i<=100000;i++)
  {
      int a = i * 2;
  }printf("Time = %lld , ( 15 , 18 ) \n", getTicks() - startTime15);
printf("Time = %lld , ( 12 , 19 ) \n", getTicks() - startTime12);}
int main()
{ freopen("Output.txt", "w+", stdout);auto startTime20 = getTicks();
    int i,j,k;
auto startTime23 = getTicks();    for(i=0; i<5; i++)
    {
auto startTime25 = getTicks();        for(j=0; j<10; j++)
        {
            int a = i+j;
        }printf("Time = %lld , ( 25 , 28 ) \n", getTicks() - startTime25);
    }printf("Time = %lld , ( 23 , 29 ) \n", getTicks() - startTime23);
auto startTime30 = getTicks();    for(i=0; i<1000000; i++)
    {
        int a = i+i;
    }printf("Time = %lld , ( 30 , 33 ) \n", getTicks() - startTime30);
    k = 10;
    if (k>0)
    {auto startTime35 = getTicks();
auto startTime37 = getTicks();        for(i=0;i<100;i++)
        {
             j = j + i;
        }printf("Time = %lld , ( 37 , 40 ) \n", getTicks() - startTime37);
printf("Time = %lld , ( 35 , 41 ) \n", getTicks() - startTime35);    }
    if(k==10)
    {auto startTime42 = getTicks();
auto startTime44 = getTicks();        for(i=0;i<500;i++)
        {
             j = j + i;
        }printf("Time = %lld , ( 44 , 47 ) \n", getTicks() - startTime44);
printf("Time = %lld , ( 42 , 48 ) \n", getTicks() - startTime42);    }
    fun();
    fun2();
printf("Time = %lld , ( 20 , 52 ) \n", getTicks() - startTime20);    return 0;
printf("Time = %lld , ( 20 , 52 ) \n", getTicks() - startTime20);}
