// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n*log(log(n)))

/** Given a number n, the task is to calculate its primorial.
    Primorial of a number is similar to factorial of a number.
    In primorial, not all the natural numbers get multiplied only prime numbers are multiplied to calculate the primorial of a number.
    It is denoted with P#.**/

/** Input: n = 5
Output: 30
Priomorial = 2 * 3 * 5 = 30
As a side note, factorial is 2 * 3 * 4 * 5
**/

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

void seive(int n)
{
    memset(prime, 1, sizeof(prime));

    prime[0] = prime[1] = 0;

    for(int i=0; i*i <= n; i++)
    {
        if(prime[i])
        {
            for(int j=2*i; j<=n; j+=i)
            {
                prime[j] = 0;
            }
        }
    }
}

int primorial_of_number(int n)
{
    int ans= 1;

    for(int i=2; i<=n; i++)
    {
        if(prime[i])
        {
            ans*= prime[i];
        }
    }

    return ans;
}

int main()
{
    int n;
    read(n)
    seive(n);
    int k = primorial_of_number(n);

    cout<<k<<endl;
    return 0;
}
