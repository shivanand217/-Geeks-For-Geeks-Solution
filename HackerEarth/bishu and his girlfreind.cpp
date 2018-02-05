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
int dist[1005];
vector<int> graph[1005];
bool vis[1005];
void dfs(int v) {
    vis[v] = true;
    for(int i=0; i < graph[v].size(); i++) {
        int to = graph[v][i];
        if(vis[to] == false){
            dist[to] = dist[v]+1;
            dfs(to);
        }
    }
}
int main() {
    fast;
    int n,u,v,q,p;
    cin>>n;
    memset(vis, false, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    for(int i = 0; i < n-1; i++) {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cin>>q;
    dfs(1);
    int value = -1, idx;
    while(q--) {
        cin>>p;
        if(value == -1) {
            value = dist[p];
            idx=p;
        } else {
            if(value == dist[p]){
                if(idx > p){
                    idx = p;
                }
            } else {
                if( value > dist[p] ){
                    value = dist[p];
                    idx = p;
                }
            }
        }
    }
    cout<<idx<<endl;
    return 0;
}
