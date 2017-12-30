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

const int mxx = 100005;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

typedef pair<int,int> pii;

int dist[mxx];
bool vis[mxx];
vector< pii > graph[mxx];

int main() {
    int t,n,m,k,x,y,z,tmp;
    //si(t);
    vector<int> special;
    si(n),si(m),si(k);

        special.clear();
        for(int i=0; i<=n; i++) {
            graph[i].clear();
        }

        for(int i=1; i<=k; i++) {
            si(tmp);
            special.pb(tmp);
        }

        for(int i=1; i<=m; i++) {
            si(x),si(y),si(z);
            graph[x].pb(make_pair(z,y));
            graph[y].pb(make_pair(z,x));
        }

        int min_ = INT_MAX;
        priority_queue< pii , vector< pii >, greater< pii > > Q;
        for(int i=0; i < special.size(); i++) {

            for(int j=1; j <= n; j++) {
                dist[j] = inf;
                vis[j] = false;
            }

            int p = special[i];
            dist[p] = 0;
            Q.push(pii(0,p));

            while(!Q.empty()) {
                int u=Q.top().ss;
                Q.pop();
                if(vis[u] == true)
                    continue;
                int sz=graph[u].size();
                for(int l=0; l < sz; l++) {
                    int to = graph[u][l].ss;
                    int w = graph[u][l].ff;
                    if(vis[to] == false && dist[to] > dist[u] + w) {
                        dist[to] = dist[u] + w;
                        Q.push(pii(dist[to], to));
                    }
                }
                vis[u]=true;
            }

            for(int j=0; j < special.size(); j++) {
                if(special[j] != p) {
                    min_ = min(min_, dist[special[j]]);
                }
            }
        }

        cout<<min_<<endl;
    //}

    return 0;
}
