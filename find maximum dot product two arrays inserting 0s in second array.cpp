#include<bits/stdc++.h>
using namespace std;

long long int a[1002], b[1002];

long long int solve(int m, int n)
{
    long long int dp[n+1][m+1];
    memset(dp, 0LL, sizeof(dp));

    for (int i=1; i<=n; i++)
        for (int j=i; j<=m; j++)
            dp[i][j] = max((dp[i-1][j-1] + (a[j-1]*b[i-1])) ,dp[i][j-1]);

    return dp[n][m] ;
}

int main()
{
	int t;
	cin>>t;

	int m,n;
    while(t--)
	{
		cin>>m>>n;

		for(int i=0; i<m; i++)
		{
			cin>>a[i];
		}
		for(int j=0; j<n; j++)
		{
			cin>>b[j];
		}

        long long int ans = solve(m, n);
        cout<<ans<<endl;
	}

    return 0;
}
