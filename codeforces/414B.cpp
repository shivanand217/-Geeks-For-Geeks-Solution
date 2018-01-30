#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
#define ss second
#define ff first
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define mx5 100005
#define mx6 1000006
#define mod 1000000007
#define rep(i,n) for(int i=0; i<n; i++)
#define fast std::ios::sync_with_stdio(false)
#define gc() getchar()
#define pc(x) putchar(x)
using namespace std;

// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;
long long dp[2005][2005];

int n, m, i, j, k;
ll ans;

int main() {

	scanf("%d%d", &n, &m);
	for(i=1;i<=n;i++)
		dp[i][1]=1;

	for(j = 2; j <= m; j++)
		for(i = 1; i <= n ; i++)
			for(k = i; k <= n; k += i)
				dp[k][j] = ( dp[k][j] + dp[i][j-1])%mod;
    ans = 0LL;

	for(i=1; i<=n; i++)
		ans = (ans + dp[i][m])%mod;

	printf("%lld\n",ans);

    return 0;
}
