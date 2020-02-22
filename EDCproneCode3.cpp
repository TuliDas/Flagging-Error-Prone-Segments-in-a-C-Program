#include<bits/stdc++.h>
using namespace std;

#define M 105
int phi[105];
vector <int> prime;
bool mark[M];

void sieve()
{
    memset(mark,true,sizeof(mark));

    prime.push_back(2);

    for(int i=3; i*i<=M; i+=2)
    {
        if(mark[i])
        {
            for(int j=i*i; j<=M; j+=2*i)
            {
                mark[j]=false;
            }
        }
    }


    for(int i=3; i<=M; i+=2)
    {
        if(mark[i])
        {
            prime.push_back(i);
        }
    }
}


void phi_fun(int n)
{

    for(int i=1; i<=n; i++)
    {
        phi[i]=i;
    }

    for(int i=0; prime[i]<=n; i++)
    {
        int p=prime[i];

        if(phi[p]==p)
        {
            for(int k=p; k<=n; k+=p)
            {
                phi[k]-=phi[k]/p;
            }
        }
    }

}

int main()
{
    sieve();
    int n;
    cin>>n;
    phi_fun(n);
    for(int i=1; i<=n; i++)
    {
        cout<<"Phi["<<i<<"] = "<<phi[i]<<endl;
    }

}
