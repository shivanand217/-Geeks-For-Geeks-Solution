// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(logn)

#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define sli(x) scanf("%ld",&x)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define LL long long
#define mod 1000000007
#define pfi(x) printf("%d\n",x)
#define pfli(x) printf("%ld\n",x)
#define pflli(x) printf("%lld\n",x)
#define lli long long int
#define ull unsigned long long int
using namespace std;

const int maxn = 1e3+2;
int f[maxn] = {0};

int fib(int n)
{

// base case
if(n == 0)
    return 0;
if(n==1 || n==2)
    return (f[n]=1);

// if f(n)is computed
if(f[n])
{
    return f[n];
}

int k = (n&1)  ? ((n+1)/2) : (n/2);
f[n] = (n&1) ? (fib(k)*fib(k) + fib(k-1)*fib(k-1)) : (2*fib(k-1) + fib(k))*fib(k);

return f[n];
}

int solve(int n)
{
    return fib(n+1);
}

int main()
{
    int n;
    si(n);
    cout<<solve(n)<<endl;

    return 0;
}
