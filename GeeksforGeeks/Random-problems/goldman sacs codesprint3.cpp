#include<bits/stdc++.h>
using namespace std;

int a[55];

int solve(int n, int k)
{
    int dp[k+1][n+1];

    for(int i=0; i<=k; i++)
		dp[i][0] = 0;

	for(int j=0; j<=n; j++)
		dp[0][j] = 0;

    for(int i=1; i<=k; i++)
	{
		for(int j=1; j<n; j++)
		{
			int max_so = INT_MIN;

			for(int m=0; m<j; m++)
			{
				max_so = max(max_so, a[j] - a[m] + dp[i-1][m]);
			}

			dp[i][j] = max(dp[i][j-1], max_so);
		}
	}

	return dp[k][n-1];
}

int main()
{
    int q, k, n;
    cin>>q;

    while(q--)
	{
        cin>>k;
        cin>>n;

        for(int i=0; i<n; i++)
		{
            cin>>a[i];
		}

        int ans = solve(n, k);

        cout<<ans<<endl;
	}
	return 0;
}

