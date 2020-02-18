static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;
#include<bits/stdc++.h>
using namespace std;
#define M 105
int phi[105];
vector <int> prime;
bool mark[M];
void sieve()
{
printf("line = %d\n",__LINE__);    memset(mark,true,sizeof(mark));
printf("line = %d\n",__LINE__);    prime.push_back(2);
    for(int i=3; i*i<=M; i+=2)
    {
        if(mark[i])
        {
            for(int j=i*i; j<=M; j+=2*i)
            {
printf("line = %d\n",__LINE__);                mark[j]=false;
            }
        }
    }
    for(int i=3; i<=M; i+=2)
    {
        if(mark[i])
        {
printf("line = %d\n",__LINE__);            prime.push_back(i);
        }
    }
}
void phi_fun(int n)
{
    for(int i=1; i<=n; i++)
    {
printf("line = %d\n",__LINE__);        phi[i]=i;
    }
    for(int i=0; prime[i]<=n; i++)
    {
printf("line = %d\n",__LINE__);        int p=prime[i];
        if(phi[p]==p)
        {
            for(int k=p; k<=n; k+=p)
            {
printf("line = %d\n",__LINE__);                phi[k]-=phi[k]/p;
            }
        }
    }
}
int main()
{ freopen("Output.txt", "w+", stdout);
    sieve();
    int n;
    cin>>n;
    phi_fun(n);
    for(int i=1; i<=n; i++)
    {
printf("line = %d\n",__LINE__);        cout<<"Phi["<<i<<"] = "<<phi[i]<<endl;
    }
}
