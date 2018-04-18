// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

/** double factorial of a number is defined as
    if number is even then fact(fact(n)) = product of numbers by same parity means
    product of n(n-2)(n-4)(n-6).....4,2
    if number is odd
    product of n(n-2)(n-4).....3.1

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

int double_factorial(int n)
{
    int ans = 1;
    for(int i=n; i>=0; i-=2)
    {
        if(i == 0 || i==1)
        {
            return ans;
        }
        else
        {
            ans*= i;
        }
    }
}

int main()
{
    int n;
    read(n)
    int ans = double_factorial(n);
    cout<<ans<<endl;
    return 0;
}
