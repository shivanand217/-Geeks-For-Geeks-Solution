// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n*n*n)
// SPACE COMPLEXITY : O(n*n*n)

/**

Given a 3-D array arr[l][m][n],
the task is to find the minimum path sum from the first cell of array
to the last cell of array. We can only traverse to adjacent element,
i.e., from a given cell (i, j, k), cells (i+1, j, k), (i, j+1, k) and (i, j, k+1) can be traversed, diagonal traversing is not allowed,
We may assume that all costs are positive integers

**/

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

const int maxn = 50;

int ar[maxn][maxn][maxn];


int dp_solve(int n)
{
    int dp[n][n][n];
    dp[0][0][0] = ar[0][0][0];

    // initialising first row
    for(int i=1; i<n; i++)
    {
        dp[i][0][0] = dp[i-1][0][0] + ar[i][0][0];
    }

    // initialising first column
    for(int j=1; j<n; j++)
    {
        dp[0][j][0] = dp[0][j-1][0] + ar[0][j][0];
    }

    // initialising first width
    for(int k=1; k<n; k++)
    {
        dp[0][0][k] = dp[0][0][k-1] + ar[0][0][k];
    }

    //initialising first row column
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {
            dp[i][j][0] = ar[i][j][0] + min(dp[i-1][j][0], dp[i][j-1][0]);
        }
    }

    for(int k=1; k<n; k++)
    {
        for(int j=1; j<n; j++)
        {
            dp[0][j][k] = ar[0][j][k] + min(dp[0][j][k-1], dp[0][j-1][k]);
        }
    }

    for(int i=1; i<n; i++)
    {
        for(int k=1; k<n; k++)
        {
            dp[i][0][k] = ar[i][0][k] + min(dp[i-1][0][k], dp[i][0][k-1]);
        }
    }

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {
            for(int k=1; k<n; k++)
            {
                dp[i][j][k] = ar[i][j][k] + min(dp[i][j][k-1], min(dp[i][j-1][k],dp[i-1][j][k]));
            }
        }
    }

    // finally return the final value
    return dp[n-1][n-1][n-1];
}

int main()
{
    int n=2;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=n; k++)
            {
                si(ar[i][j][k]);
            }
        }
    }

    int ans = dp_solve(n);

cout<<ans<<endl;
    return 0;
}
