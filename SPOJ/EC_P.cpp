#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define pb push_back
#define si(x) scanf("%d",&x)
#define slli(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define sp() putchar(' ')
#define nl() putchar('\n')
#define fck std::ios::sync_with_stdio(false);
#define mx5 100010
#define mx6 1000010
#define MOD 1000000007
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;

const int mx = 707;
int parent[mx];
int low[mx];
int disc[mx];
bool vis[mx];

vector<int> graph[mx];
int n,m,x,y,_time;
vector<pair<int,int> > ans;

bool compp(pair<int,int> p1,pair<int,int> p2) {
    return (p1.ss < p2.ss);
}

void solve(int u) {
    vis[u]=true;
    disc[u] = low[u] = ++_time;
    for(int i=0; i<graph[u].size(); i++){
        int v = graph[u][i];
        if(!vis[v]) {
            parent[v]=u;
            solve(v);
            low[u]=min(low[u],low[v]);
            if(low[v] > disc[u]) {
                if(v<=u)
					ans.pb({v,u});
				else
					ans.pb({u,v});
            }
        } else if(v != parent[u]) {
            low[u] = min(low[u],disc[v]);
        }
    }
}

void bridge() {
    for(int i=1;i<=n;i++){
        parent[i]=-1;
        vis[i]=false;
    }
    for(int i=1;i<=n;i++){
		if(!vis[i]){
			solve(i);
		}
    }
}

int main() {

	fck;
	int t;
	cin>>t;

    for(int test=1;test<=t;test++) {
		ans.clear();
        _time=0;
		cout<<endl;

        cin>>n>>m;
        for(int i=1;i<=n;i++) {
            graph[i].clear();
        }

        for(int i=0;i<m;i++){
			cin>>x>>y;
            graph[x].pb(y);
            graph[y].pb(x);
        }

        bridge();
        cout<<"Caso #"<<test<<endl;

        if(ans.size()==0) {
            cout<<"Sin bloqueos"<<endl;
            continue;
        }

        cout<<ans.size()<<endl;
        sort(ans.begin(),ans.end());

        for(int i=0;i<ans.size();i++) {
              cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
        }
    }

   return 0;
}
