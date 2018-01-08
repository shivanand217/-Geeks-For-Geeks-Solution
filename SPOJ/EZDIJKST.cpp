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
vector< pii > gr[mxx];
bool vis[mxx];
int dist[mxx];
int n,m,a,b,c;
void f(int s) {
    memset(dist,inf,sizeof(dist));
    memset(vis,false,sizeof(vis));
    dist[s]=0;
    priority_queue< pii , vector< pii >, greater< pii > > q;
    q.push(make_pair(dist[s],s));
    pii p;
    int v,w;
    while( !q.empty() ) {
        p = q.top();
        q.pop();
        v = p.ss;
        w = p.ff;
        vis[v] = true;
        if(v==b){
            break;
        }
        for(int i=0; i < gr[v].size(); i++){
            int to=gr[v][i].ff;
            int w1=gr[v][i].ss;
            if(!vis[to] && dist[to]>dist[v]+w1){
                dist[to] = dist[v] + w1;
                q.push(make_pair(dist[to],to));
            }
        }
    }
}
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(int i=1; i<=n; i++){
            gr[i].clear();
        }
        for(int i=0; i<m; i++){
            cin>>a>>b>>c;
            gr[a].pb(make_pair(b,c));
        }
        cin>>a>>b;
        f(a);
        if(dist[b] == inf){
            cout<<"NO"<<endl;
        } else {
            cout<<dist[b]<<endl;
        }
    }
    return 0;
}
