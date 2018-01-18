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

int dp[60][2000];

int egg_drop(int egg, int floor) {
    memset(dp, 0, sizeof(dp));

    /** for 1 floor 1 trial for 0 floor 0 trial **/
    for( int i=1; i <= egg; i++ ) {
        dp[i][1]= 1;
        dp[i][0]= 0;
    }

    /** if their is only one egg it require j trials **/
    for( int j=1; j <= floor; j++ ) {
        dp[1][j] = j;
    }

    int res;

    for(int i = 2; i <= egg; i++) {
        for(int j=2; j <= floor; j++) {
            dp[i][j] = INT_MAX;

            for(int k = 1; k <= j; k++ ) {
                /** here two possibilities if the egg breaks on dropping from ith floor
                    then we check for (egg-1) eggs with floor less than current floor
                    If the egg does not break then we have to check for (egg) eggs  and the remaining above floor
                    we have to take max of both because we have to take worst case scenario **/
                res = 1 + max( dp[ i-1][ k-1] , dp[ i][ j- k] );

                if(dp[i][j] > res) {
                    dp[ i][ j] = res;
                }
            }
        }
    }

    return dp[ egg][ floor];
}

int main() {
    int t, mm, egg, floor;
    scanf("%d", &t);

    for( int p = 1; p <= t; p++ ) {
        scanf("%d %d %d", &mm, &egg, &floor);

        int ans = egg_drop(egg, floor);

        printf("%d %d\n", mm, ans);
    }

    return 0;
}
