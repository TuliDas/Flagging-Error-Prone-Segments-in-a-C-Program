#include<stdio.h>
#include<iostream>
using namespace std;

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
{
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



    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                 int a = checkOddEven(k);
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