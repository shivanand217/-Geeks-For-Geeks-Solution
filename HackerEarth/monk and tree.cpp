#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
const int mx = 2e5 + 10;

typedef pair<int,int> pii;
typedef pair<int,int> pii2;

vector<int> graph[mx];
int par[mx];
int rnk[mx];
bool vis[mx];

void init(int n) {
    for(int i=1; i <= n; i++) {
        graph[i].clear();
        par[i]=i;
        rnk[i]=1;
        vis[i]=false;
    }
}
int root(int x) {
    while(x != par[x]){
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}
void union_(int x, int y) {
    if(rnk[x] > rnk[y]) {
        rnk[y] += rnk[x];
        par[x] = y;
    } else {
        rnk[x] += rnk[y];
        par[y] = x;
    }
}

bool cmp(pair<int,pii> x, pair<int,pii> y) {
    return (x.ff > y.ff);
}

void dfs(int k) {
    vis[k] = true;
    for(int i=0; i < graph[k].size(); i++) {
        int to=graph[k][i];
        if(vis[to] == false) {
            dfs(to);
        }
    }
}

int main() {
    int t,x,y,n,m;
    cin>>t;
    vector< pair<int,pii> > edge;
    int w;
    while(t--) {
        edge.clear();
        cin>>n>>m;
        init(n);
        for(int i=0; i < m; i++) {
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
            edge.push_back(make_pair(abs(x-y) , make_pair(x,y)));
        }
        sort(edge.begin(), edge.end(), cmp);
        long long cost = 0;
        int cnt = 0;
        for(int i=0; i<edge.size(); i++) {
            w = edge[i].ff;
            x = edge[i].ss.ff;
            y = edge[i].ss.ss;
            int p = root(x);
            int q = root(y);

            if(p != q) {
                union_(p, q);
            } else {
                cost += w;
            }
        }
        memset(vis, false, sizeof(vis));
        for(int i = 1; i<=n; i++) {
            if(vis[i] == false) {
                cnt++;
                dfs(i);
            }
        }

        cost += (cnt-1);
        cout<<cost<<endl;
    }

    return 0;
}
