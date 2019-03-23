// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// time: O(n*log(log(n)))


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

const int maxn =1e5+2;
bool prime[maxn];

bool prime_check(int n)
{
    prime[0]=prime[1] =false;

    for(int i=2; i*i <=n; i++)
    {
        if(prime[i])
        {
            for(int j=i*2; j <= n; j+=i)
            {
                prime[j] = false;
            }
        }
    }
}

bool check_for_right_truncatable(int n)
{
    while(n > 0)
    {
        if(!prime[n])
        {
            return false;
        }
        n/=10;
    }
    return true;
}

int main()
{
    int n;
    read(n)

    memset(prime, true, sizeof(prime));
    prime_check(n);

    if(check_for_right_truncatable(n))
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
}

