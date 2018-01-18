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

const int mxx = 2002;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/
int dp[2002][2002];
int wt[2002];

int main() {
    int t, n, k;
    scanf("%d", &t);

    for(int p=1; p <= t; p++ ) {
        scanf("%d %d", &n, &k);
        for(int i=0; i<n; i++) {
            scanf("%d", &wt[i]);
        }

        for(int i=0; i<=n; i++) {
            dp[i][0] = 0;
        }
        for(int i=0; i<=k; i++) {
            dp[0][i]=0;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=k; j++) {
                if(wt[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    if(i==1) {
                        dp[i][j] = max(wt[i-1], dp[i-1][j]);
                    } else {
                        dp[i][j] = max( wt[i-1] + dp[ i-2 ][ j- wt[i-1] ], dp[ i-1][ j] );
                    }
                }
            }
        }

        printf("Scenario #%d: %d\n", p, dp[n][k]);
    }

    return 0;
}
