#include<bits/stdc++.h>
using namespace std;

int a[102][102];
int dp[102][102];

// just reducing the overlapping subproblems occurs in the recursion computation
int solve_dp(int i, int j, int n)
{
    if(dp[i][j] != -1)
		return dp[i][j];

    if(i == n-1)
		return (dp[i][j] = a[i][j]);

    int res=0;
    for(int k=0; k<n; k++)
	{
		if(k != j)
			res = max(res , solve_dp(i+1, k, n));
	}

	return (dp[i][j] = res + a[i][j]);
}

int solve(int n)
{
    memset(dp, -1, sizeof(dp));

    int res = 0;
    for(int i=0; i<n; i++)
	{
        res = max(res, solve_dp(0, i, n));
	}

	return res;
}

int main()
{
    int t, n;
    cin>>t;
    while(t--)
	{
        cin>>n;
        for(int i=0; i<n; i++)
		{
            for(int j=0; j<n; j++)
			{
				cin>>a[i][j];
			}
		}
        int ans = solve(n);
        cout<<ans<<endl;

	}
	return 0;
}
