#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

bool prime[100007];
int n,m;

int a[1005][1005];
bool ma[1005][1005];
long long int dp[1005][1005];

void sure()
{
	memset(prime, false, sizeof(prime));
    prime[0] = prime[1] = true;

    for(long long int i=2; i*i<=100005; i++)
	{
		if(prime[i] == false)
		{
			for(long long int j=i*i; j<=100005; j+=i)
			{
                prime[j]=true;
			}
		}
	}
}

int q = 0;
pair<int,int> ans[100005];

void dfs(int i, int j, int k)
{
    if(ma[i][j]==1 || i > n || i > m || q || a[i][j] == 0)
		return;

	ma[i][j] = 1;
	ans[k] = {i,j};

    if(i == n && j == m)
	{
		q = k;
		return;
	}
    dfs(i+1, j+1, k+1);
    dfs(i+1, j, k+1);
    dfs(i, j+1, k+1);
}

int main()
{

sure();
scanf("%d%d", &n, &m);

for(int i=1; i<=n; i++)
{
	for(int j=1; j<=m; j++)
	{
        cin>>a[i][j];
        ma[i][j] = false;

        if(prime[a[i][j]] == false)
		{
			a[i][j] = 1;
		}
		else
		{
            a[i][j] = 0;
		}
	}
}

dp[1][1] = 1;

for(int i=1; i<=n; i++)
{
    for(int j=1; j<=m; j++)
	{
		if(i == 1 && j ==1 )
			continue;

        if(prime[a[i][j]] == false)
		{
            dp[i][j] = (dp[i-1][j]%mod + dp[i][j-1]%mod + dp[i-1][j-1]%mod)%mod;
		}

        if(a[i][j] == 0)
			dp[i][j] == 0;
	}
}

cout<<dp[n][m]<<endl;
dfs(1, 1, 1);

for(int i=1; i<=q; i++)
{
    cout<<ans[i].first<<" "<<ans[i].second<<endl;
}

return 0;
}
