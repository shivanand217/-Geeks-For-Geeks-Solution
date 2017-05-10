// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(log(n))
// SPACE COMPLEXITY : O(1)

/** algorithmic paradigm: divide and conquer **/

#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define sli(x) scanf("%ld",&x)
#define ll long long
#define mod 1000000007
#define pfi(x) printf("%d\n",x)
#define pfli(x) printf("%ld\n",x)
#define pflli(x) printf("%lld\n",x)
#define lli long long int
#define ull unsigned long long int
#define fo_r(i,n) for(int i=0; i<n; i++)
using namespace std;

const int maxn = 103;
int ar[maxn];
int n;

int solve(int lo, int hi)
{
    int mid = lo + (hi - lo)/2;

    if(mid == 0 || ar[mid-1] > )
}

int main()
{
    si(n);
    for(int i=0; i<n; i++)
    {
        si(ar[i]);
    }

    int ans = solve(0, n-1);

    cout<<ans<<endl;

    return 0;
}

