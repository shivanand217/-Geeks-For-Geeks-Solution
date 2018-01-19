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

typedef pair<int,int> pii;

const int mxx = 100001;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/
int dp[7][1001];
vector< pii > G[7];

int solve(int item, int money) {
	if(money < 0)
        return 0;

	if(item > 6)
        return inf;

	if(dp[item][money] != -1)
        return dp[item][money];

	int& ret = dp[item][money];
	ret = 0;

	for(int i = 0; i < G[item].size(); i++)
		if(money >= G[item][i].first)
			ret = max(ret, min(G[item][i].second, solve(item+1, money - G[item][i].first)));

	return ret;
}

int main() {

	int n, t, i, p, q, r;
	scanf("%d%d", &n, &t);
	memset(dp, -1, sizeof dp);

	for(i = 0; i < n; i++) {
		scanf("%d %d %d", &p, &q, &r);
		G[p].push_back(pii(q, r));
	}

	printf("%d\n", solve(1, t));
	return 0;
}
