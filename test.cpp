static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include<iostream>
using namespace std;
//H3//
void FuctionTerminatingBranch(int s,int e)
{printf("function_start_id %d\n", ++global_function_id);
    if(s<0 || e>=100)
    {printf("ifelse_start_id %d\n", ++global_ifelse_id);
printf("ifelse_end_id %d\n", global_ifelse_id--);printf("function_end_id %d\n", global_function_id--);        return;
printf("ifelse_end_id %d\n", global_ifelse_id--);    }
printf("line = %d\n",__LINE__);    int sum = 0 ;
printf("line = %d\n",__LINE__);    int ara[100];
printf("loop_start_id %d line = %d\n", ++global_loop_id, __LINE__);    for(int i=s;i<=e;i++)
    {
printf("line = %d\n",__LINE__);        ara[i] = s ;
    }printf("loop_end_id %d line = %d\n", global_loop_id--, __LINE__);
printf("loop_start_id %d line = %d\n", ++global_loop_id, __LINE__);    for(int i=s;i<=e;i++)
    {
printf("line = %d\n",__LINE__);        printf("%d\n",ara[i]);
    }printf("loop_end_id %d line = %d\n", global_loop_id--, __LINE__);
printf("function_end_id %d\n", global_function_id--);}
bool checkOddEven(int num)
{printf("function_start_id %d\n", ++global_function_id);
    if(num%2==0)
    {printf("ifelse_start_id %d\n", ++global_ifelse_id);
printf("ifelse_end_id %d\n", global_ifelse_id--);printf("function_end_id %d\n", global_function_id--);        return 0;
printf("ifelse_end_id %d\n", global_ifelse_id--);    }
printf("function_end_id %d\n", global_function_id--);    return 1;
printf("function_end_id %d\n", global_function_id--);}
int main()
{printf("function_start_id %d\n", ++global_function_id);
printf("line = %d\n",__LINE__);freopen("outputC.txt", "w+", stdout);
printf("line = %d\n",__LINE__);//freopen("outputC.txt", "w+", stdout);
printf("line = %d\n",__LINE__);    int a = 10;
    //H1//
printf("line = %d\n",__LINE__);    int testAra[100];
printf("line = %d\n",__LINE__);    int temp = 0 ;
printf("loop_start_id %d line = %d\n", ++global_loop_id, __LINE__);    for(int i=0;i<5;i++)
    {
printf("loop_start_id %d line = %d\n", ++global_loop_id, __LINE__);        for(int j=0;j<5;j++)
        {
printf("line = %d\n",__LINE__);            temp += checkOddEven(j);
printf("line = %d\n",__LINE__);            testAra[i] = temp ;
        }printf("loop_end_id %d line = %d\n", global_loop_id--, __LINE__);
    }printf("loop_end_id %d line = %d\n", global_loop_id--, __LINE__);
    //H2//
printf("loop_start_id %d line = %d\n", ++global_loop_id, __LINE__);    for(int i=0;i<3;i++)
    {
printf("loop_start_id %d line = %d\n", ++global_loop_id, __LINE__);        for(int j=0;j<3;j++)
        {
printf("loop_start_id %d line = %d\n", ++global_loop_id, __LINE__);            for(int k=0;k<3;k++)
            {
printf("line = %d\n",__LINE__);                printf("%d %d %d\n",i,j,k);
            }printf("loop_end_id %d line = %d\n", global_loop_id--, __LINE__);
        }printf("loop_end_id %d line = %d\n", global_loop_id--, __LINE__);
    }printf("loop_end_id %d line = %d\n", global_loop_id--, __LINE__);
    //H4//
    if(a == 10)
    {printf("ifelse_start_id %d\n", ++global_ifelse_id);
printf("line = %d\n",__LINE__);        int b = 10;
printf("line = %d\n",__LINE__);        int c = b + 1;
printf("line = %d\n",__LINE__);        int s = b + c;
printf("ifelse_end_id %d\n", global_ifelse_id--);    }
    else
    {printf("ifelse_start_id %d\n", ++global_ifelse_id);
printf("line = %d\n",__LINE__);        int b = 15;
printf("line = %d\n",__LINE__);        int c = b++;
printf("line = %d\n",__LINE__);        int s = c++;
printf("line = %d\n",__LINE__);        int t = 100;
printf("ifelse_end_id %d\n", global_ifelse_id--);    }
    //H4//
    if(a == 10)
    {printf("ifelse_start_id %d\n", ++global_ifelse_id);
printf("line = %d\n",__LINE__);        int b = 10;
printf("line = %d\n",__LINE__);        int c = b + 1;
printf("line = %d\n",__LINE__);        int s = b + c;
printf("ifelse_end_id %d\n", global_ifelse_id--);    }
    else if (a == 20)
    {printf("ifelse_start_id %d\n", ++global_ifelse_id);
printf("line = %d\n",__LINE__);        int b = 15;
printf("line = %d\n",__LINE__);        int c = b++;
printf("line = %d\n",__LINE__);        int s = c++;
printf("line = %d\n",__LINE__);        int t = 100;
printf("ifelse_end_id %d\n", global_ifelse_id--);    }
    else
    {printf("ifelse_start_id %d\n", ++global_ifelse_id);
printf("line = %d\n",__LINE__);        int b = 15;
printf("line = %d\n",__LINE__);        int c = b+10;
printf("line = %d\n",__LINE__);        int s = c+15;
printf("line = %d\n",__LINE__);        int t = 100;
printf("ifelse_end_id %d\n", global_ifelse_id--);    }
    
printf("function_end_id %d\n", global_function_id--);    return 0;
printf("function_end_id %d\n", global_function_id--);}
