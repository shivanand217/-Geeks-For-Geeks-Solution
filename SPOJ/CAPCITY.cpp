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

// special value of infinity to take for getting rid of overflows
const int inf = 0x3f3f3f3f;

/******************* Problem Code *****************/

vector<int> graph[100005];
vector<int> rev[100005];
bool vis[100005];
int ans[100005],comp[100005];
bool has[100005];
int n,m;

void dfs1( int u, stack<int>& st ) {
    vis[u] = true;
    for(int i=0; i < graph[u].size(); i++) {
        int to = graph[u][i];
        if(vis[to] == false){
            dfs1(to, st);
        }
    }
    st.push(u);
}

void dfs2( int u, int co ) {
    vis[u] = false;
    comp[u] = co;
    for(int i=0; i < rev[u].size(); i++){
        int to = rev[u][i];
        if(vis[to] == true) {
            dfs2(to, co);
        }
    }
}

/** top_sort
bool top_sort() {
    memset(vis, false, sizeof(vis));
    queue<int> q;
    for(int i=1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    while( !q.empty() ) {
        int to = q.front();
        q.pop();
        vis[to] = true;
        for(int i=0; i < graph[to].size(); i++) {
            int po=graph[to][i];
            indegree[po]--;
            if(indegree[po] == 0){
                q.push(po);
            }
        }
    }
    for(int i=1; i<=n; i++) {
        if(vis[i] == false) {
        }
    }
} **/

int main() {
    int a , b;
    while(1) {
        cin>>n;
        if( n == 0 )
            break;
        cin>>m;

        for(int i=1; i<=n; i++) {
            graph[i].clear();
            rev[i].clear();
            vis[i]=false;
            has[i]=false;
            comp[i]=0;
        }

        for(int i=0; i < m; i++) {
            cin>>a>>b;
            graph[a].push_back(b);
            rev[b].push_back(a);
        }

        stack<int> st;
        for(int i=1; i <= n; i++) {
            if(vis[i] == false) {
                dfs1(i, st);
            }
        }
        int co = 0;
        while( !st.empty() ) {
            int to = st.top();
            st.pop();
            if( vis[to] == true ) {
                co++;
                dfs2( to, co );
                has[co] = true;
            }
        }
        for(int i=1; i <= n; i++ ){
            for(int j=0; j < graph[i].size(); ++j) {
                if(comp[i] != comp[graph[i][j]]) {
                    has[ comp[i] ] = false;
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            if( has[ comp[i] ] == true ) {
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}
