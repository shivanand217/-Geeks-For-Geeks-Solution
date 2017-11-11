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

vector<pair<int,ll> > graph[mx5];
int dist[mx5];
bool vis[mx5];
int n,x,y;
long long ans,weight;

int bfs(int node) {

    queue<int> q;
    q.push(node);

    memset(dist,0,sizeof(dist));
    memset(vis,0,sizeof(vis));

    while(!q.empty()) {
        int k = q.front();
        q.pop();

        for(int i=0;i<graph[k].size();i++) {
            if(!vis[graph[k][i].ff]){
                vis[graph[k][i].ff] = true;
                dist[graph[k][i].ff] = dist[k]+graph[k][i].ss;
                q.push(graph[k][i].ff);
            }
        }
    }

    int ver;
    ll d = LLONG_MIN;

    for(int i=1;i<=n;i++) {
        if(dist[i]>d) {
            d=dist[i];
            ver = i;
        }
    }

    ans = (ll)dist[ver];
    return ver;
}

int main() {
   int t;
   si(t);

   while(t--) {

		ans = 0LL;
		si(n);
        for(int i=1;i<=n;i++){
            graph[i].clear();
        }

		for(int i=0; i < n-1; i++) {
			si(x), si(y), slli(weight);
            graph[x].pb(make_pair(y,weight));
            graph[y].pb(make_pair(x,weight));
		}

        bfs(bfs(1));
        printf("%lld\n",ans);

   }

   return 0;
}
