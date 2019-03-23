// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define read(val) scanf("%d",&val);
#define print(val) printf("%d ",val);
#define scan(val) scanf("%lld",&val);
#define show(val) printf("%lld ",val);
#define rr(val) for(int i=0; i<val; i++)
#define LL long long
#define mod 1000000007
using namespace std;

const int maxn = 105;
int arr[maxn];
vector<int> prime;

int n,m;

int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a, a);
}

int lcm(int a,int b)
{
    int ans;
    ans = (a*b)/gcd(a,b);
    return ans;
}

bool solve()
{
    // calculate the lcm of the array
    int lcm_ = arr[0];

    for(int i=1; i<n; i++)
    {
        lcm_ = lcm(lcm_,arr[i]);
    }
    int val;

    for(int i=0; i<n; i++)
    {
        val = lcm_/arr[i];

        for(int j=0; j<prime.size(); i++)
        {
            if(val % prime[i] == 0)
            {
                while(val % prime[i] == 0)
                {
                    val = val/prime[i];
                }
            }
        }
        if(val!=1)
            return false;
    }
    return true;
}


int main()
{
    read(n)
    read(m)

    for(int i=0;i<n; i++)
    {
        read(arr[i])
    }
    int tmp;

    for(int i=0; i<m; i++)
    {
        read(tmp)
        prime.push_back(tmp);
    }

    if(solve())
    {
        cout<<"possible"<<endl;
    }
    else
    {
        cout<<"not possible"<<endl;
    }
    return 0;
}
