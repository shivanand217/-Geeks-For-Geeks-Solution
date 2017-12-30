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

const int mxx = 10005;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;
typedef pair<int,int> pii;

int dist[mxx];
bool vis[mxx];
vector< pii > graph[mxx];

int main() {
    int t,n,q,p,st,en,oo,tt;
    si(t);

    char city[105];
    map<string, int> m;
    map<string, int> :: iterator it;

    while(t--) {
        si(n);
        for(int i=0; i <= n; i++){
            graph[i].clear();
        }
        m.clear();

        for(int i=1; i <= n; i++) {
            scanf("\n%s", city);
            m.insert(make_pair(city,i));
            si(p);
            for(int j=1; j <= p; j++) {
                scanf("%d %d", &oo, &tt);
                graph[i].pb(make_pair(tt,oo));
            }
        }

        si(q);
        while(q--) {
            priority_queue< pii, vector< pii > , greater< pii > > Q;
            scanf("%s", city);
            it = m.find(city);

            st = (*it).second;
            scanf("%s", city);
            it = m.find(city);

            en = (*it).second;
            for(int i=0; i<=n; i++) {
                vis[i] = false;
                dist[i] = inf;
            }

            dist[st] = 0;
            Q.push(make_pair(0,st));

            while(!Q.empty()) {
                int vv = Q.top().ss;
                int sz = graph[vv].size();
                Q.pop();
                if( vis[vv] == true )
                    continue;
                for(int i=0; i < sz; i++) {
                    int w = graph[vv][i].ff;
                    int q = graph[vv][i].ss;
                    if(vis[q] == false && dist[q] > dist[vv] + w) {
                        dist[q] = dist[vv] + w;
                        Q.push(make_pair(dist[q], q));
                    }
                }
                vis[vv]=true;
                if(vv == en)
                    break;
            }

            printf("%d\n", dist[en]);
        }
    }

    return 0;
}
