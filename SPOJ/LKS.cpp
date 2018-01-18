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

/** space optimized knapsack O(W) space only **/

long long dp[3000006];
long long val[1005] ,wt[1005];

int main() {
    int k, n, W;
    scanf("%d %d", &k, &n);

    for(int i=0; i<n; i++) {
        scanf("%lld %lld", &val[i], &wt[i]);
    }

    memset(dp, 0, sizeof(dp));
    for(int i=0; i < n; i++) {
        for(int j=k; j >= wt[i]; j--) {
            dp[ j] = max( dp[ j], val[i] + dp[ j - wt[i]]);
        }
    }

    printf("%lld\n", dp[k]);
    return 0;
}
