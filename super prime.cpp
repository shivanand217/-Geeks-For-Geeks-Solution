// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n*log(log(n)))

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
#define io_file freopen("D:/Coding Problems/Contest/input_file.in", "r", stdin);freopen("D:/Coding Problems/Contest/output_file.out", "w", stdout)

int fast_pow(int x,int n)
{
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%mod;
        x=(x*x)%mod;
        n=n/2;
    }
    return result;
}

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

const int maxn = 1e5+2;
int prime[maxn];

vector<int> super_Prime;

void super_prime(int n)
{
    int m=1;
    for(int i=2; i<=n; i++)
    {
        if(prime[i])
        {
            if(prime[m])
            {
                super_Prime.push_back(i);
            }
            m++;
        }
    }
}

void seive(int n)
{
    memset(prime, 1, sizeof(prime));

    prime[0] = prime[1] = 0;

    for(int i=2; i*i<=n; i++)
    {
        if(prime[i])
        {
            for(int j = 2*i; j<=n; j+=i)
            {
                prime[j] = 0;
            }
        }
    }
}

int main()
{
    int n;
    read(n)
    seive(n);

    super_prime(n);

    for(int i=0; i<super_Prime.size(); i++)
    {
        cout<<super_Prime[i]<<" ";
    }
    return 0;
}
