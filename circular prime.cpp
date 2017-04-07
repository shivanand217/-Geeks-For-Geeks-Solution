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
#define re return 0;
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

void seive(int n)
{
    memset(prime, 1, sizeof(prime) );
    prime[0] = prime[1] = 0;

    for(int i=2; i*i<= n; i++)
    {
        if(prime[i])
        {
            for(int j=2*i; j<=n ; j+=i)
            {
                prime[j] = 0;
            }
        }
    }
}

int count_of_digits(int n)
{
    int cnt=0;
    while(n > 0)
    {
        cnt++;
        n/=10;
    }
    return cnt;
}

bool circular_prime(int n)
{

// every time rotate the digits check for prime
// we do rotation for count of digits -1 times
int cnt = count_of_digits(n);
int tot = fast_pow(10,cnt);
// we rotate upto cnt-1 times

int tmp;
for(int i=0; i<cnt; i++)
{
    int k = n % 10;
    tmp = k * tot;

    n = n/10;
    n+=tmp;

    if(prime[n])
    {
        return false;
    }
}

return true;
}

int main()
{
 //   memset
    int n;
    read(n)

    seive(n);

    for(int i=11; i<n; i++)
    {
        if(circular_prime(i))
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;

return 0;
}
