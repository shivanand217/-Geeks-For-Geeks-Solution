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

typedef pair < int,int > pii;
const int mxx = 10005;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;
int dist[105];
bool vis[105];
vector< pii > graph[105];

int main() {
    int n,m,s,t,a,b,c;
    si(n),si(s),si(t),si(m);

    for( int i=1; i <= m; i++ ) {
            si(a),si(b),si(c);
            graph[a].pb(pii(c,b));
            graph[b].pb(pii(c,a));
    }

    int cnt = 1;

    for(int i=1; i<=n; i++) {
        if(i != s) {
            memset(dist, inf, sizeof(dist));
            memset(vis, false, sizeof(vis));
            priority_queue< pii, vector< pii >, greater< pii > > Q;
            dist[i]=0;
            Q.push(pii(0,i));
            while( !Q.empty() ) {
                int u = Q.top().ss;
                Q.pop();
                if( vis[u] == true )
                    continue;
                int sz=graph[u].size();
                for(int j=0; j < sz; j++) {
                    int v = graph[u][j].ss;
                    int w = graph[u][j].ff;
                    if( vis[v] == false && dist[v] > dist[u] + w ){
                        dist[v] = dist[u] + w;
                        Q.push(pii(dist[v], v));
                    }
                }
                vis[u]=true;
            }
            if(dist[s] <= t) {
                cnt++;
            }
        }
    }
        printf("%d\n", cnt);

    return 0;
}

