#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define pb push_back
#define se second
#define fi first

#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define rep(i,n) for(int i=0; i<n; i++)
#define fast std::ios::sync_with_stdio(false)
#define gc() getchar()
#define pc(x) putchar(x)
using namespace std;

const int mxx = 100005;
// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

vector<int> graph[mxx];
vector<int> graphT[mxx];

bool vis[mxx];
int comp[mxx];
int n,m,a,b;

void dfs1(int u, stack<int>& st) {
    vis[u]=true;
    for(int i=0; i<graph[u].size(); i++) {
        int to = graph[u][i];
        if(vis[to] == false){
            dfs1(to, st);
        }
    }
    st.push(u);
}

void dfs2(int u, vector<int>& c) {
    vis[u] = false;
    c.push_back(u);
    for(int i=0; i<graphT[u].size(); i++) {
        int to = graphT[u][i];
        if(vis[to] == true){
            dfs2(to, c);
        }
    }
}

int main() {
    fast;
    cin>>n>>m;

    for(int i=1; i <= n; i++) {
        vis[i] = false;
        comp[i] = 0;
    }

    for(int i=0; i<m; i++) {
        cin>>a>>b;
        graph[a].push_back(b);
        graphT[b].push_back(a);
    }

    stack<int> st;
    for(int i=1; i<=n; i++) {
        if( vis[i] == false )
            dfs1(i , st);
    }

    vector<int> c;
    int component = 0;
    while( !st.empty() ) {
        int u = st.top();
        st.pop();
        c.clear();
        if(vis[u] == true) {
            dfs2(u, c);
        }
        if(c.size() > 1){
            for(auto p : c){
                comp[p]=1;
            }
        }
    }

    for(int i=1; i <= n; i++) {
        cout<<comp[i]<<" ";
    } cout<<endl;

    return 0;
}
