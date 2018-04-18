// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

#include<bits/stdc++.h>
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

int pos[maxn];
int revenue[maxn];

int dp_maximum_revenue(int n, int restriction)
{
    int maximum_revenue[n];

    maximum_revenue[0] = revenue[0];

    for(int i=1; i<n; i++)
    {
        maximum_revenue[i] = max(maximum_revenue[i-restriction-1]+ revenue[i], maximum_revenue[i-1]);
    }

    return maximum_revenue[n-1];
}

int main()
{
    int n;
    si(n);

    for(int i=0; i<n; i++)
    {
        si(pos[i]);
    }

    for(int i=0; i<n; i++)
    {
        si(revenue[i]);
    }

    int restriction;
    si(restriction);

    int ans = dp_maximum_revenue(n, restriction);

    cout<<ans<<endl;
    return 0;
}

