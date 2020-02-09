#include<bits/stdc++.h>
using namespace std;


int checkEvenOrOdd(int num)
{
    if(num%2==0)
    {
        goto EVEN;
    }
    else
    {
        goto ODD;

    }

    ODD:
        printf("%d is an odd number\n",num);
        return 1;

    EVEN:
        printf("%d is an even number\n",num);
        return 1;
}

void helloPrint()
{
    printf("Hello World\n");
}


int main()
{
    int a = 5 ;
    int b = 10 ;

    int ret = checkEvenOrOdd(a);
    helloPrint();


    int sum=0;
    for(int i=1;i<=a;i++)
    {
        sum+= i ;
        for(int j=1;j<=b;j++)
        {
            sum+=j;
        }
    }
    printf("Sum = %d\n",sum);

    return 0;
}
