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

const int mxx = 10010;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;
long long arr[mxx];
long long MEMO[mxx];

int main() {

    int t;

    scanf("%d", &t);

    int n;

    for(int i=1; i <= t; i++) {

        memset(MEMO, 0, sizeof(MEMO));
        scanf("%d", &n);

        for(int j=0; j < n; j++) {
            scanf("%lld",&arr[j]);
        }

        if(n == 0) {
            printf("Case %d: 0\n",i);
            continue;
        }
        if(n == 1) {
            printf( "Case %d: %lld\n", i, arr[0] );
            continue;
        } else if(n == 2) {
            printf( "Case %d: %lld\n", i, max(arr[0], arr[1]) );
            continue;
        }

        MEMO[0] = arr[0];
        MEMO[1] = max(arr[0] , arr[1]);

        for(int j=2; j < n; j++) {
            MEMO[j] = max(MEMO[j-2] + arr[j] , MEMO[j-1]);
        }

        printf("Case %d: %lld\n", i, MEMO[n-1]);
    }

    return 0;
}
