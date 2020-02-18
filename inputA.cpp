static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include<stdio.h>
#include<iostream>
using namespace std;
int abc;
int ttt;
void FuctionTerminatingBranch(int s,int e)
{
    if(s<0 || e>=100)
    {
        return;
    }
    int sum = 0 ;
    int ara[100];
    for(int i=s;i<=e;i++)
    {
        ara[i] = s ;
    }
    for(int i=s;i<=e;i++)
    {
        printf("%d\n",ara[i]);
    }
}
bool checkOddEven(int num)
{
    if(num%2==0)
    {
        return 0;
    }
    return 1;
}
int main()
{ freopen("Output.txt", "w+", stdout);
    int a = 10;
    int testAra[100];
    int temp = 0 ;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            temp += checkOddEven(j);
            testAra[i] = temp ;
        }
    }
    FuctionTerminatingBranch(2,20);
    int z = 1000;
    while(z--)
    {
        int t = 10;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
             int a = checkOddEven(j);
            for(int k=0;k<3;k++)
            {
                
                printf("%d %d %d\n",i,j,k);
            }
        }
    }
    if(a == 10)
    {
        int b = 10;
        int c = b + 1;
        int s = b + c;
    }
    else if (a == 20)
    {
        int b = 15;
        int c = b++;
        int s = c++;
        int t = 100;
    }
    else
    {
        int b = 15;
        int c = b+10;
        int s = c+15;
        int t = 100;
    }
    return 0;
}
