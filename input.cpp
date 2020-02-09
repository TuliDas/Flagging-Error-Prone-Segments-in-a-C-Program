#include<bits/stdc++.h>
using namespace std;

void checkEvenOrOdd(int num)
{
    
    if(num%2==0)
    {
        printf("line = %d\n",__LINE__); goto EVEN;   
    }
    else
    {
        
        printf("line = %d\n",__LINE__);goto ODD;
        
        printf("line = %d\n",__LINE__);ODD:
        
        printf("line = %d\n",__LINE__); printf("This is an odd number\n");
    }

    EVEN:
        printf("line = %d\n",__LINE__); printf("This is an even number\n");

    return ;
}


int main()
{
    printf("line = %d\n",__LINE__); freopen("out.txt", "w+", stdout);

    printf("line = %d\n",__LINE__); int a = 10 ;

    printf("line = %d\n",__LINE__); checkEvenOrOdd(a);


    printf("line = %d\n",__LINE__); int p=0;
    for(int i=1;i<=a;i++)
    {
        printf("line = %d\n",__LINE__); p+= i ;
    }
    printf("line = %d\n",__LINE__); printf("P = %d\n",p);

    return 0;
}
