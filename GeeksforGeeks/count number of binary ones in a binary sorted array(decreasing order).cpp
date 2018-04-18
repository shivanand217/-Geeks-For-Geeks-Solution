// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(logn)
// SPACE COMPLEXITY : O(1)

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

const int maxn = 102;
int a[maxn];

/** simple binary search **/

int solve(int n)
{
    int lo = 0;
    int hi= n-1,mid;
    int ans;

    while(lo <= hi)
    {
        mid = (hi-lo)/2 + lo;

        if(a[mid] == 0)
        {
            if(mid-1 < 0)
            {
                ans = 0;break;
            }
            else if(a[mid-1] == 1)
            {
                ans = mid;break;
            }
            else
            {
                hi = mid-1;
            }
        }
        else
        {
            if(mid+1 == n)
            {
                ans = mid+1;break;
            }
            else if(a[mid+1] == 0)
            {
                ans = mid+1;break;
            }
            else
            {
                lo = mid+1;
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    si(n);

    for(int i=0; i<n; i++)
    {
        si(a[i]);
    }

    int ans = solve(n);
    cout<<ans<<endl;
    return 0;
}
