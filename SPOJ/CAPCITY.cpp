#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define max3(a,b,c) max(a, max(b,c))
#define max4(a,b,c,d) max(a, max(b, max(c,d)))
#define pb push_back
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define sp() putchar(' ')
#define nl() putchar('\n')
#define mx5 100010
#define mx6 1000010
#define MOD 1000000007
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

stack<int> st;
vector<int> graph[mxx];
vector<int> rev_graph[mxx];
bool vis[mxx];

void dfs1(int u) {
    vis[u]=true;
    for(int i=0;i<graph[u].size();i++) {
        if(!vis[graph[u][i]]) {
            dfs1(graph[u][i]);
        }
    }
    st.push(graph[u][i]);
}

void dfs2(int u,int k) {
    vis[u]=true;
    C[u]=k;
    for(int i=0;i<rev_graph[u].size();i++){
        if(!vis[rev_graph[u][i]]){
            dfs2(rev_graph[u][i],k);
        }
    }
}

int main() {
    si(n), si(m);
    for(int i=1; i<=n; i++){
        vis[i]=false;
        graph[i].clear();
        rev_graph[i].clear();
        in[i]=0;
    }

    for(int i=1;i<=m;i++){
        si(u), su(v);
        graph[u].pb(v);
        rev_graph[v].pb(u);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs1(i);
        }
    }

    for(int i=1;i<=n;i++){
        vis[i]=false;
    }

    int component=0;

    while(!st.empty()) {
        int k = st.top();
        st.pop();
        if(vis[k]==false) {
            ++component;
			dfs2(k,component);
        }
    }

    int _size=component;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<graph[i].size();j++) {
            if(C[i] != C[graph[i][j]]) {
                in[C[graph[i][j]]] += 1;
            }
        }
    }

    int cnt=0;
    for(int i=0;i<_size;i++) {
        if(in[i] == 0){
            ++cnt;
        }
    }

    if(cnt > 1){
        printf("0\n");
    } else {
        cnt=0;
        for(int i=1;i<=n;i++){
            if(in[C[i]]==0) {
                cnt++;
            }
        }
		printf("%d\n", cnt);
        for ( i = 1; i <= n; ++i ) {
            if ( in[ C[ i ] ] == 0 ) {
                printf("%d ", i);
            }
        }
			putchar('\n');
    }

    return 0;
}
