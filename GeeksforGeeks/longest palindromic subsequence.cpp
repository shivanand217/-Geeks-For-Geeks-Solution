#include<bits/stdc++.h>
using namespace std;

// O(n^2)
int solve(string s)
{
    int n = s.length();
    string d = "";

    for(int i=s.length()-1; i>=0; i--)
	{
        d += s[i];
	}
    int dp[n+1][n+1];

    for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=n; j++)
		{
            if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(s[i-1] == d[j-1])
				dp[i][j] = 1+ dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	return dp[n][n];
}

int main()
{
    int t;
    cin>>t;

    string s;
    while(t--)
	{
        cin>>s;
        int ans = solve(s);
        cout<<ans<<endl;
	}

	return 0;
}
