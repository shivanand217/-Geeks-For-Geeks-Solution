// AUTHOR: SHIV ANAND
// LANGUAGE: CPP
// TIME COMPLEXITY : O(n*m)
// SPACE COMPLEXITY : O(n*m)

/** naive approach takes O(n*n*n) I am using dyanamic programming approach **/

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

const int maxn = 100;
int matrix[maxn][maxn];

int dp_maximum_square_submatrix(int n,int m)
{
    int dp[n][m];
    memset(dp, 0, sizeof(dp) );

    int ans = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            // if first row or column then square size dont exist
            if(i == 0 || j==0)
            {
                dp[i][j] = 1;
            }
            else
            {
                // depends on dp[i-1][j], dp[i-1][j-1], dp[i][j-1]
                if(matrix[i][j] == matrix[i-1][j-1] && matrix[i][j] == matrix[i-1][j] && matrix[i][j] == matrix[i][j-1])
                {
                    dp[i][j] = min(dp[i][j-1], min(dp[i-1][j],dp[i-1][j-1]))+1;
                }
                else
                {
                    dp[i][j] = 1;
                }
            }

            // each time update the result
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

int main()
{
    int n,m;

    si(n);
    si(m);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            si(matrix[i][j]);
        }
    }
    int ans  = dp_maximum_square_submatrix(n,m);
    cout<<ans<<endl;

    return 0;
}

