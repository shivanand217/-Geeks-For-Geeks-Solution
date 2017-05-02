// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

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

unsigned long int nth_catalan_number(unsigned long int n)
{
    if(n <= 1)
        return 1;

    unsigned long int res=0;

    for(int i=0; i<n; i++)
    {
     res += nth_catalan_number(i)*nth_catalan_number(n-i-1);
    }
    return res;
}

unsigned long int catalan_dp(unsigned long int n)
{
    unsigned long int c[n+1];
    c[0] = c[1] = 1;

    for(int i=2; i<=n; i++)
    {
        c[i] = 0;

        for(int j=0; j<i; j++)
        {
            c[i] +=  c[j]*c[i-j-1];
        }
    }

    return c[n];
}

int main()
{
    for(int i=1; i<=10; i++)
    {
        cout<<nth_catalan_number(i)<<" ";
    }
    return 0;
}
