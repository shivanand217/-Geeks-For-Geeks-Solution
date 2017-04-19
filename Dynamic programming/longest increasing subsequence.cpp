// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n*n)
// SPACE COMPLEXITY : O(n)

/** this is simple O(n^2) dyanamic programming based approach **/

#include<bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define sli(x) scanf("%ld",&x)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define mod 1000000007
#define pfi(x) printf("%d\n",x)
#define pfli(x) printf("%ld\n",x)
#define pflli(x) printf("%lld\n",x)
#define lli long long int
#define ull unsigned long long int
using namespace std;

const int maxn = 1e3+2;
int ar[maxn];

int dp_lis_solve(int n)
{
    int *dp_lis = new int[n];

    for(int i=0; i<n; i++)
    {
        dp_lis[i] = 1;
    }

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(ar[i] > ar[j] && dp_lis[i] < dp_lis[j]+1)
            {
                dp_lis[i] = dp_lis[j] + 1;
            }
        }
    }

    int max_value = INT_MIN;
    for(int i=0; i<n; i++)
    {
        max_value = max(dp_lis[i], max_value);
    }

    return max_value;
}

int main()
{
    int n;
    si(n);

    for(int i=0; i<n; i++)
    {
        si(ar[i]);
    }

    int ans = dp_lis_solve(n);
    cout<<ans<<endl;
    return 0;
}
