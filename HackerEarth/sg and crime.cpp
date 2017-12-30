#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

typedef pair<int,int> pii;

vector< pii > graph[100005];
bool vis[100005];
int disc[100005];
int low[100005];
int parent[100005];

int id[50000000];

void bridge( int u) { //bool *vis, int *parent, int *disc, int *low, vector< pii > *graph ) {
    static int time = 0;
    disc[u] = low[u] = ++time;
    vis[u] = true;

    for(int i=0; i < graph[u].size(); i++) {
        int to = graph[u][i].first;

        if(vis[to] == false) {

            parent[to] = u;
            bridge( to);

            /** after finished processing all its decendents **/
            low[u] = min(low[u] , low[to]);

            if(low[to] > disc[u]) {
                int c = graph[u][i].second;
                id[c]++;
            }

        } else if(to != parent[u]) {
            /** update karna hoga kyonki yahan par ye apne ancesstor tak jaa raha hoga **/
            /** lekin yahan par ancesstor ka disc value se matlab hai uske low value se nahin kyonki wo "u" ke subtree mein nahin hai **/
            low[u] = min(low[u] , disc[to]);
        }
    }
}

int main() {
    fast;
    int n, m, x, y, z, q, tmp;
    cin>>n>>m>>q;

    for(int i=1; i <= n; i++) {
        disc[i]=0;
        low[i]=0;
        parent[i]=-1;
        vis[i] = false;
    }

    memset(id, 0, sizeof(id));

    for(int i=1; i <= m; i++) {
        cin>>x>>y>>z;
        graph[x].push_back(make_pair(y,z));
        graph[y].push_back(make_pair(x,z));
    }

    for(int i=1; i<=n; i++) {
        if(vis[i] == false) {
            bridge(i);
        }
    }

    while(q--) {
        cin>>tmp;
        if( tmp >= 1 && tmp <= m && id[tmp] > 0) {
            cout<<"YES"<<endl;
        } else {
            cout<<"no"<<endl;
        }
    }

    return 0;
}
