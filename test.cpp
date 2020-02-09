#include<bits/stdc++.h>
using namespace std;
int checkEvenOrOdd(int num)
{
    if(num%2==0)
    {
printf("line = %d\n",__LINE__);        goto EVEN;
    }
    else
    {
printf("line = %d\n",__LINE__);        goto ODD;
    }
    ODD:
printf("line = %d\n",__LINE__);        printf("%d is an odd number\n",num);
printf("line = %d\n",__LINE__);        return 1;
    EVEN:
printf("line = %d\n",__LINE__);        printf("%d is an even number\n",num);
printf("line = %d\n",__LINE__);        return 1;
}
void helloPrint()
{
printf("line = %d\n",__LINE__);    printf("Hello World\n");
}
int main()
{
printf("line = %d\n",__LINE__);freopen("outputC.txt", "w+", stdout);
printf("line = %d\n",__LINE__);    int a = 5 ;
printf("line = %d\n",__LINE__); int b = 10 ;
    int ret = checkEvenOrOdd(a);
printf("line = %d\n",__LINE__);    helloPrint();
printf("line = %d\n",__LINE__);    int sum=0;
    for(int i=1;i<=a;i++){
printf("line = %d\n",__LINE__);        sum+= i ;
        for(int j=1;j<=b;j++)
        {
printf("line = %d\n",__LINE__);            sum+=j;
        }
    }
printf("line = %d\n",__LINE__);    printf("Sum = %d\n",sum);
printf("line = %d\n",__LINE__);    return 0;
}
