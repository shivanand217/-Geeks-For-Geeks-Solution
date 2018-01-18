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

int n ,m;
int low[35] , disc[35] , par[35] , a[35] , b[35] , c[35];
vector<int> temp[35];
int time_;
bool bridge;
bool vis[35];

void bridges_in_graph(int u) {
    vis[u] = true;
    low[u] = disc[u] = ++time_;
    for(int i = 0; i < temp[u].size(); i++) {
        int to = temp[u][i];
        if( vis[to] == false ) {
            par[to] = u;
            bridges_in_graph(to);
            low[u] = min(low[u], low[to]);
            if( low[to] > disc[u] ) {
                bridge = true;
                return;
            }
        }
        if( vis[to] == true && par[u] != to ) {
            low[u] = min( low[u], disc[to] );
        }
    }
}

long long solve( int mask ) {
    bridge = false;
    for(int i = 0; i < n; i++) {
        temp[i].clear();
        par[i] = -1;
    }

    for(int i=0; i < m; i++) {
        if( ( mask & (1<<i) )) {
            temp[a[i]].push_back(b[i]);
            temp[b[i]].push_back(a[i]);
        }
    }

    memset(vis, false, sizeof(vis));
    time_ = 0;
    bridges_in_graph(0);

    for(int i = 0; i < n; i++) {
        if(vis[i] == false) {
            return (long long)-1;
        }
    }

    if(bridge == true) {
        return (long long)-1;
    }

    long long ans = 0;
    for(int i=0; i < m; i++ ) {
        if( (mask & (1<<i)) ) {
            ans += (long long)c[i];
        }
    }
    return ans;
}

int main() {
    int p = 1;

    while(p) {
        scanf("%d %d", &n, &m);
        if( n == 0 && m == 0 ) {
            break;
        }

        for(int i=0; i < m; i++) {
            scanf("%d %d %d", &a[i], &b[i], &c[i]);
            a[i]--,b[i]--;
        }

        if( m < n-1 ) {
            printf("There is no reliable net possible for test case %d.",p++);
            continue;
        }

        long long ans = 10000000000000000LL;
        int cnt = 0;

        /** for connecting n vertex there is at least n-1
            edges required **/

        /** I am taking all the subsets of n edges **/

        for(int mask = ( 1<<(n-1) ) ;mask < ( 1<<m ); mask++) {
               ll pol = solve(mask);
               if( pol != -1 ) {
                    ans = min(ans, pol);
               }
        }

        if( ans == 10000000000000000LL ) {
            printf("There is no reliable net possible for test case %d.\n", p++);
        } else {
            printf("The minimal cost for test case %d is %lld.\n" , p++ ,ans);
        }
    }

    return 0;
}
