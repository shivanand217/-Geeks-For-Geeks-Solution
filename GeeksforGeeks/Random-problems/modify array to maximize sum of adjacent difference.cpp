// AUTHOR: SHIV ANAND
// LANGUAGE: CPP

/**
    Given an array, we need to modify values of this array in such a way that sum of absolute differences between two consecutive elements is maximized.
    If the value of an array element is X,
    then we can change it to either 1 or X.
**/

/** we maintain a dp state of two columns **/

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

const int maxn = 1e4+2;
int ar[maxn];

int dp_state(int n)
{
    int dp[n][2];

    for(int i=0; i<n; i++)
    {
        dp[i][0] = dp[1][i] = 0;
    }

    for(int i=0; i<n-1; i++)
    {
        dp[i+1][0] = max(dp[i][0]+abs(1-1) , dp[i][1] + abs(1-arr[i]));

        dp[i+1][1] = max(dp[i][0] + abs(arr[i+1]-1), dp[i][1] + abs(arr[i+1]-arr[i]));
    }

    return max(dp[n-1][0], dp[n-1][1]);
}

int main()
{
    int n;
    si(n);

    for(int i=0; i<n; i++)
    {
        si(arr[i]);
    }

    int ans = dp_state(n);
    cout<<ans<<endl;
    return 0;

}
