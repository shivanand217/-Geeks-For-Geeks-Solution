#include<iostream>
#define MOD 1000000007
long long int dp[2002][2002];
using namespace std;
int main()
{
	long long int i,j,k,l,n,sum=0;
	cin>>n>>k;
	for(i=0;i<=n;i++)
		dp[1][i]=1;

    // O(n*k*log(n))

	for(i=2;i<=k;i++)
		for(j=1;j<=n;j++)
			for(l=j;l<=n;l+=j)
				dp[i][l]=(dp[i][l]%MOD+dp[i-1][j]%MOD)%MOD;

	for(i=1;i<=n;i++)
	{
		sum=(sum%MOD+dp[k][i]%MOD)%MOD;
	}
	cout<<sum<<endl;
	return 0;
}
