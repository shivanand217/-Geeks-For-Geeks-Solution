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

int disc[100005], low[100005], vis[100005];
int ans = 0;
int timer = 0;
vector<int> graph[100005];
int p;

int bridge(int vert, int par, int cnt) {
    disc[vert] = low[vert] = ++timer;
    vis[vert] = true;
    int child = 1;
    for(int i = 0; i < graph[vert].size(); i++) {
        int to = graph[vert][i];
        if(to != par) {
            if(vis[to] == false) {
                int _size = bridge(to, vert, cnt);
                child += _size;
                low[vert] = min( low[vert], low[to] );
                if(low[to] > disc[vert] && abs(cnt - 2 * _size) < p ) {
                    ans++;
                }
            } else {
                /** if this is ancesstor of this node **/
                low[vert] = min( low[vert], disc[to] );
            }
        }
    }
    return child;
}

int main() {
    int n,m,u,v;
    memset(vis, false, sizeof(vis));
    memset(disc, 0, sizeof(disc));
    memset(low, 0, sizeof(low));
    cin>>n>>m>>p;

    for(int i=0; i < m; i++) {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    /** for every connected component **/
    for(int i = 1; i <= n; i++) {
        if(vis[i] == false) {
            queue<int> q;
            q.push(i);
            int cnt = 1;
            vis[i] = true;
            while( !q.empty() ) {
                int top = q.front();
                q.pop();
                for(int j=0; j < graph[top].size(); j++){
                    int to = graph[top][j];
                    if(vis[to] == false){
                        cnt++;
                        vis[to] = true;
                        q.push(to);
                    }
                }
            }
            memset(vis, false, sizeof(vis));
            bridge(i, -1, cnt);
        }
    }

    cout<<ans<<endl;

    return 0;
}
