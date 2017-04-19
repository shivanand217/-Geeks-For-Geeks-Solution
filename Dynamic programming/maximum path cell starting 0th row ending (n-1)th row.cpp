// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n*n)
// SPACE COMPLEXITY : O(n*n)

/**Given a N X N matrix Mat[N][N] of positive integers. There are only three possible moves from a cell (i, j)
(i+1, j)
(i+1, j-1)
(i+1, j+1)

Input : mat[4][4] = { {4, 2, 3, 4},
                      {2, 9, 1, 10},
                      {15, 1, 3, 0},
                      {16, 92, 41, 44} };
Output :120
path : 4 + 9 + 15 + 92 = 120

**/

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

const int maxn = 1e2+2;
int mat[maxn][maxn];

int dp_maximum_path(int n)
{

    int dp[n][n];

    memset(dp, 0, sizeof(dp));

    int ans=-1;

    for(int i=0; i<n; i++)
    {
        dp[0][i] = mat[0][i];

        ans = max(ans, dp[0][i]);
    }



    for(int i=1; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i-1][j+1])) + mat[i][j];

            ans = max(ans, dp[i][j]);
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
        for(int j=0; j<n; j++)
        {
            si(mat[i][j]);
        }
    }
    int ans = dp_maximum_path(n);
    cout<<ans<<endl;

    return 0;
}

