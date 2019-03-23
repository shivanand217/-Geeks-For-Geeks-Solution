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
#define ret return 0;
#define
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

const int maxn = 1e5+2;
int prime[maxn];

int seive(int l, int r)
{
    int freq[10] = {0};

    prime[0] = prime[1] = false;

    for(int i= 2; i*i<=r; i++)
    {
        if(prime[i])
        {
            for(int j=i*2; j<=r; j+=i)
            {
                prime[j] = 0;
            }
        }
    }
    int tmp,k;

    for(int i=l; i<=r; i++)
    {
        if(prime[i])
        {
            tmp = i;

            while(tmp > 0)
            {
                k = tmp % 10;
                freq[k]++;
                tmp/=10;
            }
        }
    }

    int max_freq,max_=INT_MIN;

    for(int i=0; i<=9; i++)
    {
        if(freq[i] > max_ )
        {
            max_= freq[i];
            max_freq = i;
        }
    }

    return max_freq;
}

int main()
{
int l,r;
read(l)
read(r)

memset(prime, 1, sizeof(prime));
int ans =  seive(l,r);

cout<<ans<<endl;

return 0;
}
