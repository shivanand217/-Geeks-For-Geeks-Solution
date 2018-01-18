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

const int mxx = 4005;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/

int price[mxx];
int dp[mxx][mxx];
int wt[mxx];

int main() {
    int W , n;
    scanf("%d %d", &W, &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &wt[i]);
        scanf("%d", &price[i]);
    }

    for(int i=0; i <= n; i++) {
        dp[i][0]=0;
    }

    for(int i=0; i <= W; i++) {
        dp[0][i]=0;
    }

    int greed = 0;

    for(int i=1; i <= n; i++) {
        for(int w=1; w <= W; w++) {
            if(wt[i-1] > w) {
                /** we cannot take current item **/
                dp[i][w] = dp[i-1][w];
            } else {
                dp[i][w] = max(price[i-1]+dp[ i-1 ][ w - wt[i-1] ], dp[i-1][w]);
            }
        }
    }

    printf("%d\n", dp[n][W]);

    return 0;
}
