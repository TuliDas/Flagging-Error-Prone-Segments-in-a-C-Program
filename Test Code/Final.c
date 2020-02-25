#include<stdio.h>

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
    int i;
    for(i=s;i<=e;i++)
    {
        ara[i] = s ;
    }
    for(i=s;i<=e;i++)
    {
        printf("%d\n",ara[i]);
    }
}

int checkOddEven(int num)
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
    int testAra[1000];

    int temp = 0 ;
    int i,j,k;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            temp += checkOddEven(j);
            testAra[i] = temp ;
        }
    }
    FuctionTerminatingBranch(2,20);

    int z = 13;
    while(z--)
    {
        int t = 10;
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
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

    else
    {
            for(int i=0;i<=1000;i++)
            {
                int xx = i;
            }
    }
    return 0;
}
