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

int fee[1002] , fun[1002];
int dp[1002][1002] , money[1002][1002];

int main() {
    int n , W;
    while(1) {
        scanf("%d %d", &W, &n);
        if(n == 0 && W == 0) {
            break;
        }
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &fee[i], &fun[i]);
        }

        for(int i=0; i <= n; i++) {
            dp[i][0] = 0;
            money[i][0] = 0;
        }

        for(int i=0; i <= W; i++) {
            dp[0][i] = 0;
            money[0][i] = 0;
        }

        for(int i = 1; i <= n; i++) {
            for(int w = 1; w <= W; w++) {
                if( fee[i-1] > w ) {
                    dp[i][w] = dp[i-1][w];
                    money[i][w] = money[i-1][w];

                } else {

                    /** if picking up current will fetch us more fun without exceeding the budget then go for it **/
                    if( fun[ i -1 ] + dp[ i-1][w - fee[i-1]] > dp[ i-1 ][ w] ) {
                        dp[ i][ w] = fun[ i-1 ] + dp[ i-1][ w - fee[i-1]];
                        money[ i][ w] = fee[ i-1 ] + money[ i-1][ w -fee[i-1] ];
                    } else {

                        dp[ i][ w] = dp[ i-1][ w];
                        money[ i][ w] = money[ i-1][ w];
                    }

                }
            }
        }

        int m = dp[ n][ W];
        int min_ = INT_MAX;

        /** now checking for if this much profit has been obtained earlier with low budget then we pick that budget
            means we have to minimize our budget with gaining maximum profit
        **/

        for(int i=1; i <= W; i++) {
            if(dp[ n][ i] == m ){
                if(money[ n][ i] < min_) {
                    min_ = money[ n][ i];
                }
            }
        }

        printf("%d %d\n", min_, dp[ n][ W] );
    }

    return 0;
}
