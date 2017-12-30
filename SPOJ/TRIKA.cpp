#include<bits/stdc++.h>
#define mp make_pair
#define ll long long
#define pb push_back
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

int main() {
	int n, m, r, c, MEMO[32][32], i, j;
	scanf("%d%d%d%d", &n, &m, &r, &c);

	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			scanf("%d", &MEMO[i][j]);

	for(i = r + 2; i <= n; i++)
        MEMO[i][c] = MEMO[i-1][c] + MEMO[i][c];

	for(j = c + 2; j <= m; j++)
        MEMO[r][j] = MEMO[r][j-1] + MEMO[r][j];

	for(i = r + 1; i <= n; i++)
		for(j = c + 1; j <= m; j++)
			MEMO[i][j] = MEMO[i][j] + min(MEMO[i-1][j], MEMO[i][j-1]);

    if( MEMO[r][c] - MEMO[n][m] >= 0 )
        printf("Y %d\n", MEMO[r][c] - MEMO[n][m]);
	else
        printf("N\n");

	return 0;
}
