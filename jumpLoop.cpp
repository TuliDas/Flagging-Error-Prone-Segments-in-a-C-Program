#include<stdio.h>
#include<iostream>
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

int addition(int x,int y)
{
    int res ;
    res = x + y ;
    return res;
}


int main()
{
    int a = 5 ; int b = 10 ; int ret = checkEvenOrOdd(a);  goto exit_helloPrint;

    helloPrint();
    printf("I will not be executed");

    exit_helloPrint:
    int sum=0;
    sum = addition(a,b);

    for(int i=1;i<=a;i++){
        sum+= i ;
        for(int j=1;j<=b;j++)
        {
            sum+=j;
        }
    }
    
        for(int i=1;i<=100;i++){
        sum+= i ;
        for(int j=1;j<=20;j++)
        {
            sum+=j;
            printf("This is larger loop\n");
        }
    }

    printf("Sum = %d\n",sum);
    return 0;
}
