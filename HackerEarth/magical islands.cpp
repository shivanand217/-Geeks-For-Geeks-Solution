#include<bits/stdc++.h>
#define pb push_back
#define fast std::ios::sync_with_stdio(false)
#define gc() getchar()
#define pc(x) putchar(x)
using namespace std;

vector<int> graph[100005];
vector<int> graphT[100005];
bool vis[100005];
int ans;

void dfs1(int u, stack<int>& st) {
    vis[u] = true;
    for(int i=0; i < graph[u].size(); i++) {
        int to = graph[u][i];
        if(vis[to] == false) {
            dfs1(to, st);
        }
    }
    st.push(u);
}

void dfs2(int u) {
    vis[u] = false;
    ans++;
    for(int i=0; i<graphT[u].size(); i++){
        int to = graphT[u][i];
        if(vis[to] == true) {
            dfs2(to);
        }
    }
}

int main() {
    fast;
    int n,m,a,b;
    cin>>n>>m;

    for(int i=1; i<=m; i++) {
        cin>>a>>b;
        graph[a].pb(b);
        graphT[b].pb(a);
    }

    for(int i=1; i<=n; i++) {
        vis[i] = false;
    }

    stack<int> st;
    for(int i=1; i<=n; i++) {
        if(vis[i] == false){
            dfs1(i, st);
        }
    }
    int max_=0;

    while( !st.empty() ) {
        int p = st.top();
        st.pop();
        ans=0;
        if(vis[p] == true) {
            dfs2(p);
        }
        if(ans > max_) {
            max_ = ans;
        }

    }
    cout<<max_<<endl;

    return 0;
}
