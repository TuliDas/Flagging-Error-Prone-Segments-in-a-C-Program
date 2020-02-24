static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include <chrono>
long long getTicks(){return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();}
#include<stdio.h>
#include<iostream>
int abc;
int ttt;
void FuctionTerminatingBranch(int s,int e)
{auto startTime8 = getTicks();
    if(s<0 || e>=100)
    {auto startTime10 = getTicks();
printf("Time = %lld , ( 8 , 24 ) \n", getTicks() - startTime8);        return;
printf("Time = %lld , ( 10 , 13 ) \n", getTicks() - startTime10);    }
    int sum = 0 ;
    int ara[100];
auto startTime16 = getTicks();    for(int i=s;i<=e;i++)
    {
        ara[i] = s ;
    }printf("Time = %lld , ( 16 , 19 ) \n", getTicks() - startTime16);
auto startTime20 = getTicks();    for(int i=s;i<=e;i++)
    {
        printf("%d\n",ara[i]);
    }printf("Time = %lld , ( 20 , 23 ) \n", getTicks() - startTime20);
printf("Time = %lld , ( 8 , 24 ) \n", getTicks() - startTime8);}
bool checkOddEven(int num)
{auto startTime25 = getTicks();
    if(num%2==0)
    {auto startTime27 = getTicks();
printf("Time = %lld , ( 25 , 32 ) \n", getTicks() - startTime25);        return 0;
printf("Time = %lld , ( 27 , 30 ) \n", getTicks() - startTime27);    }
printf("Time = %lld , ( 25 , 32 ) \n", getTicks() - startTime25);    return 1;
printf("Time = %lld , ( 25 , 32 ) \n", getTicks() - startTime25);}
int main()
{ freopen("Output.txt", "w+", stdout);
    int a = 10;
 int testAra[100000];
    int temp = 0 ;
auto startTime38 = getTicks();    for(int i=0;i<5;i++)
    {
auto startTime40 = getTicks();        for(int j=0;j<5;j++)
        {
            temp += checkOddEven(j);
            testAra[i] = temp ;
        }printf("Time = %lld , ( 40 , 44 ) \n", getTicks() - startTime40);
    }    printf("Time = %lld , ( 38 , 45 ) \n", getTicks() - startTime38);
    FuctionTerminatingBranch(2,20);
    int z = 13;
auto startTime48 = getTicks();    while(z--)
    {
        int t = 10;
    }printf("Time = %lld , ( 48 , 51 ) \n", getTicks() - startTime48);
auto startTime52 = getTicks();    for(int i=0;i<3;i++)
    {
auto startTime54 = getTicks();        for(int j=0;j<3;j++)
        {
             int a = checkOddEven(j);
auto startTime57 = getTicks();            for(int k=0;k<3;k++)
            {
                
                printf("%d %d %d\n",i,j,k);
            }printf("Time = %lld , ( 57 , 61 ) \n", getTicks() - startTime57);
        }printf("Time = %lld , ( 54 , 62 ) \n", getTicks() - startTime54);
    }printf("Time = %lld , ( 52 , 63 ) \n", getTicks() - startTime52);
    if(a == 10)
    {auto startTime64 = getTicks();
        int b = 10;
        int c = b + 1;
        int s = b + c;
printf("Time = %lld , ( 64 , 69 ) \n", getTicks() - startTime64);    }
    else if (a == 100)
    {auto startTime70 = getTicks();
auto startTime72 = getTicks();            for(int i=0;i<=1000;i++)
            {
                int xx = i;
            }printf("Time = %lld , ( 72 , 75 ) \n", getTicks() - startTime72);
printf("Time = %lld , ( 70 , 76 ) \n", getTicks() - startTime70);    }
    else
    {auto startTime77 = getTicks();
        int b = 15;
        int c = b+10;
        int s = c+15;
        int t = 100;
printf("Time = %lld , ( 77 , 83 ) \n", getTicks() - startTime77);    }
    return 0;
}
