static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include <chrono>
long long getTicks(){return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();}
#include<stdio.h>
#include<iostream>
using namespace std;
int abc;
int ttt;
void FuctionTerminatingBranch(int s,int e)
{auto startTime9 = getTicks();
    if(s<0 || e>=100)
    {auto startTime11 = getTicks();
printf("Time = %lld , ( 9 , 25 ) \n", getTicks() - startTime9);        return;
printf("Time = %lld , ( 11 , 14 ) \n", getTicks() - startTime11);    }
    int sum = 0 ;
    int ara[100];
auto startTime17 = getTicks();    for(int i=s;i<=e;i++)
    {
        ara[i] = s ;
    }printf("Time = %lld , ( 17 , 20 ) \n", getTicks() - startTime17);
auto startTime21 = getTicks();    for(int i=s;i<=e;i++)
    {
        printf("%d\n",ara[i]);
    }printf("Time = %lld , ( 21 , 24 ) \n", getTicks() - startTime21);
printf("Time = %lld , ( 9 , 25 ) \n", getTicks() - startTime9);}
bool checkOddEven(int num)
{auto startTime26 = getTicks();
    if(num%2==0)
    {auto startTime28 = getTicks();
printf("Time = %lld , ( 26 , 33 ) \n", getTicks() - startTime26);        return 0;
printf("Time = %lld , ( 28 , 31 ) \n", getTicks() - startTime28);    }
printf("Time = %lld , ( 26 , 33 ) \n", getTicks() - startTime26);    return 1;
printf("Time = %lld , ( 26 , 33 ) \n", getTicks() - startTime26);}
int main()
{ freopen("Output.txt", "w+", stdout);
    int a = 10;
 int testAra[100000];
    int temp = 0 ;
auto startTime39 = getTicks();    for(int i=0;i<5;i++)
    {
auto startTime41 = getTicks();        for(int j=0;j<5;j++)
        {
            temp += checkOddEven(j);
            testAra[i] = temp ;
        }printf("Time = %lld , ( 41 , 45 ) \n", getTicks() - startTime41);
    }    printf("Time = %lld , ( 39 , 46 ) \n", getTicks() - startTime39);
    FuctionTerminatingBranch(2,20);
    int z = 13;
auto startTime49 = getTicks();    while(z--)
    {
        int t = 10;
    }printf("Time = %lld , ( 49 , 52 ) \n", getTicks() - startTime49);
auto startTime53 = getTicks();    for(int i=0;i<3;i++)
    {
auto startTime55 = getTicks();        for(int j=0;j<3;j++)
        {
             int a = checkOddEven(j);
auto startTime58 = getTicks();            for(int k=0;k<3;k++)
            {
                
                printf("%d %d %d\n",i,j,k);
            }printf("Time = %lld , ( 58 , 62 ) \n", getTicks() - startTime58);
        }printf("Time = %lld , ( 55 , 63 ) \n", getTicks() - startTime55);
    }printf("Time = %lld , ( 53 , 64 ) \n", getTicks() - startTime53);
    if(a == 10)
    {auto startTime65 = getTicks();
        int b = 10;
        int c = b + 1;
        int s = b + c;
printf("Time = %lld , ( 65 , 70 ) \n", getTicks() - startTime65);    }
    else if (a == 100)
    {auto startTime71 = getTicks();
auto startTime73 = getTicks();            for(int i=0;i<=1000;i++)
            {
                int xx = i;
            }printf("Time = %lld , ( 73 , 76 ) \n", getTicks() - startTime73);
printf("Time = %lld , ( 71 , 77 ) \n", getTicks() - startTime71);    }
    else
    {auto startTime78 = getTicks();
        int b = 15;
        int c = b+10;
        int s = c+15;
        int t = 100;
printf("Time = %lld , ( 78 , 84 ) \n", getTicks() - startTime78);    }
    return 0;
}
