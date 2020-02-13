#include<stdio.h>
#include<iostream>
using namespace std;
//H3//
void FuctionTerminatingBranch(int s,int e)
{
    if(s<0 || e>=100)
printf("line = %d\n",__LINE__);    return;
printf("line = %d\n",__LINE__);    int sum = 0 ;
printf("line = %d\n",__LINE__);    int ara[100];
    for(int i=s;i<=e;i++)
    {
printf("line = %d\n",__LINE__);        ara[i] = s ;
    }
    for(int i=s;i<=e;i++)
    {
printf("line = %d\n",__LINE__);        printf("%d\n",ara[i]);
    }
}
bool checkOddEven(int num)
{
    if(num%2==0)
printf("line = %d\n",__LINE__);        return 0;
printf("line = %d\n",__LINE__);    return 1;
}
int main()
{
printf("line = %d\n",__LINE__);freopen("outputC.txt", "w+", stdout);
printf("line = %d\n",__LINE__);    int a = 10;
    //H1//
printf("line = %d\n",__LINE__);    int testAra[100];
printf("line = %d\n",__LINE__);    int temp = 0 ;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<5;j++)
        {
printf("line = %d\n",__LINE__);            temp += checkOddEven(j);
printf("line = %d\n",__LINE__);            testAra[i] = temp ;
        }
    }
    //H2//
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
printf("line = %d\n",__LINE__);                printf("%d %d %d\n",i,j,k);
            }
        }
    }
    //H4//
    if(a == 10)
    {
printf("line = %d\n",__LINE__);        int b = 10;
printf("line = %d\n",__LINE__);        int c = b + 1;
printf("line = %d\n",__LINE__);        int s = b + c;
    }
    else
    {
printf("line = %d\n",__LINE__);        int b = 15;
printf("line = %d\n",__LINE__);        int c = b++;
printf("line = %d\n",__LINE__);        int s = c++;
printf("line = %d\n",__LINE__);        int t = 100;
    }
printf("line = %d\n",__LINE__);    return 0;
}
