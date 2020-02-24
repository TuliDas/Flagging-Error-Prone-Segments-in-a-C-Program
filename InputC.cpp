static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include <chrono>
long long getTicks(){return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int fun2(int d,int e,int f)
{printf("function_start_id %d line = %d\n", ++global_function_id, __LINE__);
printf("line = %d\n",__LINE__);    int a = d + e + f ;
printf("line = %d\n",__LINE__);printf("function_end_id %d line = %d\n", global_function_id--, __LINE__);    return a ;
printf("function_end_id %d line = %d\n", global_function_id--, __LINE__);}
int fun(int x,int y,int z)
{printf("function_start_id %d line = %d\n", ++global_function_id, __LINE__);
printf("line = %d\n",__LINE__);    int a;
printf("line = %d\n",__LINE__);    int b;
printf("line = %d\n",__LINE__);    int c;
printf("line = %d\n",__LINE__);    int ans = fun2(x,y,z);
printf("line = %d\n",__LINE__);printf("function_end_id %d line = %d\n", global_function_id--, __LINE__);    return ans;
printf("function_end_id %d line = %d\n", global_function_id--, __LINE__);}
void fun3()
{printf("function_start_id %d line = %d\n", ++global_function_id, __LINE__);
printf("line = %d\n",__LINE__);    int a;
printf("line = %d\n",__LINE__);    int b;
printf("line = %d\n",__LINE__);    int c;
printf("function_end_id %d line = %d\n", global_function_id--, __LINE__);}
int main()
{ freopen("Output.txt", "w+", stdout);
printf("line = %d\n",__LINE__);    int n = 10;
printf("loop_start_id %d line = %d\n", ++global_loop_id, __LINE__);    for(int i=1;i<=5;i++)
    {
printf("line = %d\n",__LINE__);        int z = fun(i,i,i);
    }printf("loop_end_id %d line = %d\n", global_loop_id--, __LINE__);
printf("line = %d\n",__LINE__);    fun3();
printf("line = %d\n",__LINE__);    fun3();
printf("line = %d\n",__LINE__);    return 0;
}
