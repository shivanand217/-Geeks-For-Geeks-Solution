// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/** their is a formula for this
    D(n) = 4* D(floor(n/5)) * D(unit digit of n) if the tens digit of n is odd
    or
    D(n) = 6* D(floor(n/5)) * D(unit digit of n) if the tens digit of n is even

    formula work as if we have to find 10! = 10*9*8*7*6*5*4*3*2*1
    we remove all the factors of 5 and equal factors of two (5*2 = 10)
    now multiply all the last digit of the remained number that is our answer
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

int d;

// we have to precompute d values of the numbers less than 10
int d_value[] = {1,1,2,6,4,2,2,4,2,8};

int last_non_zero_digit_in_factorial(int n)
{
    if(n<10)
    {
        return d_value[n];
    }

    int f = n;int p = f%10;
    f/=10;

    f = f%10;

    if(f%2)// f is odd
    {
        d = 4* last_non_zero_digit_in_factorial(floor(n/5))* last_non_zero_digit_in_factorial(p);
    }
    else // f is even
    {
        d = 6 * last_non_zero_digit_in_factorial(floor(n/5)) * last_non_zero_digit_in_factorial(p);
    }

    return d;
}

int main()
{
int n;
cin>>n;

int ans = last_non_zero_digit_in_factorial(n);
cout<<ans<<endl;

int k = ans%10;

cout<<k<<endl;

return 0;
}
