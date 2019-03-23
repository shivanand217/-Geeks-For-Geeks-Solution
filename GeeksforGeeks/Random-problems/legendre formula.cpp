// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(logp(n))

/**Legendre’s formula (Given p and n, find the largest x such that p^x divides n!)
**/

/**  largest possible power is n/p + n/(p^2) + n/(p^3) + … **/


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
using namespace std;

int largest_power(int n, int p)
{
    int x=0;

    while(n)
    {
        n/=p;
        x+=n;
    }

return x;
}

int n,p;

int main()
{
    si(n);
    si(p);

    int ans = largest_power(n, p);

    cout<<"largest power of "<<p<<" that divides n! is: ";
    cout<<ans<<endl;
    return 0;
}
